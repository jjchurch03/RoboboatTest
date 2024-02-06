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

# Initial GPIO Setup
GPIO.setmode(GPIO.BOARD)
GPIO.setup(in12, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

print("initializing thrusters")	
duck_counter = 0
	

 # Takes in Zed Objects, which contains info on distance, bounding box position, etc.
class ZedObjects:
	def __init__(self, objects):
		self.objects = objects

        # Holds all zed objects in the frame that are green buoys
		self.red_ball_list = []
		self.green_ball_list = []
		self.yellow_ball_list = []

		self.red_ball_detected = False
		self.green_ball_detected = False
		self.yellow_ball_detected = False
		
		self.nearest_red_ball_detected = False
		self.nearest_green_ball_detected = False
		self.nearest_yellow_ball_detected = False

		self.nearest_red_ball_index = -1
		self.nearest_green_ball_index = -1
		self.nearest_yellow_ball_index = -1

		self.desired_center_point = 0

		duck_counter = 0
		
		#for obj in objects.object_list:
			#print("x_min: " + str(obj.bounding_box_2d[0][0]))
			#print("x_max: " + str(obj.bounding_box_2d[1][0]))
			#print("Distance: " + str(abs((obj.position[2]))))
			#print("Object Label: " + str(obj.raw_label))

	# Determines if  buoys are detected then puts them into seperate arrays (red_buoy_list, green_buoy_list, red_ball_list, etc...)
	def detect_buoys(self):
		
		# Fills red_buoy_list, green_buoy_list, red_ball_list, etc...
		for obj in self.objects.object_list:
			if (str(obj.raw_label) == "9") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
				self.red_ball_list.append(obj)
				self.red_ball_detected = True	
			elif (str(obj.raw_label) == "5") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
				self.green_ball_list.append(obj)
				self.green_ball_detected = True		
			elif (str(obj.raw_label) == "12") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
				self.yellow_ball_list.append(obj)
				self.yellow_ball_detected = True
				#duck_counter = duck_counter + 1
				#print("Ducks... Quack count: " + str(duck_counter))				
																
	
	# If present, finds the nearest of each type of buoy

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
			if xCenter_red_ball < xCenter_green_ball:
				# red on left, green on right: vessel is "departing" 
				return_or_depart = 0
			else:
				# red, right, returning
				return_or_depart = 1

			if self.nearest_yellow_ball_index == -1:
				print("no obstacle ball index detected")
				self.desired_center_point = self.channel_center_point
				return self.desired_center_point
			else:
				############### look into if you dont have both
				xCenter_yellow_ball = round((self.get_nearest_yellow_ball().bounding_box_2d[1][0] + self.get_nearest_yellow_ball().bounding_box_2d[0][0])/2)
				
				# red on left, green on right...
				if return_or_depart == 0:
					# if yellow ball is in the channel...
						if xCenter_yellow_ball < xCenter_green_ball & xCenter_yellow_ball > xCenter_red_ball:
							stbd_gap_width = xCenter_green_ball - xCenter_yellow_ball						
							port_gap_width = xCenter_yellow_ball - xCenter_red_ball
							if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
								print("Departing: move to stbd side of yellow ball")
								self.desired_center_point = round((xCenter_green_ball + xCenter_yellow_ball)/2)
							else:
								# 1 = port side is greater, move to the left of the yellow ball
								print("Departing: move to port side of yellow ball")
								self.desired_center_point = round((xCenter_red_ball + xCenter_yellow_ball)/2)
								
					
				# red on right, green on left					
				else:
					# if yellow ball is in the channel...
						if xCenter_yellow_ball > xCenter_green_ball & xCenter_yellow_ball < xCenter_red_ball:
							stbd_gap_width = xCenter_red_ball - xCenter_yellow_ball						
							port_gap_width = xCenter_yellow_ball - xCenter_green_ball
							if port_gap_width < stbd_gap_width:
								# 0 = stbd side is greater, move to the right of the yellow ball
								print("Returning: move to stbd side of yellow ball")
								self.desired_center_point = round((xCenter_red_ball + xCenter_yellow_ball)/2)
							else:
								# 1 = port side is greater, move to the left of the yellow ball
								print("Returning: move to port side of yellow ball")
								self.desired_center_point = round((xCenter_green_ball + xCenter_yellow_ball)/2)
														
					
				return self.desired_center_point
			

# Takes in list of objects from Zed 2i Camera each frame
def set_objects(objects_in):
	objects = ZedObjects(objects_in)
	objects.detect_buoys()
	objects.sort_red_ball()
	objects.sort_green_ball()
	objects.sort_yellow_ball()
	print("Desired Center Point: " + str(objects.find_desired_center_point()))
	move_to_center(objects.find_desired_center_point())


# Adjusts moters to ensure the pixel center point of the green and red buoys lines up with the center pixel of the image (640)
def move_to_center(desired_center_point):
	zed_center_pixel = 1280/2

	if desired_center_point == -1:
	# Go straight slowly if buoy channel not detected
		print("no channel, go straight slowly")
    # Turn to the left when on the right side of channel
	elif desired_center_point <= zed_center_pixel - 20:
		print("turn left")
	# Turn to the right when on left side of channel
	elif desired_center_point >= zed_center_pixel + 20:
		print("turn right")
	else:
	# Go forward if within 20 pixels of center channel
		print("move forward through channel")




    	
