import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import time
import math

class DockAvoidance(Node):
    def __init__(self):
        super().__init__('dock_avoidance')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.lidar_callback, 10)
        self.subscription  # prevent unused variable warning

    def lidar_callback(self, msg):
        # Define threshold distance for detecting docks (in meters)
        dock_threshold_distance = 1.0

        # Calculate the number of scan points in the left and right regions
        num_points = len(msg.ranges)
        mid_index = num_points // 2
        left_region = msg.ranges[:mid_index]
        right_region = msg.ranges[mid_index:]

        # Check if there are docks in the left region
        left_dock_detected = any(distance < dock_threshold_distance for distance in left_region)

        # Check if there are docks in the right region
        right_dock_detected = any(distance < dock_threshold_distance for distance in right_region)

        # If docks are detected on either side, take evasive action
        if left_dock_detected or right_dock_detected:
            self.avoid_collision(left_dock_detected, right_dock_detected)


    def avoid_collision(self, left_dock_detected, right_dock_detected):
        # If there is no dock detected too close, do nothing (don't change thruster speeds)
        if not (left_dock_detected or right_dock_detected):
            return

        # Stop the vessel to allow for adjustment
        self.stop_due_to_proximity()

        # Implement logic to make a turn based on the detected dock
        if left_dock_detected:
            self.make_turn(-math.pi / 6)  # Example: Make a left turn of 30 degrees (pi/6 radians)
        elif right_dock_detected:
            self.make_turn(math.pi / 6)   # Example: Make a right turn of 30 degrees (pi/6 radians)


    def stop_due_to_proximity(self):
        self.thrusters.change_speed(1900, 1900)  # Set thruster speeds for reverse movement
        time.sleep(0.5)  # Adjust sleep time as needed to ensure complete stop
        self.thrusters.stop()  # Stop the thrusters to hold the vessel in place

    def stop_due_to_turn(self):
        self.thrusters.change_speed(1500, 1500)  # Set thruster speeds to neutral
        time.sleep(0.5)  # Adjust sleep time as needed to ensure complete stop
        self.thrusters.stop()  # Stop the thrusters to hold the vessel in place


    def make_turn(self, steering_angle):
        # Define parameters for turning
        turn_duration = 2.0  # Duration for making the turn (in seconds)
        turn_speed = 1400    # Speed of thrusters during turn

        # Calculate the change in speed for each thruster based on the steering angle
        left_speed_change = steering_angle * turn_speed
        right_speed_change = -steering_angle * turn_speed

        # Change thruster speeds gradually to initiate the turn
        self.thrusters.change_speed(1500 + left_speed_change, 1500 + right_speed_change)

    # Wait for the turn to complete
        time.sleep(turn_duration)

    # Stop the vessel after the turn
        self.stop_due_to_turn()

