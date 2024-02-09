# Pin Definitions


# Pin 16: Digital Output - IN1 & IN2 on Relay - Set to Low means Thrusters and Battery are connected
in12 = 16 
# Pin 18: Pulse Width Modulation (PWM) Output - Controls Right Thruster (Grey wire)
r_thrust_pwm = 18
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)
l_thrust_pwm = 15

# Imports
import RPi.GPIO as GPIO # (General-Purpose Input/Output) pins on the back of Jetson
import time             # Provides time-related functions: delays
import pyzed.sl as sl   # used to interface with ZED 2i camera and access its functionalities

# Initial GPIO Setup and control
GPIO.setmode(GPIO.BOARD) # sets the pin numbering mode on jetson to use the physical pin numbers instead of GPIO numbers
GPIO.setup(in12, GPIO.OUT, initial=GPIO.LOW) # initializes Relay inputs to low - connects thrusters to battery if low, dissconnects if high
GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW) # initializes thrusters to low for control later
GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

class Thrusters:
	# 1500 = neuteral
	# 1100 = max ahead
	# 1900 = max reverse
	p_r = GPIO.PWM(r_thrust_pwm, 50) # right thruster's Pulse Width Modulation object
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
thrusters.changeSpeed(1450, 1450) # Slower than original code


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
		
		# for obj in objects.object_list:
		# 	print("x_min: " + str(obj.bounding_box_2d[0][0]))
		# 	print("x_max: " + str(obj.bounding_box_2d[1][0]))
		# 	print("Distance: " + str(abs((obj.position[2]))))
		# 	print("Object Label: " + str(obj.raw_label))

	# Determines if  buoys are detected then puts them into seperate arrays (red_buoy_list, green_buoy_list, red_ball_list, etc...)
	def detect_buoys(self):
		# Fills red_buoy_list, green_buoy_list, red_ball_list, etc...
		for obj in self.objects.object_list:
			if (str(obj.raw_label) == "5") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Will say "green_buoy or whatever the label is for a green buoy"
				self.green_buoys_list.append(obj)
				self.green_buoy_detected = True				
			elif (str(obj.raw_label) == "9") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
				self.red_buoys_list.append(obj)
				self.red_buoy_detected = True
			elif (str(obj.raw_label) == "8") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
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


	# Finds what pixel we want to align the center of our screen with

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



##################################### only black balls in channel detected ##########################			
			if self.nearest_yellow_ball_index == -1 & self.nearest_black_ball_index != -1:
				print("only black ball(s) detected")
				xCenter_black_ball = round((self.get_nearest_black_ball().bounding_box_2d[1][0] + self.get_nearest_black_ball().bounding_box_2d[0][0])/2)

				stbd_gap_width = xCenter_green_ball - xCenter_black_ball						
				port_gap_width = xCenter_black_ball - xCenter_red_ball
				if port_gap_width < stbd_gap_width:
					# 0 = stbd side is greater, move to the right of the yellow ball
					move_port_or_stbd = 0
					print("Departing: move to stbd side of black ball")
					self.desired_center_point = round((xCenter_green_ball + xCenter_black_ball)/2)
				else:
					# 1 = port side is greater, move to the left of the yellow ball
					move_port_or_stbd = 1
					print("Departing: move to port side of black ball")
					self.desired_center_point = round((xCenter_red_ball + xCenter_black_ball)/2)					


##################################### only yellow balls in channel detected ##########################
			elif self.nearest_yellow_ball_index != -1 & self.nearest_black_ball_index == -1:
				print("only yellow ball(s) detected")
				xCenter_yellow_ball = round((self.get_nearest_yellow_ball().bounding_box_2d[1][0] + self.get_nearest_yellow_ball().bounding_box_2d[0][0])/2)

				stbd_gap_width = xCenter_green_ball - xCenter_yellow_ball						
				port_gap_width = xCenter_yellow_ball - xCenter_red_ball
				if port_gap_width < stbd_gap_width:
					# 0 = stbd side is greater, move to the right of the yellow ball
					move_port_or_stbd = 0
					print("Departing: move to stbd side of yellow ball")
					self.desired_center_point = round((xCenter_green_ball + xCenter_yellow_ball)/2)					
				else:
					# 1 = port side is greater, move to the left of the yellow ball
					move_port_or_stbd = 1
					print("Departing: move to port side of yellow ball")
					self.desired_center_point = round((xCenter_red_ball + xCenter_yellow_ball)/2)					



################################# Both Yellow and Black Balls in the channel #################################
			elif self.nearest_yellow_ball != -1 & self.nearest_black_ball != -1:
				print("black and yellow obsticles detected")
				xCenter_yellow_ball = round((self.get_nearest_yellow_ball().bounding_box_2d[1][0] + self.get_nearest_yellow_ball().bounding_box_2d[0][0])/2)
				xCenter_black_ball = round((self.get_nearest_black_ball().bounding_box_2d[1][0] + self.get_nearest_black_ball().bounding_box_2d[0][0])/2)

				#if yellow ball is closer than black ball:
				if self.get_nearest_yellow_ball().dist < self.get_nearest_black_ball().dist: 
				# if yellow ball is in the channel...
					if xCenter_yellow_ball < xCenter_green_ball & xCenter_yellow_ball > xCenter_red_ball:
						stbd_gap_width = xCenter_green_ball - xCenter_yellow_ball						
						port_gap_width = xCenter_yellow_ball - xCenter_red_ball
						if port_gap_width < stbd_gap_width:
							# 0 = stbd side is greater, move to the right of the yellow ball
							move_port_or_stbd = 0
							print("Departing: move to stbd side of yellow ball")
							self.desired_center_point = round((xCenter_green_ball + xCenter_yellow_ball)/2)							
						else:
							# 1 = port side is greater, move to the left of the yellow ball
							move_port_or_stbd = 1
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
							print("Departing: move to stbd side of black ball")
							self.desired_center_point = round((xCenter_green_ball + xCenter_black_ball)/2)							
						else:
							# 1 = port side is greater, move to the left of the yellow ball
							move_port_or_stbd = 1
							print("Departing: move to port side of black ball")
							self.desired_center_point = round((xCenter_red_ball + xCenter_black_ball)/2)			


############################ No obstacle balls in the channel ################################											
			else:
				print("no obstacle ball index detected")
				self.desired_center_point = self.channel_center_point

			return self.desired_center_point
			

# Takes in list of objects from Zed 2i Camera each frame
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


# Adjusts moters to ensure the pixel center point of the green and red buoys lines up with the center pixel of the image (640)
def move_to_center(desired_center_point):
	zed_center_pixel = 1280/2

	if desired_center_point == -1:
	# Go straight slowly if buoy channel not detected
		thrusters.changeSpeed(1425, 1425)
    # Turn to the left when on the right side of channel
	elif desired_center_point <= zed_center_pixel - 20:
		thrusters.changeSpeed(1400, 1300)
	# Turn to the right when on left side of channel
	elif desired_center_point >= zed_center_pixel + 20:
		thrusters.changeSpeed(1300, 1400)
	else:
	# Go forward if within 20 pixels of center channel
		thrusters.changeSpeed(1400, 1400)


def test_motors():
	# Initialize the thrusters in neuteral
	print("Neuteral Thrusters")
	thrusters = Thrusters(1500, 1500)
	time.sleep(10)
	
	# Standard Foward
	print("Standard Forward")
	thrusters.changeSpeed(1650, 1650)
	time.sleep(10)
	
	# Standard Reverse
	print("Standard Reverse")
	thrusters.changeSpeed(1350, 1350)
	time.sleep(10)
	
	# Disconnect
	print("Stop Thrusters")
	thrusters.stop()
	
	GPIO.cleanup()




    	
