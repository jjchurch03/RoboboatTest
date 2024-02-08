# Code for task number 3, docking challenge
# Pin Definitions

# Pin 16: Dig Output - IN1 & IN2 on Relay - Set to Low means Thrusters and Battery are connected
in12 = 16
# Pin 18: PWM Output - Controls Right Thruster (Grey wire)
r_thrust_pwm = 18
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)
l_thrust_pwm = 15

# Imports
import RPi.GPIO as GPIO
import time
import pyzed.sl as sl
import PID

# Initial GPIO Setup
GPIO.setmode(GPIO.BOARD)
GPIO.setup(in12, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

class Thrusters:
    # 1500 = neutral
    # 1100 = max ahead
    # 1900 = max reverse
    p_r = GPIO.PWM(r_thrust_pwm, 50)
    p_l = GPIO.PWM(l_thrust_pwm, 50)
    # right_speed and left_speed should be initiated at 1500, which is neutral
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

thrusters = Thrusters(1500, 1500)
time.sleep(5)
thrusters.changeSpeed(1350, 1350)

class ZedObjects:

    def __init__(self, objects):
        self.objects = objects
        self.green_buoys_list = []
        self.red_buoys_list = []
        self.green_triangle_list = []
        self.red_square_list = []
        self.blue_circle_list = []
        self.blue_plus_list = []
        self.red_plus_list = []
        self.green_plus_list = []
        self.duck_list = []

        self.green_buoy_detected = False
        self.red_buoy_detected = False
        self.green_triangle_detected = False
        self.red_square_detected = False
        self.blue_circle_detected = False
        self.blue_plus_detected = False
        self.red_plus_detected = False
        self.green_plus_detected = False
        self.duck_detected = False

        self.nearest_green_detected = False
        self.nearest_red_detected = False
        self.nearest_green_triangle_detected = False
        self.nearest_red_square_detected = False
        self.nearest_blue_circle_detected = False
        self.nearest_blue_plus_detected = False
        self.nearest_red_plus_detected = False
        self.nearest_green_plus_detected = False
        self.nearest_duck_detected = False

        self.nearest_green_index = -1
        self.nearest_red_index = -1
        self.nearest_green_triangle_index = -1
        self.nearest_red_square_index = -1
        self.nearest_blue_circle_index = -1
        self.nearest_blue_plus_index = -1
        self.nearest_red_plus_index = -1
        self.nearest_green_plus_index = -1
        self.nearest_duck_index = -1

        self.image_of_the_day = 0  # 1=triangle; 2=square; 3=circle; 4=blue_plus; 5=red_plus; 6=green_plus; 7=duck
        self.desired_center_point = 0
        
    def detect_all(self):
        # Fills red_buoy_list and green_buoy_list
        for obj in self.objects.object_list:
            if (str(obj.raw_label) == "5") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Will say "green_buoy or whatever the label is for a green buoy"
                self.green_buoys_list.append(obj)
                self.green_buoy_detected = True
            elif (str(obj.raw_label) == "9") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Red buoy
                self.red_buoys_list.append(obj)
                self.red_buoy_detected = True
            elif (str(obj.raw_label) == "7") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Triangle
                self.green_triangle_list.append(obj)
                self.green_triangle_detected = True
            elif (str(obj.raw_label) == "11") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Square
                self.red_square_list.append(obj)
                self.red_square_detected = True
            elif (str(obj.raw_label) == "1") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Circle
                self.blue_circle_list.append(obj)
                self.blue_circle_detected = True
            elif (str(obj.raw_label) == "2") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Blue Plus
                self.blue_plus_list.append(obj)
                self.blue_plus_detected = True
            elif (str(obj.raw_label) == "10") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Red Plus
                self.red_plus_list.append(obj)
                self.red_plus_detected = True
            elif (str(obj.raw_label) == "6") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Green Plus
                self.green_plus_list.append(obj)
                self.green_plus_detected = True

    def sort_green_buoys(self):
        if not self.green_buoy_detected:
            print("Error: No green buoys detected.")
        else:
            # Find green buoy with closest distance
            green_distances = []
            for green_buoy in self.green_buoys_list:
                green_distances.append(abs((green_buoy.position[2])))
            green_distances.sort()
            i = 0
            for green_buoy in self.green_buoys_list:
                if abs(green_buoy.position[2]) == green_distances[0]:
                    self.nearest_green_index = i
                    self.nearest_green_detected = True
                i += 1
    
    def sort_red_buoys(self):
        if not self.red_buoy_detected:
            print("Error: No red buoys detected.")
        else:
            # Find red buoy with closest distance
            red_distances = []
            for red_buoy in self.red_buoys_list:
                red_distances.append(abs((red_buoy.position[2])))
            red_distances.sort()
            i = 0
            for red_buoy in self.red_buoys_list:
                if abs(red_buoy.position[2]) == red_distances[0]:
                    self.nearest_red_index = i
                    self.nearest_red_detected = True
                i += 1
    
    def sort_triangle(self):
        if not self.green_triangle_detected:
            print("Error: No triangle detected.")
        else:
            # Find the triangle with closest distance
            triangle_distances = []
            for triangle in self.green_triangle_list:
                triangle_distances.append(abs((triangle.position[2])))
            triangle_distances.sort()
            i = 0
            for triangle in self.green_triangle_list:
                if abs(triangle.position[2]) == triangle_distances[0]:
                    self.nearest_triangle_index = i
                    self.nearest_green_triangle_detected = True
                i += 1

    def sort_square(self):
        if not self.red_square_detected:
            print("Error: No square detected.")
        else:
            # Find the square with closest distance
            square_distances = []
            for square in self.red_square_list:
                square_distances.append(abs((square.position[2])))
            square_distances.sort()
            i = 0
            for square in self.red_square_list:
                if abs(square.position[2]) == square_distances[0]:
                    self.nearest_square_index = i
                    self.nearest_red_square_detected = True
                i += 1

    def sort_circle(self):
        if not self.blue_circle_detected:
            print("Error: No circle detected.")
        else:
            # Find the circle with closest distance
            circle_distances = []
            for circle in self.blue_circle_list:
                circle_distances.append(abs((circle.position[2])))
            circle_distances.sort()
            i = 0
            for circle in self.blue_circle_list:
                if abs(circle.position[2]) == circle_distances[0]:
                    self.nearest_circle_index = i
                    self.nearest_blue_circle_detected = True
                i += 1

    def sort_blue_plus(self):
        if not self.blue_plus_detected:
            print("Error: No blue plus detected.")
        else:
            # Find the blue plus with the closest distance
            blue_plus_distances = []
            for blue_plus in self.blue_plus_list:
                blue_plus_distances.append(abs((blue_plus.position[2])))
            blue_plus_distances.sort()
            i = 0
            for blue_plus in self.blue_plus_list:
                if abs(blue_plus.position[2]) == blue_plus_distances[0]:
                    self.nearest_blue_plus_index = i
                    self.nearest_blue_plus_detected = True
                i += 1

    def sort_green_plus(self):
        if not self.green_plus_detected:
            print("Error: No green plus detected.")
        else:
            # Find the green plus with the closest distance
            green_plus_distances = []
            for green_plus in self.green_plus_list:
                green_plus_distances.append(abs((green_plus.position[2])))
            green_plus_distances.sort()
            i = 0
            for green_plus in self.green_plus_list:
                if abs(green_plus.position[2]) == green_plus_distances[0]:
                    self.nearest_green_plus_index = i
                    self.nearest_green_plus_detected = True
                i += 1

    def sort_red_plus(self):
        if not self.red_plus_detected:
            print("Error: No red plus detected.")
        else:
            # Find the red plus with the closest distance
            red_plus_distances = []
            for red_plus in self.red_plus_list:
                red_plus_distances.append(abs((red_plus.position[2])))
            red_plus_distances.sort()
            i = 0
            for red_plus in self.red_plus_list:
                if abs(red_plus.position[2]) == red_plus_distances[0]:
                    self.nearest_red_plus_index = i
                    self.nearest_red_plus_detected = True
                i += 1

    def sort_duck(self):
        if not self.duck_detected:
            print("Error: No duck detected.")
        else:
            # Find the duck with the closest distance
            duck_distances = []
            for duck in self.duck_list:
                duck_distances.append(abs((duck.position[2])))
            duck_distances.sort()
            i = 0
            for duck in self.duck_list:
                if abs(duck.position[2]) == duck_distances[0]:
                    self.nearest_duck_index = i
                    self.nearest_duck_detected = True
                i += 1
    
    def find_center_point(self):
        match self.image_of_the_day:
            case 1:  # green triangle
                if self.nearest_green_triangle_detected:
                    return round((self.green_triangle_list[self.nearest_green_triangle_index].bounding_box_2d[1][0] + self.green_triangle_list[self.nearest_green_triangle_index].bounding_box_2d[0][0]) / 2)
                else:
                    print("Error: Nearest green triangle not detected.")
                    return -1
            case 2:  # red square
                if self.nearest_red_square_detected:
                    return round((self.red_square_list[self.nearest_red_square_index].bounding_box_2d[1][0] + self.red_square_list[self.nearest_red_square_index].bounding_box_2d[0][0]) / 2)
                else:
                    print("Error: Nearest red square not detected.")
                    return -1
            case 3:  # blue circle
                if self.nearest_blue_circle_detected:
                    return round((self.blue_circle_list[self.nearest_blue_circle_index].bounding_box_2d[1][0] + self.blue_circle_list[self.nearest_blue_circle_index].bounding_box_2d[0][0]) / 2)
                else:
                    print("Error: Nearest blue circle not detected.")
                    return -1
            case 4:  # blue plus
                if self.nearest_blue_plus_detected:
                    return round((self.blue_plus_list[self.nearest_blue_plus_index].bounding_box_2d[1][0] + self.blue_plus_list[self.nearest_blue_plus_index].bounding_box_2d[0][0]) / 2)
                else:
                    print("Error: Nearest blue plus not detected.")
                    return -1
            case 5:  # red plus
                if self.nearest_red_plus_detected:
                    return round((self.red_plus_list[self.nearest_red_plus_index].bounding_box_2d[1][0] + self.red_plus_list[self.nearest_red_plus_index].bounding_box_2d[0][0]) / 2)
                else:
                    print("Error: Nearest red plus not detected.")
                    return -1
            case 6:  # green plus
                if self.nearest_green_plus_detected:
                    return round((self.green_plus_list[self.nearest_green_plus_index].bounding_box_2d[1][0] + self.green_plus_list[self.nearest_green_plus_index].bounding_box_2d[0][0]) / 2)
                else:
                    print("Error: Nearest green plus not detected.")
                    return -1
            case 7:  # duck
                if self.nearest_duck_detected:
                    return round((self.duck_list[self.nearest_duck_index].bounding_box_2d[1][0] + self.duck_list[self.nearest_duck_index].bounding_box_2d[0][0]) / 2)
                else:
                    print("Error: Nearest duck not detected.")
                    return -1




def set_objects(objects_in):
    objects = ZedObjects(objects_in)
    objects.detect_all()
    objects.sort_green_buoys()
    objects.sort_red_buoys()
    print("Center Point: " + str(objects.find_center_point()))
    move_to_center(objects.find_center_point())

def move_to_center(center_point):
    zed_center_pixel = 1280 / 2

    if center_point == -1:
        # Go straight slowly if buoy channel not detected
        thrusters.change_speed(1425, 1425)
    elif center_point <= zed_center_pixel - 20:
        # Turn to the left when on the right side of channel
        thrusters.change_speed(1400, 1300)
    elif center_point >= zed_center_pixel + 20:
        # Turn to the right when on left side of channel
        thrusters.change_speed(1300, 1400)
    else:
        # Go forward if within 20 pixels of center channel
        thrusters.change_speed(1400, 1400)

def match_speed(distance_away):
    goal_distance = 1  # distance we want to be in meters
    if goal_distance * 3 >= distance_away:
        thrusters.change_speed(1400, 1400)
    elif goal_distance * 2 >= distance_away:
        thrusters.change_speed(1425, 1425)
    elif goal_distance * 1.5 >= distance_away:
        thrusters.change_speed(1450, 1450)
    elif goal_distance * 1.1 >= distance_away or goal_distance * 0.9 <= distance_away:
        thrusters.change_speed(1500 + 10 * (goal_distance - distance_away), 1500 + 10 * (goal_distance - distance_away))
