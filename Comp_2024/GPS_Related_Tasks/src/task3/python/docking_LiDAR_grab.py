import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)
        print("Subscription to LiDAR created!")
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        print("Main Control Turn Publisher Created!")
        self.min_distance_threshold = 0.5
        self.front_obstacle_threshold = 0.2  # Set your own threshold for obstacles in front
        self.num_readings = 0  # Initialize num_readings

    def scan_callback(self, msg):
        distances = msg.ranges
        min_distance = min(distances)
        self.num_readings = len(distances)  # Update num_readings

        if min_distance < self.min_distance_threshold:
            print("Obstacle Detected! Deciding best course of action...")
            self.avoid_obstacle(distances, msg)  # Pass msg to the avoid_obstacle method
        else:
            print("Moving Forward...")
            self.move_forward()

    def avoid_obstacle(self, distances, msg):
        closest_index = distances.index(min(distances))
        num_readings = len(distances)
        angle_increment = msg.angle_increment

        print(f"Calculating Angle... Angle Increment: {angle_increment}")

        angle_to_obstacle = closest_index * angle_increment
        print(f"Angle to Obstacle: {angle_to_obstacle}")

        # Check if the obstacle is in front or near the front
        if angle_to_obstacle < self.front_obstacle_threshold:
            print("Obstacle in Front or Near Front! Changing direction...")
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

    # (Remaining code for turn_right, turn_left, and move_forward methods)


# Add new methods for turning right and left
    def turn_right(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.0
        twist_msg.angular.z = -0.5
        self.publisher.publish(twist_msg)

    def turn_left(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.0
        twist_msg.angular.z = 0.5
        self.publisher.publish(twist_msg)


    def move_forward(self):
        twist_msg = Twist()
        twist_msg.linear.x = 0.2
        twist_msg.angular.z = 0.0
        self.publisher.publish(twist_msg)


    def change_direction(self, angle_to_obstacle):
        # Add logic to change the direction based on your requirements
        print("Changing Direction...")
        if angle_to_obstacle < (self.num_readings / 2):
            print("Best course of action: Turn Right")
            self.turn_right()
        else:
            print("Best course of action: Turn Left")
            self.turn_left()

def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance_node = ObstacleAvoidance()
    rclpy.spin(obstacle_avoidance_node)
    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

