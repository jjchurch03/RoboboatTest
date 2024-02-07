import sys
import numpy as np

import argparse
import torch
import cv2
import pyzed.sl as sl
import torch.backends.cudnn as cudnn

sys.path.insert(0, './yolov5')
from models.experimental import attempt_load
from utils.general import check_img_size, non_max_suppression, scale_coords, xyxy2xywh
from utils.torch_utils import select_device
from utils.augmentations import letterbox

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

lock = Lock()
run_signal = False
exit_signal = False

class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.min_distance_threshold = 0.5
        self.front_obstacle_threshold = 0.5
        self.num_readings = 0

    def scan_callback(self, msg):
        distances = msg.ranges
        min_distance = min(distances)
        self.num_readings = len(distances)

        if min_distance < self.min_distance_threshold:
            print("Obstacle Detected! Deciding best course of action...")
            self.avoid_obstacle(distances, msg)
        else:
            print("Moving Forward...")
            self.move_forward()

    def avoid_obstacle(self, distances, msg):
        closest_index = distances.index(min(distances))
        num_readings = len(distances)
        angle_increment = msg.angle_increment

        print(f"Calculating Angle... Angle Increment: {angle_increment}")

        angle_to_obstacle = closest_index * angle_increment
        print(f"Angle to Obstacle: {angle_to_obstacle}")

        if angle_to_obstacle < self.front_obstacle_threshold:
            print("Obstacle in Front or Near Front! Changing direction...")
            self.change_direction(angle_to_obstacle)
        else:
            left_range = slice(0, num_readings // 2)
            right_range = slice(num_readings // 2, num_readings)

            avg_left_distance = sum(distances[left_range]) / len(distances[left_range])
            avg_right_distance = sum(distances[right_range]) / len(distances[right_range])

            if avg_left_distance > avg_right_distance:
                print("Best course of action: Turn Right")
                self.turn_right()
            else:
                print("Best course of action: Turn Left")

    def turn_right(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.0
        twist_msg.angular.z = -0.5
        self.publisher.publish(twist_msg)

    def turn_left(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.0
        twist_msg.angular.z = 0.5
        self.publisher.publish(twist_msg)

    def move_forward(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.2
        twist_msg.angular.z = 0.0
        self.publisher.publish(twist_msg)

    def change_direction(self, angle_to_obstacle):
        print("Changing Direction...")
        if angle_to_obstacle < (self.num_readings / 2):
            print("Best course of action: Turn Right")
            self.turn_right()
        else:
            print("Best course of action: Turn Left")

def img_preprocess(img, device, half, net_size):
    net_image, ratio, pad = letterbox(img[:, :, :3], net_size, auto=False)
    net_image = net_image.transpose((2, 0, 1))[::-1]
    net_image = np.ascontiguousarray(net_image)

    img = torch.from_numpy(net_image).to(device)
    img = img.half() if half else img.float()
    img /= 255.0

    if img.ndimension() == 3:
        img = img.unsqueeze(0)
    return img, ratio, pad

def xywh2abcd(xywh, im_shape):
    output = np.zeros((4, 2))
    x_min = (xywh[0] - 0.5*xywh[2]) * im_shape[1]
    x_max = (xywh[0] + 0.5*xywh[2]) * im_shape[1]
    y_min = (xywh[1] - 0.5*xywh[3]) * im_shape[0]
    y_max = (xywh[1] + 0.5*xywh[3]) * im_shape[0]

    output[0][0] = x_min
    output[0][1] = y_min

    output[1][0] = x_max
    output[1][1] = y_min

    output[2][0] = x_min
    output[2][1] = y_max

    output[3][0] = x_max
    output[3][1] = y_max
    return output

def detections_to_custom_box(detections, im, im0):
    output = []
    for i, det in enumerate(detections):
        if len(det):
            det[:, :4] = scale_coords(im.shape[2:], det[:, :4], im0.shape).round()
            gn = torch.tensor(im0.shape)[[1, 0, 1, 0]]

            for *xyxy, conf, cls in reversed(det):
                xywh = (xyxy2xywh(torch.tensor(xyxy).view(1, 4)) / gn).view(-1).tolist()

                obj = sl.CustomBoxObjectData()
                obj.bounding_box_2d = xywh2abcd(xywh, im0.shape)
                obj.label = cls
                obj.probability = conf
                obj.is_grounded = False
                output.append(obj)
    return output

def torch_thread(weights, img_size, conf_thres=0.2, iou_thres=0.45):
    global image_net, exit_signal, run_signal, detections

    device = select_device()
    half = device.type != 'cpu'
    imgsz = img_size

    model = attempt_load(weights, device=device)
    stride = int(model.stride.max())
    imgsz = check_img_size(imgsz, s=stride)
    if half:
        model.half()
    cudnn.benchmark = True

    if device.type != 'cpu':
        model(torch.zeros(1, 3, imgsz, imgsz).to(device).type_as(next(model.parameters())))

    while not exit_signal:
        if run_signal:
            lock.acquire()
            img, ratio, pad = img_preprocess(image_net, device, half, imgsz)

            pred = model(img)[0]
            det = non_max_suppression(pred, conf_thres, iou_thres)

            detections = detections_to_custom_box(det, img, image_net)
            lock.release()
            run_signal = False
        sleep(0.01)

def main():
    global image_net, exit_signal, run_signal, detections

    capture_thread = Thread(target=torch_thread,
                            kwargs={'weights': opt.weights, 'img_size': opt.img_size, "conf_thres": opt.conf_thres})
    capture_thread.start()

    print("Initializing Camera...")

    # Initialize ROS node
    rclpy.init()
    obstacle_avoidance_node = ObstacleAvoidance()

    zed = sl.Camera()

    input_type = sl.InputType()
    if opt.svo is not None:
        input_type.set_from_svo_file(opt.svo)

    init_params = sl.InitParameters(input_t=input_type, svo_real_time_mode=True)
    init_params.camera_resolution = sl.RESOLUTION.HD720
    init_params.coordinate_units = sl.UNIT.METER
    init_params.depth_mode = sl.DEPTH_MODE.ULTRA
    init_params.coordinate_system = sl.COORDINATE_SYSTEM.RIGHT_HANDED_Y_UP
    init_params.depth_maximum_distance = 50

    runtime_params = sl.RuntimeParameters()
    status = zed.open(init_params)

    if status != sl.ERROR_CODE.SUCCESS:
        print(repr(status))
        exit()

    image_left_tmp = sl.Mat()

    print("Initialized Camera")

    positional_tracking_parameters = sl.PositionalTrackingParameters()
    zed.enable_positional_tracking(positional_tracking_parameters)

    obj_param = sl.ObjectDetectionParameters()
    obj_param.detection_model = sl.DETECTION_MODEL.CUSTOM_BOX_OBJECTS
    obj_param.enable_tracking = True
    zed.enable_object_detection(obj_param)

    objects = sl.Objects()
    obj_runtime_param = sl.ObjectDetectionRuntimeParameters()

    camera_infos = zed.get_camera_information()
    viewer = gl.GLViewer()
    point_cloud_res = sl.Resolution(min(camera_infos.camera_resolution.width, 720),
                                    min(camera_infos.camera_resolution.height, 404))

    point_cloud_render = sl.Mat()
    viewer.init(camera_infos.camera_model, point_cloud_res, obj_param.enable_tracking)

    point_cloud = sl.Mat(point_cloud_res.width, point_cloud_res.height, sl.MAT_TYPE.F32_C4, sl.MEM.CPU)
    image_left = sl.Mat()
    display_resolution = sl.Resolution(min(camera_infos.camera_resolution.width, 1280),
                                       min(camera_infos.camera_resolution.height, 720))
    image_scale = [display_resolution.width / camera_infos.camera_resolution.width, display_resolution.height / camera_infos.camera_resolution.height]
    image_left_ocv = np.full((display_resolution.height, display_resolution.width, 4), [245, 239, 239, 255], np.uint8)

    track_view_generator = cv_viewer.TrackingViewer(tracks_resolution, camera_config.camera_fps,
                                                    init_params.depth_maximum_distance)
    track_view_generator.set_camera_calibration(camera_config.calibration_parameters)
    image_track_ocv = np.zeros((tracks_resolution.height, tracks_resolution.width, 4), np.uint8)

    cam_w_pose = sl.Pose()

    while viewer.is_available() and not exit_signal:
        if zed.grab(runtime_params) == sl.ERROR_CODE.SUCCESS:
            lock.acquire()
            zed.retrieve_image(image_left_tmp, sl.VIEW.LEFT)
            image_net = image_left_tmp.get_data()
            lock.release()
            run_signal = True

            while run_signal:
                sleep(0.001)

            lock.acquire()
            zed.ingest_custom_box_objects(detections)
            lock.release()
            zed.retrieve_objects(objects, obj_runtime_param)

            zed.retrieve_measure(point_cloud, sl.MEASURE.XYZRGBA, sl.MEM.CPU, point_cloud_res)
            point_cloud.copy_to(point_cloud_render)
            zed.retrieve_image(image_left, sl.VIEW.LEFT, sl.MEM.CPU, display_resolution)
            zed.get_position(cam_w_pose, sl.REFERENCE_FRAME.WORLD)

            viewer.updateData(point_cloud_render, objects)
            np.copyto(image_left_ocv, image_left.get_data())
            cv_viewer.render_2D(image_left_ocv, image_scale, objects, obj_param.enable_tracking)
            global_image = cv2.hconcat([image_left_ocv, image_track_ocv])
            track_view_generator.generate_view(objects, cam_w_pose, image_track_ocv, objects.is_tracked)

            mc.set_objects(objects)

            cv2.imshow("ZED | 2D View and Birds View", global_image)
            key = cv2.waitKey(10)
            if key == 27:
                exit_signal = True
        else:
            exit_signal = True

    exit_signal = True
    zed.close()
    rclpy.shutdown()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--weights', nargs='+', type=str, default='../weights/best.pt', help='model.pt path(s)')
    parser.add_argument('--svo', type=str, default=None, help='optional svo file')
    parser.add_argument('--img_size', type=int, default=416, help='inference size (pixels)')
    parser.add_argument('--conf_thres', type=float, default=0.4, help='object confidence threshold')
    opt = parser.parse_args()

    with torch.no_grad():
        main()
