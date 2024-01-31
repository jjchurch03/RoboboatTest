import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan

class MySubscriber(Node):
    def __init__(self):
        super().__init__('my_subscriber_node')
        self.subscription = self.create_subscription(LaserScan,'scan', self.listener_callback, 10)
        self.subscription  # Prevent unused variable warning

    def listener_callback(self, msg):
        # Process the LaserScan message here
        self.get_logger().info('Received LaserScan data: %s' % msg)

def main(args=None):
    rclpy.init(args=args)
    my_subscriber = MySubscriber()
    rclpy.spin(my_subscriber)
    my_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
