#OA_v2

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


# Constants
MIN_DISTANCE_THRESHOLD = 1.65
FRONT_OBSTACLE_THRESHOLD = 1.65

# # Initial GPIO Setup
# GPIO.setmode(GPIO.BOARD)
# GPIO.setup(in12, GPIO.OUT, initial=GPIO.LOW)
# GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
# GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

# Define a class for the obstacle avoidance behavior
class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)

        # Set minimum distance threshold for obstacle detection
        self.min_distance_threshold = MIN_DISTANCE_THRESHOLD  
        
        # Initialize the number of laser scan readings
        self.num_readings = 0  

    def scan_callback(self, msg):
        distances = msg.ranges

        # Find the minimum distance from the laser scan readings
        min_distance = min(distances) 

        # Update the number of laser scan readings
        self.num_readings = len(distances)  
        if min_distance < self.min_distance_threshold:
            print("Obstacle Detected! Deciding best course of action...")

            # Call method to handle obstacle avoidance
            self.avoid_obstacle(distances, msg)  
        else:
            print("Moving Forward...")
            # If no obstacle, move forward
            # move_forward()

    def avoid_obstacle(self, distances, msg):
        # Find the index of the closest obstacle
        closest_index = distances.index(min(distances))  
        num_readings = len(distances)

        # Get the angle increment of laser scan readings
        angle_increment = msg.angle_increment  
        print(f"Calculating Angle... Angle Increment: {angle_increment}")

        # Calculate angle to the closest obstacle
        angle_to_obstacle = closest_index * angle_increment  
        print(f"Angle to Obstacle: {angle_to_obstacle}")

        # Define the range for the left side and right side of laser scan readings
        left_range = slice(0, num_readings // 2)  
        right_range = slice(num_readings // 2, num_readings)  

        # Calculate average distance on the left and right side
        avg_left_distance = sum(distances[left_range]) / len(distances[left_range])  
        avg_right_distance = sum(distances[right_range]) / len(distances[right_range])

        #Based on objects around the vessel make a decision
        if avg_left_distance > avg_right_distance:
            print("Best course of action: Turn Right")
            # turn_right()
        else:
            print("Best course of action: Turn Left")
            # turn_left()


def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance_node = ObstacleAvoidance()
    rclpy.spin(obstacle_avoidance_node)
    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()

# class Thrusters:
#     def __init__(self, left_speed, right_speed):
#         self.right_speed = right_speed
#         self.left_speed = left_speed
#         self.change_speed(left_speed, right_speed)
        
#     def change_speed(self, left_speed, right_speed):
#         self.right_speed = right_speed
#         self.p_r.start(right_speed / 200)
#         self.left_speed = left_speed
#         self.p_l.start(left_speed / 200)
        
#     def stop(self):
#         self.p_r.stop()
#         self.p_l.stop()

# thrusters = Thrusters(1500, 1500)
# time.sleep(5)
# thrusters.change_speed(1350, 1350)

# def turn_left():
#     thrusters.change_speed(1400, 1300)

# def turn_right():
#     thrusters.change_speed(1300, 1400)

# def move_forward():
#     thrusters.change_speed(1425, 1425)

if __name__ == '__main__':
    main()
