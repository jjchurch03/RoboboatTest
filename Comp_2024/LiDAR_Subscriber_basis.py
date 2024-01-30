import rclpy
from sensor_msgs.msg import LaserScan

class LidarProcessor:
    def __init__(self):
        self.node = rclpy.create_node('lidar_processor')
        self.subscription = self.node.create_subscription(LaserScan, 'lidar_topic', self.lidar_callback, 10)

    def lidar_callback(self, msg):
        # Process the LiDAR data here
        ranges = msg.ranges
        closest_distance = min(ranges)

        # Define your desired minimum distance
        desired_min_distance = 0.5  # Adjust this value according to your needs

        if closest_distance < desired_min_distance:
            # Stop the robot or take appropriate action
            print("I have docked in my berth!")

        else:
            # Move the robot forward or take appropriate action
            print("I am closing in on my target")

def main():
    rclpy.init()
    lidar_processor = LidarProcessor()
    print('Waiting for LiDAR data...')
    rclpy.spin(lidar_processor.node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
