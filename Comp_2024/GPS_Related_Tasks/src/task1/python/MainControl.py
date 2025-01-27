# Pin Definitions

#Initialization Pins
# Pin 16: Dig Output - IN1 & IN2 on Relay - Set to Low means Thrusters and Battery are connected #16OCT having ripped the wires, how does this now apply?
in12 = 16 
# Pin 18: PWM Output - Controls Right Thruster (Grey wire) 14OCT I AM THE JETSON PIN TO WRITE TO
r_thrust_pwm = 18 
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)
l_thrust_pwm = 15

# Imports
import RPi.GPIO as GPIO
import time
import pyzed.sl as sl #16OCT for ZED  for object detecting
# import rclpy
# from vectornav_msgs.msg import GpsGroup
# from sensor_msgs.msg import NavSatFix

# # global variable to store GPS data
# latitude = None
# longitude = None

# Initial GPIO Setup
GPIO.setmode(GPIO.BOARD) #17OCT pin numbering should follow physical pin layout
GPIO.setup(in12, GPIO.OUT, initial=GPIO.LOW) #14OCT set the pins as outputs and start them as low
GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW) 
GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

class Thrusters:
	# 1500 = neuteral
	# 1100 = max ahead
	# 1900 = max reverse 
	# 14OCT The GPIO.PWM method (method is function declared in class) allows a specific PWM to be sent out from a pin
	p_r = GPIO.PWM(r_thrust_pwm, 50)  #14OCT arguments are (PIN, frequency); this variable is used to adjust thruster speed to be controlled with PWM
	p_l = GPIO.PWM(l_thrust_pwm, 50)
	# right_speed and left_speed should be initiated at 1500, which is neuteral
	
	def __init__(thrusters, left_speed, right_speed): #18OCT constructor; called when you create a new instance of the class 
		thrusters.right_speed = right_speed 
		thrusters.left_speed = left_speed
		thrusters.changeSpeed(left_speed, right_speed) #THIS

	#IS HERE	
	def changeSpeed(thrusters, left_speed, right_speed): #16OCT thrusters refers to current instance of class (an instance is object created from class); gives access to other things like thrusters.p_r and thrusters.p_l
		# Change right thruster to set value 
		thrusters.right_speed = right_speed
		thrusters.p_r.start(right_speed/200)   # 14OCT thrusters.p_r:the start method is called to begin sending a "duty cycle" or how much power to supply to thruster
		
		# Change left thruster to set value
		thrusters.left_speed = left_speed
		thrusters.p_l.start(left_speed/200)     
	
	#22OCT24 THIS WOULD WORK TOO:
	#def changeSpeed(thrusters):  # No need for parameters here
    # Use the already set values from the instance
    #thrusters.p_r.start(thrusters.right_speed / 200)   # Use the stored right_speed
    #thrusters.p_l.start(thrusters.left_speed / 200)    # Use the stored left_speed

	def stop(thrusters):
		thrusters.p_r.stop()
		thrusters.p_l.stop()
	#16OCT example use thruster_obj.changeSpeed(1600, 1400)

# def callback(msg):
#     global latitude, longitude
#     if latitude is None:
#         # Grab the first set of information
#         latitude = msg.latitude
#         longitude = msg.longitude
#         print(f"Received first set of information: {latitude}")
#         print(f"Received second set of information: {longitude}")

#         # Unsubscribe after receiving the first message
#         node.get_logger().info('Unsubscribing from the topic...')
#         subscription.destroy()
#     if longitude is None:
#         print("Failed to grab longitude information.")
#     if latitude is None:
#         print("Failed to grab latitude information")

# def ros():
#     rclpy.init()
#     node = rclpy.create_node('task1_start')  # node is named here
#     subscription = node.create_subscription(NavSatFix, 'vectornav/gnss', callback, 10)  # Adjust the queue size as needed
#     node.destroy_node()



# Initialize the thrusters into neutral then set them to go straight forward
thrusters = Thrusters(1500, 1500)
time.sleep(5)
thrusters.changeSpeed(1350, 1350)


# 14OCT Takes in Zed Objects, which contains info on distance, bounding box position, etc.
class ZedObjects:
	def __init__(self, objects): #14OCT constructor; called when you create a new instance of the class; objects is passed in itilializiation
		self.objects = objects #14OCT self.objects can be accessed by other methods in the class, allowing those methods to operate on the data passed during the initialization.
		self.green_buoys_list = []
		self.red_buoys_list = []         # Holds all zed objects in the frame that are green buoys in an empty list
		self.green_buoy_detected = False
		self.red_buoy_detected = False
		self.nearest_green_detected = False
		self.nearest_red_detected = False
		self.nearest_green_index = -1 #14OCT24 Initialize as an index that doesn't exist
		self.nearest_red_index = -1
		self.center_point = 0
		
		#for obj in objects.object_list:
			#print("x_min: " + str(obj.bounding_box_2d[0][0]))
			#print("x_max: " + str(obj.bounding_box_2d[1][0]))
			#print("Distance: " + str(abs((obj.position[2]))))
			#print("Object Label: " + str(obj.raw_label))

	# 14OCT Determines if red and green buoys are detected then puts them in two seperate arrays (red_buoy_list and green_buoy_list)
	def detect_buoys(self):
		# Fills red_buoy_list and green_buoy_list
		for obj in self.objects.object_list:   #object_list IS PASSED FROM DETECTOR FUNCTION and the actual list of objects
			#and self.objects is defined in method above
			if (str(obj.raw_label) == "0") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): #14OCT if an green buoy is detected (index==0 from ZED) add it to the list
				self.green_buoys_list.append(obj) #14OCT green is indexed 0 by the camera
				self.green_buoy_detected = True
			elif (str(obj.raw_label) == "2") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
				self.red_buoys_list.append(obj) #14OCT red is indexed as 2 by the camera
				self.red_buoy_detected = True

	#14OCT calculates distances to nearest buoys for all green buoys insight. it then reoders the detected buoys by distance
	def sort_green_buoys(self):
		if self.green_buoy_detected == False:
			print("Error: No green buoys detected.")
		else:
			# Find green buoy with closest distance
			green_distances = [] #16OCT create empty list for green buoy distances
			for green_buoy in self.green_buoys_list: #15OCT green buoy is just a placeholder for each green buoy in list
				green_distances.append(abs((green_buoy.position[2])))  #14OCT 2 is the z-axis component; this starts empty
			green_distances.sort()  #15OCT sort the distances from smallest to greatest to grab smallest in section below
			i = 0
			
			for green_buoy in self.green_buoys_list: #15OCT for every buoy detected
				if abs(green_buoy.position[2]) == green_distances[0]: #15OCT this line compares the distances of every buoy [2] to the smallest distance [0] recorded in distances
					self.nearest_green_index = i  #!!!!!!!!!
					self.nearest_green_detected = True
				i = i + 1  #iterate through all the different green buoys in the list until the closest green buoy is found
	
	#14OCT same as green buoys but red
	def sort_red_buoys(self):
		if self.red_buoy_detected == False:
			print("Error: No red buoys detected.")
		else:
			# Find red buoy with closest distance
			red_distances = []
			for red_buoy in self.red_buoys_list:
				red_distances.append(abs((red_buoy.position[2])))
			red_distances.sort()
			i = 0 #22OCT24 intializes index i
			for red_buoy in self.red_buoys_list:
				if abs(red_buoy.position[2]) == red_distances[0]:
					self.nearest_red_index = i
					self.nearest_red_detected = True
				i = i + 1
	#22OCT SEPERATING SORT AND GET ARE REDUNDANT, SORT DOES NOT RETURN ANYTHING AND IS USED AS AN INTERMEDIARY FNCTION
	def get_nearest_green_buoy(self):
		if self.green_buoy_detected == False:
			print("Error: No green buoys detected.")
		elif self.nearest_green_detected == False:
			print("Error: Nearest green buoy not yet detected.")
		else:
			return self.green_buoys_list[self.nearest_green_index]         #!!!!!!!!!
		
	def get_nearest_red_buoy(self):
		if self.red_buoy_detected == False:
			print("Error: No red buoys detected.")
		elif self.nearest_red_detected == False:
			print("Error: Nearest red buoy not yet detected.")
		else:
			return self.red_buoys_list[self.nearest_red_index]
	
	# Finds what pixel is at the center of the green and red buoys
	def find_center_point(self):
		if self.nearest_green_index == -1:
			print("Error: Issue with green index")
			return -1
		elif self.nearest_red_index == -1:
			print("Error: Issue with red index")
			return -1
		else:
			xmin_green = self.get_nearest_green_buoy().bounding_box_2d[0][0] #16OCT take in the bottom left corner of the nearest green
			xmax_red = self.get_nearest_red_buoy().bounding_box_2d[1][0] #16OCT take in the bottom right corner of the nearest red
			self.center_point = round((xmin_green + xmax_red)/2) #16OCT calculate the average
			return self.center_point #14OCT center point calculated
			
#16OCT we are no longer within the ZedObjects Class??

# Takes in list of objects from Zed 2i Camera each frame
def set_objects(objects_in): #18OCT objects_in is passed from detector.py
	objects = ZedObjects(objects_in) #16OCT create an instance of the class ZedObjects CALLED objects, using objects_in as argument
	objects.detect_buoys() #16OCT everything is preceeded by objects because we are now referencing the objects instance ITS NOT self. anymore
	objects.sort_green_buoys()
	objects.sort_red_buoys()
	print("Center Point: " + str(objects.find_center_point()))
	move_to_center(objects.find_center_point()) #15OCT call movetocenter point based on calculated center point









# Adjusts moters to ensure the pixel center point of the green and red buoys lines up with the center pixel of the image (640)
#22OCT its easier to keep this function outside of any classes because it takes the output of a function as an argument above
def move_to_center(center_point):
	zed_center_pixel = 1280/2

	if center_point == -1:
	# 15OCT Go straight slowly if buoy channel not detected
		thrusters.changeSpeed(1425, 1425)
    
	# 15OCT Turn to the left when on the right side of channel
	elif center_point <= zed_center_pixel - 20:
		thrusters.changeSpeed(1400, 1300)
	
	# 15OCT Turn to the right when on left side of channel
	elif center_point >= zed_center_pixel + 20:
		thrusters.changeSpeed(1300, 1400)

	# 15OCT Go forward if within 20 pixels of center channel	
	else:
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

#if __name__ == '__main__':
    # try:
    #     ros()
    #     rclpy.spin(node)
    # except KeyboardInterrupt:
    #     pass
    # finally:
	
    # thrusters.stop()
    # #rclpy.shutdown()
    # GPIO.cleanup()

