import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan,'scan', self.scan_callback,10)
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10) # This is a way to do this. We need to find a way to pass the variable to MainControl
        self.min_distance_threshold = 0.5  # Adjust this threshold as needed

    def scan_callback(self, msg):
        distances = msg.ranges
        min_distance = min(distances)

        if min_distance < self.min_distance_threshold:
            # Obstacle detected, perform obstacle avoidance
            self.avoid_obstacle(distances)
        else:
            # No obstacle, move forward
            self.move_forward()

    def avoid_obstacle(self, distances):
        # Determine the direction of the closest obstacle
        closest_index = distances.index(min(distances))
        num_readings = len(distances)
        angle_increment = msg.angle_increment

        # Calculate the angle of the closest obstacle
        angle_to_obstacle = closest_index * angle_increment

        # Decide whether to turn left or right based on the angle
        if angle_to_obstacle < (num_readings / 2):
            # Turn right
            twist_msg = Twist()
            twist_msg.linear.x = 0.0  # Stop moving forward
            twist_msg.angular.z = -0.5  # Rotate to the right
            self.publisher.publish(twist_msg)
        else:
            # Turn left
            twist_msg = Twist()
            twist_msg.linear.x = 0.0  # Stop moving forward
            twist_msg.angular.z = 0.5  # Rotate to the left
            self.publisher.publish(twist_msg)

    def move_forward(self):
        # Move forward with a constant linear velocity
        twist_msg = Twist()
        twist_msg.linear.x = 0.2  # Adjust linear velocity as needed
        twist_msg.angular.z = 0.0  # No rotation
        self.publisher.publish(twist_msg)

def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance_node = ObstacleAvoidance()
    rclpy.spin(obstacle_avoidance_node)
    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
