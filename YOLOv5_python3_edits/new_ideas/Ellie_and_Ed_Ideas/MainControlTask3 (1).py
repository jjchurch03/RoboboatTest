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
thrusters.changeSpeed(1350, 1350)

# Takes in Zed Objects, which contains info on distance, bounding box position, etc.
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

		self.image_of_the_day = 0 # 1=triangle; 2=square; 3=circle; 4=blue_plus; 5=red_plus; 6=green_plus; 7=duck
		# ask what is the image of the day
		# set the image to the image of the day

		# set self.detected image to _ for shape of the day, update the index when it finds the shape to _, when the two match, then drive towards that
		self.desired_center_point = 0
        
		
		#for obj in objects.object_list:
			#print("x_min: " + str(obj.bounding_box_2d[0][0]))
			#print("x_max: " + str(obj.bounding_box_2d[1][0]))
			#print("Distance: " + str(abs((obj.position[2]))))
			#print("Object Label: " + str(obj.raw_label))

	# Determines if red and green buoys are detected then puts them in two seperate arrays (red_buoy_list and green_buoy_list)
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
    
    def sort_triangle(self):
        if self.green_triangle_detected == False:
            print("Error: No triangle detected.")
        else:
            # Find the triangle with closest distance
            triangle_distances = []
            for triangle in self.green_triangle_list:
                triangle_distances.append(abs((triangle.position[2])))
            triangle_distances.sort()
			i = 0
            for triangle in self.green_triangle_list:
                if abs(triangle.position[2]) == triangle_distances[0]
                    self.nearest_triangle_index = i
                    self.nearest_green_triangle_detected = True
                i = i + 1

    def sort_square(self):
		if self.red_square_detected == False:
		 	print("Error: No square detected.")
		else:
			# Find the square with closest distance
			square_distances = []
			for square in self.red_square_list:
				square_distances.append(abs((square.position[2])))
			square_distances.sort()
			i = 0
			for square in self.red_square_list:
				if abs(square.position[2]) == square_distances[0]
					self.nearest_triangle_index = i
					self.nearest_red_square_detected = True
				i = i + 1

    def sort_circle(self):
		if self.blue_circle_detected == False:
		 	print("Error: No circle detected.")
		else:
			# Find the circle with closest distance
			circle_distances = []
			for circle in self.blue_circle_list:
				circle_distances.append(abs((circle.position[2])))
			square_distances.sort()
			i = 0
				if abs(circle.position[2]) == circle_distances[0]
					self.nearest_blue_circle_index = i
					self.nearest_blue_circle_detected = True
				i = i + 1
    def sort_blue_plus(self):
		if self.blue_plus_detected == False:
			print("Error: No blue plus detected.")
		else:
			# Find the blue plus with the closest distance
			blue_plus_distances = []
			for blue_plus in self.blue_plus_list:
				blue_plus_distances.append(abs((blue_plus.position[2])))
			blue_plus.sort()
			i = 0
				if abs(blue_plus.position[2]) == blue_plus_distances[0]
			       self.nearest_blue_plus_index == i
				   self.nearest_blue_plus_detected = True
				i = i + 1
	def sort_green_plus(self):
		if self.green_plus_detected == False:
			print("Error: No green plus detected.")
		else:
			# Find the green plus with the closest distance
			green_plus_distances = []
			for green_plus in self.green_plus_list:
				green_plus_distances.append(abs((green_plus.position[2])))
			green_plus.sort()
			i = 0
				if abs(green_plus.position[2]) == green_plus_distances[0]
			       self.nearest_green_plus_index == i
				   self.nearest_green_plus_detected = True
				i = i + 1
	def sort_red_plus(self):
		if self.red_plus_detected == False:
			print("Error: No red plus detected.")
		else:
			# Find the red plus with the closest distance
			red_plus_distances = []
			for red_plus in self.red_plus_list:
				red_plus_distances.append(abs((green_plus.position[2])))
			red_plus.sort()
			i = 0
				if abs(red_plus.position[2]) == red_plus_distances[0]
			       self.nearest_red_plus_index == i
				   self.nearest_red_plus_detected = True
				i = i + 1
	def sort_duck(self):
		if self.duck == False:
		    print("Error: No duck detected.")
		else:
			# Find the duck with the closest distance
			duck_distances = []
			for duck in self.duck_list:
				duck_distances.append(abs((duck.position[2])))
			duck.sort()
			i = 0
				if abs(duck.position[2]) == duck_distances[0]
				   self.nearest_duck_index == i
				   self.nearest_duck_detected == True
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
	def get_nearest_circle
	
	# Finds what pixel is at the center of the green and red buoys
	def find_center_point(self):
		match self.image_of_the_day
		case 1 # green triangle
			self.center_point = round((self.get_nearest_triangle().bounding_box_2d[1][0] + self.get_nearest_triangle().bounding_box_2d[0][0])/2)
		case 2 # red square
			self.center_point = round((self.get_nearest_square().bounding_box_2d[1][0] + self.get_nearest_square().bounding_box_2d[0][0])/2)
		case 3 # blue circle
			self.center_point = round((self.get_nearest_circle().bounding_box_2d[1][0] + self.get_nearest_circle().bounding_box_2d[0][0])/2)
		case 4 # blue plus
			self.center_point = round((self.get_nearest_blue_plus().bounding_box_2d[1][0] + self.get_nearest_blue_plus().bounding_box_2d[0][0])/2)
		case 5 # red plus
			self.center_point = round((self.get_nearest_red_plus().bounding_box_2d[1][0] + self.get_nearest_red_plus().bounding_box_2d[0][0])/2)
		case 6 # green plus
			self.center_point = round((self.get_nearest_green_plus().bounding_box_2d[1][0] + self.get_nearest_green_plus().bounding_box_2d[0][0])/2)
		case 7 # duck
			self.center_point = round((self.get_nearest_duck().bounding_box_2d[1][0] + self.get_nearest_green_plus().bounding_box_2d[0][0])/2)
			

# Takes in list of objects from Zed 2i Camera each frame
def set_objects(objects_in):
	objects = ZedObjects(objects_in)
	objects.detect_buoys()
	objects.sort_green_buoys()
	objects.sort_red_buoys()
	print("Center Point: " + str(objects.find_center_point()))
	move_to_center(objects.find_center_point())


# Adjusts moters to ensure the pixel center point of the green and red buoys lines up with the center pixel of the image (640)
def move_to_center(center_point):
	zed_center_pixel = 1280/2

	if center_point == -1:
	# Go straight slowly if buoy channel not detected
		thrusters.changeSpeed(1425, 1425)
    # Turn to the left when on the right side of channel
	elif center_point <= zed_center_pixel - 20:
		thrusters.changeSpeed(1400, 1300)
	# Turn to the right when on left side of channel
	elif center_point >= zed_center_pixel + 20:
		thrusters.changeSpeed(1300, 1400)
	else:
	# Go forward if within 20 pixels of center channel
		thrusters.changeSpeed(1400, 1400)
		# speed controller

def match_speed(distance_away):
	goal_distance = 1 # distance we want to be in meters
	if goal_distance*3 >= distance_away
		thruster.changeSpeed(1400,1400)
	elif goal_distance*2 >= distance_away
		thruster.changeSpeed(1425,1425)
	elif goal_distance*1.5 >= distance_away
		thruster.changeSpeed(1450,1450)
	elif goal_distance*1.1 >= distance_away or goal_distance*0.9 <= distance_away
		thruster.changeSpeed(1500+10*(goal_distance-distance_way),1500+10*(goal_distance-distance_away))
	else




## Sudo code for task 3
# drive straight
# aquire image of the day based on set variables (blue vs green, square vs triangle)
    #scan back and forth, so slowly rotate back and forth
    #aquire the correct image based on the defined stuff
# use the move to center controller logic, keep the image in the center
# use new speed controller to control speed as you get closer
# once 3(?) feet away from dock, do not get any closer
