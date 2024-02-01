import rclpy
from rclpy.node import Node
from vectornav_msgs.msg import AttitudeGroup

class AttitudeSubscriber(Node):

    def __init__(self):
        super().__init__('attitude_subscriber')
        self.subscription = self.create_subscription(AttitudeGroup,'attitude', self.attitude_callback, 10)
        self.subscription  # prevent unused variable warning

    def attitude_callback(self, msg):
        # Access the yawpitchroll variable from the attitude group
        yaw = msg.yawpitchroll.x
        pitch = msg.yawpitchroll.y
        roll = msg.yawpitchroll.z

        # Print the values (you can modify this part as needed)
        self.get_logger().info(f'Yaw: {yaw}, Pitch: {pitch}, Roll: {roll}')

def main(args=None):
    rclpy.init(args=args)

    attitude_subscriber = AttitudeSubscriber()

    rclpy.spin(attitude_subscriber)

    attitude_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
