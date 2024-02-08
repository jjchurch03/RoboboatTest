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

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan

# # Initial GPIO Setup
# GPIO.setmode(GPIO.BOARD)
# GPIO.setup(in12, GPIO.OUT, initial=GPIO.LOW)
# GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
# GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)




# Define a class for the obstacle avoidance behavior
class ObstacleAvoidance(Node):
    def __init__(self):
        # Initialize the Node with a name 'obstacle_avoidance_node'
        super().__init__('obstacle_avoidance_node')

        # Create a subscription to the 'scan' topic, which receives LaserScan messages
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)


        # Set threshold values for obstacle detection and initialize num_readings
        self.min_distance_threshold = 1.65
        self.front_obstacle_threshold = 1.65
        self.num_readings = 0

    # Callback function for handling LaserScan messages
    def scan_callback(self, msg):
        distances = msg.ranges
        min_distance = min(distances)
        self.num_readings = len(distances)

        # Check if an obstacle is detected based on the minimum distance
        if min_distance < self.min_distance_threshold:
            print("Obstacle Detected! Deciding best course of action...")
            # Call the avoid_obstacle method to determine the action to take
            self.avoid_obstacle(distances, msg)
        else:
            print("Moving Forward...")
            # If no obstacle, move forward
            #move_forward()

    # Method to handle obstacle avoidance logic
    def avoid_obstacle(self, distances, msg):
        closest_index = distances.index(min(distances))
        num_readings = len(distances)
        angle_increment = msg.angle_increment

        print(f"Calculating Angle... Angle Increment: {angle_increment}")

        # Calculate the angle to the closest obstacle
        angle_to_obstacle = closest_index * angle_increment
        print(f"Angle to Obstacle: {angle_to_obstacle}")

        # Determine the angle ranges for left and right sides
        left_range = slice(0, num_readings // 2)
        right_range = slice(num_readings // 2, num_readings)

            # Calculate the average distances for left and right sides
        avg_left_distance = sum(distances[left_range]) / len(distances[left_range])
        avg_right_distance = sum(distances[right_range]) / len(distances[right_range])

            # Decide which side has more space and turn accordingly
        if avg_left_distance > avg_right_distance:
            print("Best course of action: Turn Right")
            #turn_right()
        else:
            print("Best course of action: Turn Left")
            #turn_left()

# class Thrusters:
# 	# 1500 = neuteral
# 	# 1100 = max ahead
# 	# 1900 = max reverse
# 	p_r = GPIO.PWM(r_thrust_pwm, 50)
# 	p_l = GPIO.PWM(l_thrust_pwm, 50)
# 	# right_speed and left_speed should be initiated at 1500, which is neuteral
# 	def __init__(thrusters, left_speed, right_speed):
# 		thrusters.right_speed = right_speed
# 		thrusters.left_speed = left_speed
# 		thrusters.changeSpeed(left_speed, right_speed)
		
# 	def changeSpeed(thrusters, left_speed, right_speed):
# 		# Change right thruster to set value
# 		thrusters.right_speed = right_speed
# 		thrusters.p_r.start(right_speed/200)
		
# 		# Change left thruster to set value
# 		thrusters.left_speed = left_speed
# 		thrusters.p_l.start(left_speed/200)
		
# 	def stop(thrusters):
# 		thrusters.p_r.stop()
# 		thrusters.p_l.stop()
          
# thrusters = Thrusters(1500, 1500)
# time.sleep(5)
# thrusters.changeSpeed(1350, 1350)


# Main function to initialize the ROS 2 node and run the obstacle avoidance behavior
def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance_node = ObstacleAvoidance()
    rclpy.spin(obstacle_avoidance_node)
    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()

# def turn_left():
#     thrusters.changeSpeed(1400, 1300)

# def turn_right():
#     thrusters.changeSpeed(1300, 1400)

# def move_forward():
#     thrusters.changeSpeed(1425, 1425)



