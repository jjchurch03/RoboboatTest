# Code for Obstacle avoidance
# Pin Definitions
# Pin 18: PWM Output - Controls Right Thruster (Grey wire)
R_THRUST_PWM = 18
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)
L_THRUST_PWM = 15

# Imports
import RPi.GPIO as GPIO
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import numpy as np

# Constants
MIN_DISTANCE_THRESHOLD = 1.65
SAFE_FORWARD_DISTANCE = 0.5

# Initial GPIO Setup
GPIO.setmode(GPIO.BOARD)
GPIO.setup(R_THRUST_PWM, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(L_THRUST_PWM, GPIO.OUT, initial=GPIO.LOW)

class Thrusters:
    def __init__(self, left_speed, right_speed):
        self.p_r = GPIO.PWM(R_THRUST_PWM, 50)
        self.p_l = GPIO.PWM(L_THRUST_PWM, 50)
        self.left_speed = left_speed
        self.right_speed = right_speed
        self.change_speed(left_speed, right_speed)

    def change_speed(self, left_speed, right_speed):
        self.left_speed = left_speed
        self.right_speed = right_speed
        self.p_r.start(right_speed / 200)
        self.p_l.start(left_speed / 200)

    def stop(self):
        self.p_r.stop()
        self.p_l.stop()

# Initialize the thrusters into neutral then set them to go straight forward
thrusters = Thrusters(1500, 1500)
time.sleep(5)
thrusters.change_speed(1350, 1350)

# Define a class for the obstacle avoidance behavior
class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)
        self.min_distance_threshold = MIN_DISTANCE_THRESHOLD
        self.starting_distance = 0.6  # meters
        self.degree_range = 0.98  # radians
        self.left_range = None
        self.right_range = None
        self.obstacle_distances = []

    def scan_callback(self, msg):
        distances = msg.ranges
        self.obstacle_distances = [x for x in distances if not np.isnan(x)]

        if not self.obstacle_distances:
            self.get_logger().info("No valid laser scan data received.")
            return

        start_index = int(self.starting_distance / msg.range_max * len(self.obstacle_distances))
        filtered_distances = self.obstacle_distances[start_index:]

        degree_range_indices = int(self.degree_range / msg.angle_increment)
        path_clear = self.is_path_clear(filtered_distances, degree_range_indices)

        if not path_clear:
            self.avoid_obstacle(filtered_distances, msg)
        else:
            self.get_logger().info("Clear path")
            thrusters.change_speed(1400, 1400)

    def is_path_clear(self, distances, degree_range_indices):
        front_distances = distances[:degree_range_indices]
        back_distances = distances[-degree_range_indices:]

        if min(front_distances) < self.min_distance_threshold or min(back_distances) < self.min_distance_threshold:
            return False
        else:
            return True

    def avoid_obstacle(self, distances, msg):
        closest_index = distances.index(min(distances))
        num_readings = len(distances)
        angle_increment = msg.angle_increment

        angle_to_obstacle = (closest_index - num_readings // 2) * angle_increment

        self.left_range = slice(0, num_readings // 2)
        self.right_range = slice(num_readings // 2, num_readings)

        avg_left_distance = sum(distances[self.left_range]) / len(distances[self.left_range])
        avg_right_distance = sum(distances[self.right_range]) / len(distances[self.right_range])

        if avg_left_distance > avg_right_distance:
            self.get_logger().info("Best course of action: Turn Right")
            thrusters.change_speed(1400, 1300)
        else:
            self.get_logger().info("Best course of action: Turn Left")
            thrusters.change_speed(1300, 1400)

def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance_node = ObstacleAvoidance()
    try:
        rclpy.spin(obstacle_avoidance_node)
    except KeyboardInterrupt:
        pass
    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()
    thrusters.stop()
    GPIO.cleanup()

if __name__ == '__main__':
    main()
