import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

# Define a class for the obstacle avoidance behavior
class ObstacleAvoidance(Node):
    def __init__(self):
        # Initialize the Node with a name 'obstacle_avoidance_node'
        super().__init__('obstacle_avoidance_node')

        # Create a subscription to the 'scan' topic, which receives LaserScan messages
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)

        # Create a publisher for sending Twist messages to control the robot's movement
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)

        # Set threshold values for obstacle detection and initialize num_readings
        self.min_distance_threshold = 0.5
        self.front_obstacle_threshold = 0.2
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
            self.move_forward()

    # Method to handle obstacle avoidance logic
    def avoid_obstacle(self, distances, msg):
        closest_index = distances.index(min(distances))
        num_readings = len(distances)
        angle_increment = msg.angle_increment

        print(f"Calculating Angle... Angle Increment: {angle_increment}")

        # Calculate the angle to the closest obstacle
        angle_to_obstacle = closest_index * angle_increment
        print(f"Angle to Obstacle: {angle_to_obstacle}")

        # Check if the obstacle is in front or near the front
        if angle_to_obstacle < self.front_obstacle_threshold:
            print("Obstacle in Front or Near Front! Changing direction...")
            # Change direction based on the angle to the obstacle
            self.change_direction(angle_to_obstacle)
        else:
            # Determine the angle ranges for left and right sides
            left_range = slice(0, num_readings // 2)
            right_range = slice(num_readings // 2, num_readings)

            # Calculate the average distances for left and right sides
            avg_left_distance = sum(distances[left_range]) / len(distances[left_range])
            avg_right_distance = sum(distances[right_range]) / len(distances[right_range])

            # Decide which side has more space and turn accordingly
            if avg_left_distance > avg_right_distance:
                print("Best course of action: Turn Right")
                self.turn_right()
            else:
                print("Best course of action: Turn Left")
                self.turn_left()

    # Method to turn the robot to the right
    def turn_right(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.0
        twist_msg.angular.z = -0.5
        self.publisher.publish(twist_msg)

    # Method to turn the robot to the left
    def turn_left(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.0
        twist_msg.angular.z = 0.5
        self.publisher.publish(twist_msg)

    # Method to move the robot forward
    def move_forward(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.2
        twist_msg.angular.z = 0.0
        self.publisher.publish(twist_msg)

    # Method to change the direction based on the angle to the obstacle
    def change_direction(self, angle_to_obstacle):
        print("Changing Direction...")
        if angle_to_obstacle < (self.num_readings / 2):
            print("Best course of action: Turn Right")
            self.turn_right()
        else:
            print("Best course of action: Turn Left")
            self.turn_left()

# Main function to initialize the ROS 2 node and run the obstacle avoidance behavior
def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance_node = ObstacleAvoidance()
    rclpy.spin(obstacle_avoidance_node)
    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()

# Entry point to start the program
if __name__ == '__main__':
    main()
