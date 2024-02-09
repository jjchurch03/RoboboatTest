# Code for task number 3, docking challenge
# Pin Definitions
# Pin 18: PWM Output - Controls Right Thruster (Grey wire)
r_thrust_pwm = 18
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)
l_thrust_pwm = 15

# Imports
import RPi.GPIO as GPIO
import time
import pyzed.sl as sl
# import PID

# Initial GPIO Setup
GPIO.setmode(GPIO.BOARD)
# GPIO.setup(in12, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

class Thrusters:
    # 1500 = neuteral
    # 1100 = max ahead
    # 1900 = max reverse
    p_r = GPIO.PWM(r_thrust_pwm, 50)
    p_l = GPIO.PWM(l_thrust_pwm, 50)
    # right_speed and left_speed should be initiated at 1500, which is neuteral
    def __init__(thrusters, left_speed, right_speed):
        thrusters.right_speed = right_speed
        thrusters.left_speed = left_speed
        thrusters.changeSpeed(left_speed, right_speed)

    def changeSpeed(thrusters, left_speed, right_speed):
        # Change right thruster to set value
        thrusters.right_speed = right_speed
        thrusters.p_r.start(right_speed/200)
        # Change left thruster to set value
        thrusters.left_speed = left_speed
        thrusters.p_l.start(left_speed/200)

    def stop(thrusters):
        thrusters.p_r.stop()
        thrusters.p_l.stop()

# Initialize the thrusters into neutral then set them to go straight forward
thrusters = Thrusters(1500, 1500)
time.sleep(5)
thrusters.changeSpeed(1400, 1400) #slower than original code

# Takes in Zed Objects, which contains info on distance, bounding box position, etc.
class ZedObjects:
    def __init__(self, objects):
       
       self.objects = objects

       self.defined_day_shape_list = []
        # self.green_triangle_list = []

       self.defined_day_shape_detected = False
        # self.red_buoy_detected = False

       self.nearest_defined_day_shape_detected = False
        # self.nearest_red_detected = False
       
       self.distance_away = 10
       
       self.center_point = -1

       self.nearest_defined_day_shape_index = -1
        # self.nearest_red_index = -1
        # self.desired_center_point = 0
        # 1=triangle; 2=square; 3=circle; 4=blue_plus; 5=red_plus; 6=green_plus; 7=duck
        # ask what is the image of the day
        # set the image to the image of the day
    
        # set self.detected image to _ for shape of the day, update the index when it finds the shape to _, when the two match, then drive towards that         
       #for obj in objects.object_list:
            #print("x_min: " + str(obj.bounding_box_2d[0][0]))
            #print("x_max: " + str(obj.bounding_box_2d[1][0]))
         #   print("Distance: " + str(abs((obj.position[2]))))
            #print("Object Label: " + str(obj.raw_label))

    # Determines if red and green buoys are detected then puts them in two seperate arrays (red_buoy_list and green_buoy_list)
    def detect_all(self):
        # Fills red_buoy_list and green_buoy_list  
        for obj in self.objects.object_list:
            if (str(obj.raw_label) == "3") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Will say "green_buoy or whatever the label is for a green buoy"
                self.defined_day_shape_list.append(obj)
                self.defined_day_shape_detected = True
#			elif (str(obj.raw_label) == "9") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Red buoy
#				self.red_buoys_list.append(obj)
#				self.red_buoy_detected = True
#            elif (str(obj.raw_label) == "7") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Triangle
#                self.green_triangle_list.append(obj)
#				self.green_triangle_detected = True
#            elif (str(obj.raw_label) == "11") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Square
#                self.red_square_list.append(obj)
#				self.red_square_detected = True
#            elif (str(obj.raw_label) == "1") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Circle
            #     self.blue_circle_list.append(obj)
            # 	self.blue_circle_detected = True
            # elif (str(obj.raw_label) == "2") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Blue Plus
            #     self.blue_plus_list.append(obj)
            # 	self.blue_plus_detected = True
            # elif (str(obj.raw_label) == "10") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Red Plus
            #     self.red_plus_list.append(obj)
            # 	self.red_plus_detected = True
            # elif (str(obj.raw_label) == "6") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Green Plus
            #     self.green_plus_list.append(obj)
            # 	self.green_plus_detected = True
            

    def sort_detected_day_shape(self):
        if self.defined_day_shape_detected == False:
            print("Error: No day_shape_detected detected.")
        else:
            # Find day shape with closest distance
            day_distances = []
            for day_shape in self.defined_day_shape_list:
                day_distances.append(abs((day_shape.position[2])))
            day_distances.sort()
            i = 0
            for day_shape in self.defined_day_shape_list:
                if abs(day_shape.position[2]) == day_distances[0]:
                    self.nearest_defined_day_shape_index = i
                    self.self.defined_day_shape_detected = True
                i = i + 1				   
            self.distance_away = day_distances[0]


    def get_nearest_defined_day_shape(self):
        if self.nearest_defined_day_shape_detected == False:
            print("Error: No day shape detected.")
        elif self.nearest_defined_day_shape_detected == False:
            print("Error: Nearest day shape not yet detected.")
        else:
            return self.defined_day_shape_list[self.nearest_defined_day_shape_index] 
        
    # def get_nearest_red_buoy(self):
    # 	if self.red_buoy_detected == False:
    # 		print("Error: No red buoys detected.")
    # 	elif self.nearest_red_detected == False:
    # 		print("Error: Nearest red buoy not yet detected.")
    # 	else:
    # 		return self.red_buoys_list[self.nearest_red_index]
    # def get_nearest_circle
    
    # Finds what pixel is at the center of the green and red buoys
    #def find_center_point(self):
    # 	match self.image_of_the_day
    # 	case 1 # green triangle
    # 		self.center_point = round((self.get_nearest_triangle().bounding_box_2d[1][0] + self.get_nearest_triangle().bounding_box_2d[0][0])/2)
    # 	case 2 # red square
    # 		self.center_point = round((self.get_nearest_square().bounding_box_2d[1][0] + self.get_nearest_square().bounding_box_2d[0][0])/2)
    # 	case 3 # blue circle
    # 		self.center_point = round((self.get_nearest_circle().bounding_box_2d[1][0] + self.get_nearest_circle().bounding_box_2d[0][0])/2)
    # 	case 4 # blue plus
    # 		self.center_point = round((self.get_nearest_blue_plus().bounding_box_2d[1][0] + self.get_nearest_blue_plus().bounding_box_2d[0][0])/2)
    # 	case 5 # red plus
    # 		self.center_point = round((self.get_nearest_red_plus().bounding_box_2d[1][0] + self.get_nearest_red_plus().bounding_box_2d[0][0])/2)
    # 	case 6 # green plus
    # 		self.center_point = round((self.get_nearest_green_plus().bounding_box_2d[1][0] + self.get_nearest_green_plus().bounding_box_2d[0][0])/2)
    # 	case 7 # duck
    # 		self.center_point = round((self.get_nearest_duck().bounding_box_2d[1][0] + self.get_nearest_green_plus().bounding_box_2d[0][0])/2)
            

# Takes in list of objects from Zed 2i Camera each frame
def find_center_point(self):
        if self.defined_day_shape_index == -1:
            print("Error: Issue with day shape index")
            return -1
        else:
            xmin_shape = self.get_nearest_defined_day_shape().bounding_box_2d[0][0]
            xmax_shape = self.get_nearest_defined_day_shape().bounding_box_2d[1][0]
            self.center_point = round((xmin_shape + xmax_shape)/2)
            return self.center_point
        
# def find_Distance(self):
#         if self.defined_day_shape_index == -1:
#             print("Error: Issue with day shape index")
#             return -1
#         else:
#             self.distance_away = abs(self.get_nearest_defined_day_shape().position[2])
#             return self.distance_away       

def set_objects(objects_in):
    objects = ZedObjects(objects_in)
    objects.detect_all()
    objects.sort_detected_day_shape()
    print("Center Point: " + str(objects.find_center_point()))
    move_to_center(objects.find_center_point())
    # self.distance_away = abs((obj.position[2]))


# Adjusts moters to ensure the pixel center point of the green and red buoys lines up with the center pixel of the image (640)
def move_to_center(center_point,distance_away):
    zed_center_pixel = 1280/2

    if center_point == -1:
    # Go straight slowly if buoy channel not detected
        thrusters.changeSpeed(1425, 1425)
        print("channel not detected, going straight slowly")
    # Turn to the left when on the right side of channel
    elif center_point <= zed_center_pixel - 20:
        thrusters.changeSpeed(1450, 1350)
        print("poster too far to the left, turning left")
    # Turn to the right when on left side of channel
    elif center_point >= zed_center_pixel + 20:
        thrusters.changeSpeed(1350, 1450)
        print("poster too far to the right, turning right")
    else:
    # Go forward if within 20 pixels of center channel
       goal_distance = 1 # distance we want to be in meters
       if goal_distance*5 >= distance_away:
            thrusters.changeSpeed(1400,1400)
            print("5 meters: most speed")
       elif goal_distance*2.5 >= distance_away:
            thrusters.changeSpeed(1425,1425)
            print("2.5 meters: medium speed")
       elif goal_distance*1.5 >= distance_away:
            thrusters.changeSpeed(1450,1450)
            print("1.5 meters: slow speed")
       elif goal_distance*1.1 >= distance_away or goal_distance*0.9 <= distance_away:
            thrusters.changeSpeed(1500+10*(goal_distance-distance_away),1500+10*(goal_distance-distance_away))
            print("1.1 meters: station-keep")
       else:
            time.sleep(5)
            thrusters.changeSpeed(1550,1550)
            print("idk")

# def match_speed(distance_away):
#    goal_distance = 1 # distance we want to be in meters
#    if goal_distance*5 >= distance_away:
#        thruster.changeSpeed(1400,1400)
#    elif goal_distance*2.5 >= distance_away:
#        thruster.changeSpeed(1425,1425)
#    elif goal_distance*1.5 >= distance_away:
#        thruster.changeSpeed(1450,1450)
#    elif goal_distance*1.1 >= distance_away or goal_distance*0.9 <= distance_away:
#        thruster.changeSpeed(1500+10*(goal_distance-distance_away),1500+10*(goal_distance-distance_away))
#    else:
#        time.sleep(5)
#        thrusters.changeSpeed(1550,1550)






## Sudo code for task 3
# drive straight
# aquire image of the day based on set variables (blue vs green, square vs triangle)
    #scan back and forth, so slowly rotate back and forth
    #aquire the correct image based on the defined stuff
# use the move to center controller logic, keep the image in the center
# use new speed controller to control speed as you get closer
# once 3(?) feet away from dock, do not get any closer
