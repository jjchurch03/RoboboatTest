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

#imports for ROS 2
import rclpy
from geometry_msgs.msg import Twist

linear_vel = 0.0
angular_vel = 0.0

# existing code for Main Control

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
		
    def receive_twist_message(self, twist_msg):
        # Extract linear and angular velocities from Twist message
        linear_vel = twist_msg.linear.x
        angular_vel = twist_msg.angular.z

        

thrusters = Thrusters(1500, 1500)
time.sleep(5)
thrusters.changeSpeed(1350, 1350)

def main():
    # Create subscriber to receive Twist messages
    def twist_callback(msg):
        thrusters.receive_twist_message(msg)
    subscriber = node.create_subscription(Twist, 'cmd_vel', twist_callback, 10)

    # Spin ROS 2 node
    rclpy.spin(node)
	

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
	rclpy.init()
    node = rclpy.create_node('thruster_control_node')
    # Create subscriber to receive Twist messages
    def twist_callback(msg):
        thrusters.receive_twist_message(msg)
    subscriber = node.create_subscription(Twist, 'cmd_vel', twist_callback, 10)
    # Spin ROS 2 node
    rclpy.spin(node)
	print("Desired Center Point: " + str(objects.find_desired_center_point()))
	move_to_center(objects.find_desired_center_point())

def move_to_center(desired_center_point):
	zed_center_pixel = 1280/2
	if angular_vel is 0.0:
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
	else:
        if angular_vel == 0.5:
			thrusters.changeSpeed(1400, 1300)
		else:
			thrusters.changeSpeed(1300, 1400)
	angular_vel == 0.0
	linear_vel == 0.0


