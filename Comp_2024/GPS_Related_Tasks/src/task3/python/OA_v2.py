import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import numpy as np


# Constants
MIN_DISTANCE_THRESHOLD = 1.65
SAFE_FORWARD_DISTANCE = 0.5


# Define a class for the obstacle avoidance behavior
class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)

        # Set minimum distance threshold for obstacle detection
        self.min_distance_threshold = MIN_DISTANCE_THRESHOLD  
        
        # Initialize the number of laser scan readings
        self.num_readings = 0  

        # Define left and right range for laser scan readings
        self.left_range = None
        self.right_range = None

        self.obstacle_distances = []

    def scan_callback(self, msg):
        distances = msg.ranges
        self.obstacle_distances = [x for x in distances if not np.isnan(x)]

        # Find the minimum distance from the laser scan readings
        min_distance = min(self.obstacle_distances) 

        # Update the number of laser scan readings
        self.num_readings = len(self.obstacle_distances)  

        if min_distance < self.min_distance_threshold:
            print("Obstacle Detected! Deciding best course of action...")
            # Call method to handle obstacle avoidance
            self.avoid_obstacle(self.obstacle_distances, msg)  
        else:
            print("Moving Forward...")
            # If no obstacle within a certain range, move forward
            if min_distance > SAFE_FORWARD_DISTANCE:
                # Move forward
                pass
            else:
                print("Obstacle too close, cannot move forward.")


    def avoid_obstacle(self, distances, msg):
        # Print laser scan data for debugging
        print("Distances:", distances)
        print("Left Range:", self.left_range)
        print("Right Range:", self.right_range)

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

        # Print average distances for debugging
        print("Average Left Distance:", avg_left_distance)
        print("Average Right Distance:", avg_right_distance)

        #Based on objects around the vessel make a decision
        if avg_left_distance > avg_right_distance:
            print("Best course of action: Turn Left")
        else:
            print("Best course of action: Turn Right")


def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance_node = ObstacleAvoidance()
    rclpy.spin(obstacle_avoidance_node)
    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

