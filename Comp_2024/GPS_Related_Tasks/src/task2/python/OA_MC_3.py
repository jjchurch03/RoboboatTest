# Pin Definitions
# Pin 16: Digital Output - IN1 & IN2 on Relay - Set to Low means Thrusters and Battery are connected
in12 = 16 
# Pin 18: Pulse Width Modulation (PWM) Output - Controls Right Thruster (Grey wire)
r_thrust_pwm = 18
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)
l_thrust_pwm = 15

# Imports
import RPi.GPIO as GPIO
import time
import pyzed.sl as sl
import numpy as np

# Importing modules from OA
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan

# Initial GPIO Setup and control
GPIO.setmode(GPIO.BOARD)
GPIO.setup(in12, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

class Thrusters:
 
    p_r = GPIO.PWM(r_thrust_pwm, 50)
    p_l = GPIO.PWM(l_thrust_pwm, 50)
    def __init__(self, left_speed, right_speed):
        self.right_speed = right_speed
        self.left_speed = left_speed
        self.change_speed(left_speed, right_speed)
        
    def change_speed(self, left_speed, right_speed):
        self.right_speed = right_speed
        self.p_r.start(right_speed / 200)
        self.left_speed = left_speed
        self.p_l.start(left_speed / 200)
        
    def stop(self):
        self.p_r.stop()
        self.p_l.stop()

# Initialize the thrusters into neutral then set them to go straight forward
thrusters = Thrusters(1500, 1500)
time.sleep(5)
thrusters.change_speed(1450, 1450) # Slower than original code

# Constants
MIN_DISTANCE_THRESHOLD = 1.65
SAFE_FORWARD_DISTANCE = 0.5

class ObstacleAvoidance(Node):
    def __init__(self):
        global obstacle_avoidance_node
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)

        # Set minimum distance threshold for obstacle detection
        self.min_distance_threshold = MIN_DISTANCE_THRESHOLD  
        # Set starting distance for obstacle consideration
        self.starting_distance = 0.6  # meters
        # Set degree range for checking path ahead
        self.degree_range = 0.98 # degrees

        # Initialize the number of laser scan readings
        self.num_readings = 0  

        # Define left and right range for laser scan readings
        self.left_range = None
        self.right_range = None

        self.obstacle_distances = []

    def scan_callback(self, msg):
        global obstacle_avoidance_node  # Access global obstacle_avoidance_node
        distances = msg.ranges
        self.obstacle_distances = [x for x in distances if not np.isnan(x)]

        # Filter distances starting from 0.6 meters away
        start_index = int(self.starting_distance / msg.range_max * len(self.obstacle_distances))
        filtered_distances = self.obstacle_distances[start_index:]

        # Check if there are obstacles within the specified degree range
        degree_range_indices = int(self.degree_range / msg.angle_increment)
        path_clear = self.is_path_clear(filtered_distances, degree_range_indices)

        if not path_clear:
            self.avoid_obstacle(filtered_distances, msg)
        else:
            print("Clear path")  # Print statement indicating clear path
            # Continue moving straight
            thrusters.change_speed(1400, 1400)  # Adjust thrusters to move straight

    def is_path_clear(self, distances, degree_range_indices):
        # Get distances within the specified degree range
        front_distances = distances[:degree_range_indices]
        back_distances = distances[-degree_range_indices:]

        # Check if there are obstacles within the specified distance threshold
        if min(front_distances) < self.min_distance_threshold or min(back_distances) < self.min_distance_threshold:
            return False
        else:
            return True

    def avoid_obstacle(self, distances, msg):
        # Find the index of the closest obstacle
        closest_index = distances.index(min(distances))
        num_readings = len(distances)

        # Get the angle increment of laser scan readings
        angle_increment = msg.angle_increment
        print("Calculating Angle... Angle Increment:", angle_increment)

        # Calculate angle to the closest obstacle
        angle_to_obstacle = closest_index * angle_increment
        print("Angle to Obstacle:", angle_to_obstacle)

        # Define the range for the left side and right side of laser scan readings
        self.left_range = slice(0, num_readings // 2)  
        self.right_range = slice(num_readings // 2, num_readings)

        # Calculate average distance on the left and right side
        avg_left_distance = sum(distances[self.left_range]) / len(distances[self.left_range])  
        avg_right_distance = sum(distances[self.right_range]) / len(distances[self.right_range])

        #Based on objects around the vessel make a decision
        if avg_left_distance > avg_right_distance:
            print("Best course of action: Turn Left")
            thrusters.change_speed(1400, 1300)
        else:
            print("Best course of action: Turn Left")
            thrusters.change_speed(1300, 1400)

# Takes in Zed Objects, which contains info on distance, bounding box position, etc.
class ZedObjects:
    def __init__(self, objects):
        self.objects = objects

        self.green_buoys_list = []
        self.red_buoys_list = []         # Holds all zed objects in the frame that are green buoys
        self.red_ball_list = []
        self.green_ball_list = []
        self.yellow_ball_list = []
        self.black_ball_list = []

        self.green_buoy_detected = False
        self.red_buoy_detected = False
        self.red_ball_detected = False
        self.green_ball_detected = False
        self.yellow_ball_detected = False
        self.black_ball_detected = False

        self.nearest_green_detected = False
        self.nearest_red_detected = False
        self.nearest_red_ball_detected = False
        self.nearest_green_ball_detected = False
        self.nearest_yellow_ball_detected = False
        self.nearest_black_ball_detected = False

        self.nearest_green_index = -1
        self.nearest_red_index = -1
        self.nearest_red_ball_index = -1
        self.nearest_green_ball_index = -1
        self.nearest_yellow_ball_index = -1
        self.nearest_black_ball_index = -1

        self.desired_center_point = 0

        self.duck_counter = 0
		
    # Determines if buoys are detected then puts them into separate arrays (red_buoy_list, green_buoy_list, red_ball_list, etc...)
    def detect_buoys(self):
        # Fills red_buoy_list, green_buoy_list, red_ball_list, etc...
        for obj in self.objects.object_list:
            if (str(obj.raw_label) == "5") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Will say "green_buoy or whatever the label is for a green buoy"
                self.green_buoys_list.append(obj)
                self.green_buoy_detected = True                
            elif (str(obj.raw_label) == "9") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
                self.red_buoys_list.append(obj)
                self.red_buoy_detected = True
            if (str(obj.raw_label) == "8") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
                self.red_ball_list.append(obj)
                self.red_ball_detected = True    
            elif (str(obj.raw_label) == "4") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
                self.green_ball_list.append(obj)
                self.green_ball_detected = True        
            elif (str(obj.raw_label) == "12") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
                self.yellow_ball_list.append(obj)
                self.yellow_ball_detected = True
                self.duck_counter = self.duck_counter + 1
                print("Ducks... Quack count: " + str(self.duck_counter))                
            elif (str(obj.raw_label) == "0") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
                self.black_ball_list.append(obj)
                self.black_ball_detected = True
                                                                
    
    # If present, finds the nearest of each type of buoy
    def sort_green_buoys(self):
        if self.green_buoy_detected == False:
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
                i = i + 1
    
    def sort_red_buoys(self):
        if self.red_buoy_detected == False:
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
                i = i + 1

    def sort_red_ball(self):
        if self.red_ball_detected == False:
            print("Error: No red balls detected.")
        else:
            # Find red ball with closest distance
            red_ball_distances = []
            for red_ball in self.red_ball_list:
                red_ball_distances.append(abs((red_ball.position[2])))
            red_ball_distances.sort()
            i = 0
            for red_ball in self.red_ball_list:
                if abs(red_ball.position[2]) == red_ball_distances[0]:
                    self.nearest_red_ball_index = i
                    self.nearest_red_ball_detected = True
                i = i + 1        

    def sort_green_ball(self):
        if self.green_ball_detected == False:
            print("Error: No green balls detected.")
        else:
            # Find green ball with closest distance
            green_ball_distances = []
            for green_ball in self.green_ball_list:
                green_ball_distances.append(abs((green_ball.position[2])))
            green_ball_distances.sort()
            i = 0
            for green_ball in self.green_ball_list:
                if abs(green_ball.position[2]) == green_ball_distances[0]:
                    self.nearest_green_ball_index = i
                    self.nearest_green_ball_detected = True
                i = i + 1    

    def sort_yellow_ball(self):
        if self.yellow_ball_detected == False:
            print("Error: No yellow balls detected.")
        else:
            # Find yellow ball with closest distance
            yellow_ball_distances = []
            for yellow_ball in self.yellow_ball_list:
                yellow_ball_distances.append(abs((yellow_ball.position[2])))
            yellow_ball_distances.sort()
            i = 0
            for yellow_ball in self.yellow_ball_list:
                if abs(yellow_ball.position[2]) == yellow_ball_distances[0]:
                    self.nearest_yellow_ball_index = i
                    self.nearest_yellow_ball_detected = True
                i = i + 1        
                
    def sort_black_ball(self):
        if self.black_ball_detected == False:
            print("Error: No black balls detected.")
        else:
            # Find black ball with closest distance
            black_ball_distances = []
            for black_ball in self.black_ball_list:
                black_ball_distances.append(abs((black_ball.position[2])))
            black_ball_distances.sort()
            i = 0
            for black_ball in self.black_ball_list:
                if abs(black_ball.position[2]) == black_ball_distances[0]:
                    self.nearest_black_ball_index = i
                    self.nearest_black_ball_detected = True
                i = i + 1    


    def get_nearest_green_buoy(self):
        if self.green_buoy_detected == False:
            print("Error: No green buoys detected.")
        elif self.nearest_green_detected == False:
            print("Error: Nearest green buoy not yet detected.")
        else:
            return self.green_buoys_list[self.nearest_green_index] 
        
    def get_nearest_red_buoy(self):
        if self.red_buoy_detected == False:
            print("Error: No red buoys detected.")
        elif self.nearest_red_detected == False:
            print("Error: Nearest red buoy not yet detected.")
        else:
            return self.red_buoys_list[self.nearest_red_index]

    def get_nearest_red_ball(self):
        if self.red_ball_detected == False:
            print("Error: No red balls detected.")
        elif self.nearest_red_ball_detected == False:
            print("Error: Nearest red ball not yet detected.")
        else:
            return self.red_ball_list[self.nearest_red_ball_index]    

    def get_nearest_green_ball(self):
        if self.green_ball_detected == False:
            print("Error: No green balls detected.")
        elif self.nearest_green_ball_detected == False:
            print("Error: Nearest green ball not yet detected.")
        else:
            return self.green_ball_list[self.nearest_green_ball_index]        

    def get_nearest_yellow_ball(self):
        if self.yellow_ball_detected == False:
            print("Error: No yellow balls detected.")
        elif self.nearest_yellow_ball_detected == False:
            print("Error: Nearest yellow ball not yet detected.")
        else:
            return self.yellow_ball_list[self.nearest_yellow_ball_index]        

    def get_nearest_black_ball(self):
        if self.black_ball_detected == False:
            print("Error: No black balls detected.")
        elif self.nearest_black_ball_detected == False:
            print("Error: Nearest black ball not yet detected.")
        else:
            return self.black_ball_list[self.nearest_black_ball_index]

    def find_desired_center_point(self):
        if self.nearest_green_ball_index == -1:
            print("Error: Issue with green ball index")
            return -1
        elif self.nearest_red_ball_index == -1:
            print("Error: Issue with red ball index")
            return -1
        else:
            	# takes avg of max and min point of x axis of bounding box to find the center point of the buoy itself (before finding center point between seperate buoys)
            xCenter_red_ball = round((self.get_nearest_red_ball().bounding_box_2d[1][0] + self.get_nearest_red_ball().bounding_box_2d[0][0])/2)
            xCenter_green_ball = round((self.get_nearest_green_ball().bounding_box_2d[1][0] + self.get_nearest_green_ball().bounding_box_2d[0][0])/2)
            	# finds center point between two closest red and green buoys
            self.channel_center_point = round((xCenter_red_ball + xCenter_green_ball)/2)
            if xCenter_red_ball < xCenter_green_ball:
				# red on left, green on right: vessel is "departing" 
                return_or_depart = 0
            else:
				# red, right, returning
                return_or_depart = 1

            if self.nearest_yellow_ball_index != -1 & self.nearest_black_ball_index != -1:
                print("black and yellow obsticles detected")
                xCenter_yellow_ball = round((self.get_nearest_yellow_ball().bounding_box_2d[1][0] + self.get_nearest_yellow_ball().bounding_box_2d[0][0])/2)
                xCenter_black_ball = round((self.get_nearest_black_ball().bounding_box_2d[1][0] + self.get_nearest_black_ball().bounding_box_2d[0][0])/2)

				# red on left, green on right...
                if return_or_depart == 0:
					#if yellow ball is closer than black ball:
                    if self.get_nearest_yellow_ball().dist < self.get_nearest_black_ball().dist: 
					# if yellow ball is in the channel...
                        if xCenter_yellow_ball < xCenter_green_ball & xCenter_yellow_ball > xCenter_red_ball:
                            stbd_gap_width = xCenter_green_ball - xCenter_yellow_ball						
                            port_gap_width = xCenter_yellow_ball - xCenter_red_ball
                            if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
                                move_port_or_stbd = 0
                            else:
								# 1 = port side is greater, move to the left of the yellow ball
                                move_port_or_stbd = 1
                            if move_port_or_stbd == 0:
                                print("Departing: move to stbd side of yellow ball")
                                self.desired_center_point = round((xCenter_green_ball + xCenter_yellow_ball)/2)
                            else:
                                print("Departing: move to port side of yellow ball")
                                self.desired_center_point = round((xCenter_red_ball + xCenter_yellow_ball)/2)
                        else:
					# if black ball is in the channel...
                            if xCenter_black_ball < xCenter_green_ball & xCenter_black_ball > xCenter_red_ball:
                                stbd_gap_width = xCenter_green_ball - xCenter_black_ball						
                                port_gap_width = xCenter_black_ball - xCenter_red_ball
                                if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
                                   move_port_or_stbd = 0
                                else:
								# 1 = port side is greater, move to the left of the yellow ball
                                   move_port_or_stbd = 1
                                if move_port_or_stbd == 0:
                                    print("Departing: move to stbd side of black ball")
                                    self.desired_center_point = round((xCenter_green_ball + xCenter_black_ball)/2)
                                else:
                                    print("Departing: move to port side of black ball")
                                    self.desired_center_point = round((xCenter_red_ball + xCenter_black_ball)/2)
				# red on right, green on left					
                else:
					#if yellow ball is closer than black ball:
                    if self.get_nearest_yellow_ball().dist < self.get_nearest_black_ball().dist: 
					# if yellow ball is in the channel...
                        if xCenter_yellow_ball > xCenter_green_ball & xCenter_yellow_ball < xCenter_red_ball:
                            stbd_gap_width = xCenter_red_ball - xCenter_yellow_ball						
                            port_gap_width = xCenter_yellow_ball - xCenter_green_ball
                            if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
                                move_port_or_stbd = 0
                            else:
								# 1 = port side is greater, move to the left of the yellow ball
                                move_port_or_stbd = 1
                            if move_port_or_stbd == 0:
                                print("Returning: move to stbd side of yellow ball")
                                self.desired_center_point = round((xCenter_red_ball + xCenter_yellow_ball)/2)
                            else:
                                print("Returning: move to port side of yellow ball")
                                self.desired_center_point = round((xCenter_green_ball + xCenter_yellow_ball)/2)
                        
                        else:
					# if black ball is in the channel...
                            if xCenter_black_ball > xCenter_green_ball & xCenter_black_ball < xCenter_red_ball:
                                stbd_gap_width = xCenter_red_ball - xCenter_black_ball						
                                port_gap_width = xCenter_black_ball - xCenter_green_ball
                                if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
                                   move_port_or_stbd = 0
                                else:
								# 1 = port side is greater, move to the left of the yellow ball
                                   move_port_or_stbd = 1
                                if move_port_or_stbd == 0:  
                                    print("Returning: move to stbd side of black ball")
                                    self.desired_center_point = round((xCenter_red_ball + xCenter_black_ball)/2)
                                else:
                                    print("Returning: move to port side of black ball")
                                    self.desired_center_point = round((xCenter_green_ball + xCenter_black_ball)/2)	

                return self.desired_center_point
			
            elif self.nearest_yellow_ball_index == -1 & self.nearest_black_ball_index != -1:
                print("only black ball(s) detected")
                xCenter_black_ball = round((self.get_nearest_black_ball().bounding_box_2d[1][0] + self.get_nearest_black_ball().bounding_box_2d[0][0])/2)
                if return_or_depart == 0:
                    if xCenter_black_ball < xCenter_green_ball & xCenter_black_ball > xCenter_red_ball:
                        stbd_gap_width = xCenter_green_ball - xCenter_black_ball						
                        port_gap_width = xCenter_black_ball - xCenter_red_ball
                        if port_gap_width < stbd_gap_width:
                                                
                    		# 0 = stbd side is greater, move to the right of the yellow ball
                            move_port_or_stbd = 0
                        else:
								# 1 = port side is greater, move to the left of the yellow ball
                            move_port_or_stbd = 1
                        if move_port_or_stbd == 0:
                            print("Departing: move to stbd side of black ball")
                            self.desired_center_point = round((xCenter_green_ball + xCenter_black_ball)/2)
                        else:
                            print("Departing: move to port side of black ball")
                            self.desired_center_point = round((xCenter_red_ball + xCenter_black_ball)/2)
                    else:
                         if xCenter_black_ball > xCenter_green_ball & xCenter_black_ball < xCenter_red_ball:
                            stbd_gap_width = xCenter_red_ball - xCenter_black_ball						
                            port_gap_width = xCenter_black_ball - xCenter_green_ball
                            if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
                                move_port_or_stbd = 0
                            else:
								# 1 = port side is greater, move to the left of the yellow ball
                                move_port_or_stbd = 1
                                
                            if move_port_or_stbd == 0:
                                print("Returning: move to stbd side of black ball")
                                self.desired_center_point = round((xCenter_red_ball + xCenter_black_ball)/2)
                            else:
                                print("Returning: move to port side of black ball")
                                self.desired_center_point = round((xCenter_green_ball + xCenter_black_ball)/2)

##################################### only yellow balls in channel detected ##########################
            elif self.nearest_yellow_ball_index != -1 & self.nearest_black_ball_index == -1:
                print("only yellow ball(s) detected")
                xCenter_yellow_ball = round((self.get_nearest_yellow_ball().bounding_box_2d[1][0] + self.get_nearest_yellow_ball().bounding_box_2d[0][0])/2)
                if return_or_depart == 0:
                    if xCenter_yellow_ball < xCenter_green_ball & xCenter_yellow_ball > xCenter_red_ball:
                        stbd_gap_width = xCenter_green_ball - xCenter_yellow_ball						
                        port_gap_width = xCenter_yellow_ball - xCenter_red_ball
                        if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
                            move_port_or_stbd = 0
                        else:
								# 1 = port side is greater, move to the left of the yellow ball
                            move_port_or_stbd = 1
                        if move_port_or_stbd == 0:
                            print("Departing: move to stbd side of yellow ball")
                            self.desired_center_point = round((xCenter_green_ball + xCenter_yellow_ball)/2)
                        else:
                            print("Departing: move to port side of yellow ball")
                            self.desired_center_point = round((xCenter_red_ball + xCenter_yellow_ball)/2)
                    else:
                        if xCenter_yellow_ball > xCenter_green_ball & xCenter_yellow_ball < xCenter_red_ball:
                            stbd_gap_width = xCenter_red_ball - xCenter_yellow_ball						
                            port_gap_width = xCenter_yellow_ball - xCenter_green_ball
                            if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
                                move_port_or_stbd = 0
                            else:
								# 1 = port side is greater, move to the left of the yellow ball
                                move_port_or_stbd = 1
                            if move_port_or_stbd == 0:
                                print("Returning: move to stbd side of yellow ball")
                                self.desired_center_point = round((xCenter_red_ball + xCenter_yellow_ball)/2)
                            else:
                                print("Returning: move to port side of yellow ball")
                                self.desired_center_point = round((xCenter_green_ball + xCenter_yellow_ball)/2)

            else:
                print("no obstacle ball index detected")
                self.desired_center_point = self.channel_center_point
                return self.desired_center_point
            
obstacle_avoidance_node = None

def set_objects(objects_in):
    objects = ZedObjects(objects_in)
    objects.detect_buoys()
    objects.sort_green_buoys()
    objects.sort_red_buoys()
    objects.sort_red_ball()
    objects.sort_green_ball()
    objects.sort_yellow_ball()
    objects.sort_black_ball()
    print("Desired Center Point: " + str(objects.find_desired_center_point()))
    move_to_center(objects.find_desired_center_point())

def move_to_center(desired_center_point):
    global obstacle_avoidance_node
    zed_center_pixel = 1280/2

    if desired_center_point == -1:
        # Go straight slowly if buoy channel not detected
        thrusters.change_speed(1425, 1425)
    # Turn to the left when on the right side of channel
    elif desired_center_point <= zed_center_pixel - 20:
        thrusters.change_speed(1400, 1300)
    # Turn to the right when on left side of channel
    elif desired_center_point >= zed_center_pixel + 20:
        thrusters.change_speed(1300, 1400)
    else:
        # Go forward if within 20 pixels of center channel
        thrusters.change_speed(1400, 1400)
    
    # Instantiate ObstacleAvoidance class if not already instantiated
    # Start the ROS 2 node and run obstacle avoidance
    rclpy.init()
    obstacle_avoidance_node = ObstacleAvoidance()
    rclpy.spin_once(obstacle_avoidance_node)
    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()

