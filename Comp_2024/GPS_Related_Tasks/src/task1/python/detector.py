#!/usr/bin/env python3

import sys
import numpy as np

import argparse #16OCT argument parsing
import torch #16OCT provides tools for machine learning
import cv2 #16OCT computer vision 2; used for image processing, vision, and machine learning tasks
import pyzed.sl as sl #16OCT python wrapper for ZED from C++ to python; provides functions and class for object detection
import torch.backends.cudnn as cudnn #16OCT provides access to CUDA deep neural network

sys.path.insert(0, './yolov5') #16OCT look into ./yolov5 directory when trying to import local modules
from models.experimental import attempt_load #16OCT used to load pretrained model
from utils.general import check_img_size, non_max_suppression, scale_coords, xyxy2xywh 
from utils.torch_utils import select_device #16OCT choose appropriate device CPU or GPU
from utils.augmentations import letterbox #16OCT used for resizing and padding images

from threading import Lock, Thread
from time import sleep

import ogl_viewer.viewer as gl #16OCT used for ogenGL-based visualization capabilities
import cv_viewer.tracking_viewer as cv_viewer #16OCT functionality for visualizing tracked objects in computer vision; handle display of real-time tracking information from ZED
import MainControl as mc 

import rclpy #16OCT python client library for ros2
from vectornav_msgs.msg import GpsGroup #16OCT to retrieve raw GPS data and other sensor info and provide messages specific to interacting with VectorNav
from sensor_msgs.msg import NavSatFix #16OCT to provide GPS data from any GPS reciever

import signal

# global variable to store GPS data
latitude = None
longitude = None
subscription = None
node = None
ros2_initialized = False
lock = Lock()
run_signal = False
exit_signal = False

#Trying to help with the exiting issues #15OCT activates when user sends SIGINT signal Ctrl+C
def signal_handler(sig, frame):
    global exit_signal, capture_thread, node

    print("Received SIGINT (Ctrl+C). Shutting down...")
    exit_signal = True     

    if capture_thread.is_alive():
        capture_thread.join()

    if node is not None:
        print("Destroying Node...")
        node.destroy_node()

    print("ROS2 Node Exterminated")
    sys.exit(0)

#15OCT preprocesses input images to prepare them Yolov5
def img_preprocess(img, device, half, net_size): #17OCT input image (numpy array), device, boolean to convert to half precision or fullm target size for neural network input
    net_image, ratio, pad = letterbox(img[:, :, :3], net_size, auto=False) #18OCT resize image while maintaining aspect ratio
    net_image = net_image.transpose((2, 0, 1))[::-1]  # transposes dimensions of net_image from HWC to CHW for PyTorch, -1 means BGR to RGB
    net_image = np.ascontiguousarray(net_image) #18OCT store image in connected block of memory

    img = torch.from_numpy(net_image).to(device) #15OCT converts image into pytorch tensor and transfers it to a device (CPU/GPU)
    img = img.half() if half else img.float()  # 16OCT conversion to fp16 or 32
    img /= 255.0  # 0 - 255 to 0.0 - 1.0 #18OCT normalizes pixel values from 0-255 to 0-1 for neural network input

    if img.ndimension() == 3: #18OCT if there are 3 dimensions (CHW)
        img = img.unsqueeze(0) #18OCT add (Batch CHW or BCHW)
    return img, ratio, pad #15OCT returns preprocessed image tensor for image processes, ratio of original size to resize, and amount of padding applied)


# Bounding Box (outline of where the object is) Conversion: 
# 15OCT converts bounding box coordinates from the format of center coordinates (x,y) 
# and height/width from YoloV5 into the corner coordinates 
# (a bottomleft b bottomright c toprigght d topleft) needed by the ZED SDK for object detection
def xywh2abcd(xywh, im_shape):
    output = np.zeros((4, 2)) #18OCT initializes a matrix of zeros

    # Center / Width / Height -> BBox corners coordinates
    x_min = (xywh[0] - 0.5*xywh[2]) * im_shape[1]   #15OCT calculates coordinates of the bounding box
    x_max = (xywh[0] + 0.5*xywh[2]) * im_shape[1]
    y_min = (xywh[1] - 0.5*xywh[3]) * im_shape[0]
    y_max = (xywh[1] + 0.5*xywh[3]) * im_shape[0]
    
    # Printing out x max and min values of object
    #print("x max: " + str(x_max))
    #print("x min: " + str(x_min))

    # A ------ B
    # | Object |
    # D ------ C

    output[0][0] = x_min   #15OCT D
    output[0][1] = y_min

    output[1][0] = x_max #15OCT C
    output[1][1] = y_min

    output[2][0] = x_min #15OCT A
    output[2][1] = y_max

    output[3][0] = x_max #15OCT B
    output[3][1] = y_max
    return output

#15OCT Converts Yolov5s detected objects into ZED's customboxobjectdata format. This includes
#labels, bounding boxes, and confidence 
def detections_to_custom_box(detections, im, im0): #18OCT im0 is needed to scale bounding boxes back to original res
    output = []
    for i, det in enumerate(detections): #15OCT iterate over detections list where i is in index and det is the actual detection at that index
        if len(det): #17OCT if a detection contains objects
            det[:, :4] = scale_coords(im.shape[2:], det[:, :4], im0.shape).round() #18OCT rescale bounding box coordinates from YoloV5 to dimensions of original image; 
            #im.shape extracts height and width of image YoloV5, det[:,:4] is bounding box cords 
            # x1,y1,x2,y2) in Yolov5 format, and im0 is original dimensions)  
            gn = torch.tensor(im0.shape)[[1, 0, 1, 0]]  # 18OCT creates normalization factor for normalizing the bounding box

            for *xyxy, conf, cls in reversed(det):   #15OCT iterates over detection results in reverse order (i.e oldest detections in que first)  
                #15OCT converts coordinates to xywh format; normalized by gn
                xywh = (xyxy2xywh(torch.tensor(xyxy).view(1, 4)) / gn).view(-1).tolist() #15OCT converts from xyxy2xywh and reshapes for processing

                # Creating ingestable objects for the ZED SDK
                obj = sl.CustomBoxObjectData() #16OCT creates instance of customboxobjectdata class from ZED
                obj.bounding_box_2d = xywh2abcd(xywh, im0.shape) #15OCT im0.shape provides dimensions of original image
                obj.label = cls
                obj.probability = conf
                obj.is_grounded = False
                output.append(obj)
    return output

#15OCT runs object detetion in a seperate thread using YoloV5. This calls YoloV5
def torch_thread(weights, img_size, conf_thres=0.2, iou_thres=0.45):  
    global image_net, exit_signal, run_signal, detections

    print("Intializing Network...")

    device = select_device()
    half = device.type != 'cpu'  # half precision only supported on CUDA
    imgsz = img_size

    # Load model
    model = attempt_load(weights, device=device) #15OCT attempts to load the model
    # load FP32
    stride = int(model.stride.max())  # model stride #15OCT determines max stride of model, which is used for adjusting input sizes      
    imgsz = check_img_size(imgsz, s=stride)  # VERUFY img_size for compatability to stride
    if half:
        model.half()  # to FP16
    cudnn.benchmark = True

    # Run inference
    if device.type != 'cpu':
        model(torch.zeros(1, 3, imgsz, imgsz).to(device).type_as(next(model.parameters())))  # run once as a test for object detection

    while not exit_signal: #while ctrl+c is not 1
        if run_signal:  #15OCT i.e an object should be processed for detection as defined in main
            lock.acquire()
            img, ratio, pad = img_preprocess(image_net, device, half, imgsz) #15OCT prepares input images for detection using earlier function

            pred = model(img)[0]   #15OCT runs model on input image
            det = non_max_suppression(pred, conf_thres, iou_thres) #15OCT filter out overlapping bounding boxes

            # ZED CustomBox format (with inverse letterboxing tf applied)
            detections = detections_to_custom_box(det, img, image_net) 
            lock.release()
            run_signal = False
        sleep(0.01)

def initialize_ros2():  #15OCT initialize ros2, sets up a node, suscribes to a gps topic to get lat/long 
    global subscription, node #initalizing variables wo/ values is not best practice
    global latitude, longitude, ros2_initialized

    if not ros2_initialized and latitude is None:
        print("Creating ROS2 GPS Subscriber...")
        try: #25OCT you don't want try except in production code because if anything in try fails 
            rclpy.init() #Initializes ROS client library
            node = rclpy.create_node('task1_start')
            subscription = node.create_subscription(NavSatFix, 'vectornav/gnss', lambda msg: callback(msg, node), 10) #(message type to listen for (usually GPS data), name of topic to suscribe, sets up callpack function(from msg, our node) to use when new information is published, every 10 hz)
            ros2_initialized = True                                               #lambda function has no name, ROS2 sends new GPS info to msg, it passes msg to the callback function
            print("ROS2 Initialized")
            rclpy.spin_once(node, timeout_sec=0.1) #25OCT This function processes any pending callbacks or events that may have occured during initilization phase or might have been published to vectornav before subscription was fully established for the given node for 0.1 seconds then moves on, rather than continuously and stuck in loop (as with rclpy.spin).
        except Exception as e:
            print(f"Failed to initialize ROS2: {e}")


	
def callback(msg, node):   #15OCT gets GPS and unsuscribes after getting first message
    global latitude, longitude, subscription
    if latitude is None:  #if no previous lat has been recieved then grab the information
        # Grab the first set of information
        latitude = msg.latitude
        longitude = msg.longitude
        print(f"Received latitude information: {latitude}")
        print(f"Received longitude information: {longitude}")

        # Unsubscribe after receiving the first message
        if subscription is not None:
            node.get_logger().info('Unsubscribing from the topic...')
            subscription.destroy()
            subscription = None  # Reset subscription after destroying
    if longitude is None:
        print("Failed to grab longitude information.")
    if latitude is None:
        print("Failed to grab latitude information")

def cleanup_ros2(): #15OCT ROS2 shutdown by destroying the node, unsubscribing from the GPS topic, and shutting down ROS2 properly.
    global subscription, node

    if node is not None:
        print("Destroying Node...")
        try:
            node.destroy_node()
        except Exception as e:
            print(f"Failed to destroy ROS2 node: {e}")

    if subscription is not None:
        print("Unsubscribing from the topic...")
        try:
            if hasattr(subscription, 'handle') and subscription.handle.is_valid():
                subscription.destroy()
                subscription = None
        except Exception as e:
            print(f"Failed to unsubscribe from the topic: {e}")

    print("Shutting down ROS2...")
    try:
        rclpy.shutdown()
    except Exception as e:
        print(f"Failed to shutdown ROS2: {e}")



def main():
    # Define thruster object for thruster control

    global image_net, exit_signal, run_signal, detections, subscription, latitude, ros2_initialized

    #15OCT initialize a thread for image processing with parameters and start it immediately
    capture_thread = Thread(target=torch_thread,
                            kwargs={'weights': opt.weights, 'img_size': opt.img_size, "conf_thres": opt.conf_thres})
    capture_thread.start()

    initialize_ros2()
    cleanup_ros2()
    

    zed = sl.Camera() #creates instance of camera class from ZED SDK; access to cameras functions and data

    input_type = sl.InputType() #creates an instance of the InputType class from ZED SDK
    if opt.svo is not None: #if an .svo file is provided through opt.svo, it sets it as the input source
        input_type.set_from_svo_file(opt.svo) #otherwise its the camera feed

    # 15OCT Create a InitParameters object and set configuration parameters for the ZED
    init_params = sl.InitParameters(input_t=input_type, svo_real_time_mode=True) #
    init_params.camera_resolution = sl.RESOLUTION.HD720
    init_params.coordinate_units = sl.UNIT.METER
    init_params.depth_mode = sl.DEPTH_MODE.ULTRA  # QUALITY
    init_params.coordinate_system = sl.COORDINATE_SYSTEM.RIGHT_HANDED_Y_UP
    init_params.depth_maximum_distance = 50

    #15OCT runtime_params is initialized for managing the camera during the main loop
    runtime_params = sl.RuntimeParameters() 
    status = zed.open(init_params)

    if status != sl.ERROR_CODE.SUCCESS:
        print(repr(status))
        exit() #Exit if the camera does not open successfully

    image_left_tmp = sl.Mat()

    print("Initialized Camera")

    #15OCT Positional Tracking is initialized which allows for tracking the camera's movement; note the camera tracks its own movement
    positional_tracking_parameters = sl.PositionalTrackingParameters()
    # If the camera is static, uncomment the following line to have better performances and boxes sticked to the ground.
    # positional_tracking_parameters.set_as_static = True
    zed.enable_positional_tracking(positional_tracking_parameters)

    #15OCT Object Detection on the Zed using a custom model and enabling tracking of detected objects
    obj_param = sl.ObjectDetectionParameters()
    obj_param.detection_model = sl.DETECTION_MODEL.CUSTOM_BOX_OBJECTS #15OCT using custom trained box objects 
    obj_param.enable_tracking = True # 15OCT Enable tracking of detected objects
    zed.enable_object_detection(obj_param)

    #15OCT initialize empty to hold info about detected objects and camera information is retrieved
    objects = sl.Objects()
    obj_runtime_param = sl.ObjectDetectionRuntimeParameters()
    camera_infos = zed.get_camera_information()

    # Create OpenGL viewer
    #viewer = gl.GLViewer() # ** Comment this line out to disable visual display **
   
    # 15OCT point cloud is a collection of 3D points that captured objects by the ZED camera 
    # It is stored in point_cloud and the resolution is captured by point_cloud_res
    point_cloud_res = sl.Resolution(min(camera_infos.camera_resolution.width, 720),
                                    min(camera_infos.camera_resolution.height, 404)) 
                                    
    point_cloud_render = sl.Mat()
    viewer.init(camera_infos.camera_model, point_cloud_res, obj_param.enable_tracking) # ** Comment this line out to disable visual display **

    point_cloud = sl.Mat(point_cloud_res.width, point_cloud_res.height, sl.MAT_TYPE.F32_C4, sl.MEM.CPU)
    #now ready to store coordinates

    #15OCT creates object for image captured from the left side camera
    image_left = sl.Mat() 
    
    # Utilities for 2D display; 15OCT handle resizing for display
    display_resolution = sl.Resolution(min(camera_infos.camera_resolution.width, 1280),
                                       min(camera_infos.camera_resolution.height, 720))
    image_scale = [display_resolution.width / camera_infos.camera_resolution.width, display_resolution.height / camera_infos.camera_resolution.height]
    image_left_ocv = np.full((display_resolution.height, display_resolution.width, 4), [245, 239, 239, 255], np.uint8)

    # Utilities for tracks view; 15OCT creates a tracking viewer to visualize the tracking data
    camera_config = zed.get_camera_information().camera_configuration
    tracks_resolution = sl.Resolution(400, display_resolution.height)
    track_view_generator = cv_viewer.TrackingViewer(tracks_resolution, camera_config.camera_fps,
                                                    init_params.depth_maximum_distance)
    track_view_generator.set_camera_calibration(camera_config.calibration_parameters)
    image_track_ocv = np.zeros((tracks_resolution.height, tracks_resolution.width, 4), np.uint8)
    # Camera pose
    cam_w_pose = sl.Pose() #15OCT stores camera's world position

    #while viewer.is_available() and not exit_signal: # ** Comment this line out to disable visual display **
    while True: # <- ** Comment this out if above line is uncommented **
        if zed.grab(runtime_params) == sl.ERROR_CODE.SUCCESS: #15OCT if a new image is available within the loop
            # -- Get the image 
            lock.acquire()
            zed.retrieve_image(image_left_tmp, sl.VIEW.LEFT)     #get image from sl.VIEW.LEFT and store it in image_left_tmp
            image_net = image_left_tmp.get_data() #17OCT stored image data like actual pixed data
            lock.release()
            run_signal = True #HOLY SHIT:  THIS TRIGGERS THE CREATED TORCH_THREAD IN MAIN TO RUN !!!!!!!!!!!!!!!!!!!!!

           
            while run_signal:  #18OCT maybe just remove
                sleep(0.001) #18OCT maybe a little fast, tone it down

            # Wait for detections
            lock.acquire()
            # -- 
            #im mad confused about this section
            zed.ingest_custom_box_objects(detections) #integrate detections into cameras object tracking system
            lock.release()
            zed.retrieve_objects(objects, obj_runtime_param) #15OCT retrieve and update detected object information and detected by ZED in objects

            # -- Display
            # Retrieve display data
            zed.retrieve_measure(point_cloud, sl.MEASURE.XYZRGBA, sl.MEM.CPU, point_cloud_res) #15OCT retrieves point cloud data from ZED camera
            point_cloud.copy_to(point_cloud_render) #15OCT copies point cloud data for display or rending
            zed.retrieve_image(image_left, sl.VIEW.LEFT, sl.MEM.CPU, display_resolution) #15OCT retrieves left image from ZED in specified resolution
            zed.get_position(cam_w_pose, sl.REFERENCE_FRAME.WORLD) #15OCT retrieves position and orientation of camera

            # 3D rendering
            #viewer.updateData(point_cloud_render, objects) # ** Comment this line out to disable visual display **
            # 2D rendering
            np.copyto(image_left_ocv, image_left.get_data()) #15OCT copies the left camera image data (numpy array) into image_left_ovc array for OpenCV processing
            #cv_viewer.render_2D(image_left_ocv, image_scale, objects, obj_param.enable_tracking) # ** Comment this line out to disable visual display **
            global_image = cv2.hconcat([image_left_ocv, image_track_ocv]) #15OCT combines 2D camera image with tracking view for display
            # Tracking view (the 2D birds eye view seems like the best bet for making this simple)
            track_view_generator.generate_view(objects, cam_w_pose, image_track_ocv, objects.is_tracked) #15OCT generates 2D tracking view of detected object
            
            # 15OCT Send Zed aquired objects to MainControl.py script
            mc.set_objects(objects)      

            #cv2.imshow("ZED | 2D View and Birds View", global_image) # ** Comment this line out to disable visual display **
            key = cv2.waitKey(10)
            if key == 27: #17OCT escape key is pressed
                exit_signal = True
        else:
            exit_signal = True

    
    #viewer.exit()
    exit_signal = True
    capture_thread.join() 
    zed.close()


#15OCT HOW TO ALLOW ARGUMENTS TO BE PASSED TO THISFUNCTION
if __name__ == '__main__':
    exit_signal = False  # Initialize exit_signal here
    try:
        parser = argparse.ArgumentParser()
        parser.add_argument('--weights', nargs='+', type=str, default='exp13best.pt', help='model.pt path(s)')
        parser.add_argument('--svo', type=str, default=None, help='optional svo file')
        parser.add_argument('--img_size', type=int, default=512, help='inference size (pixels)')
        parser.add_argument('--conf_thres', type=float, default=0.1, help='object confidence threshold')
        opt = parser.parse_args()
        with torch.no_grad():
            main()
    except KeyboardInterrupt:
        # Handle Ctrl+C (KeyboardInterrupt)
        signal_handler(signal.SIGINT, None)
        # Set exit_signal to True
        exit_signal = True
    finally:
        # Print "Exiting script..." only if Ctrl+C is used
        if exit_signal is True:
            print("Exiting script...")

#Summary of Key Components
#ZED Camera: Captures depth and RGB images and enables object detection and tracking.
#YOLOv5: Performs object detection on the images captured by the ZED camera, providing bounding boxes and confidence scores.

#Data Flow:
#Capture: ZED captures images and depth data.
#Detection: YOLOv5 processes the images for object detection.
#Integration: Detected objects are formatted and ingested into the ZED SDK for tracking.
#Visualization: Both 2D and 3D representations of the scene, including detected objects, are rendered for user observation.