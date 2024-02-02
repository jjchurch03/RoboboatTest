import rclpy
from rclpy.node import Node
from vectornav_msgs.msg import CommonGroup

class CommonSubscriber(Node):

    def __init__(self):
        super().__init__('common_subscriber')
        print("Creating Node...")
        self.subscription = self.create_subscription(CommonGroup, 'vectornav/raw/common', self.attitude_callback, 10)
        self.subscription  # prevent unused variable warning

    def attitude_callback(self, msg):
        # Access the yawpitchroll variable from the attitude group
        print("grabbing yaw, pitch, and roll variables...")
        yaw = msg.yawpitchroll.x
        pitch = msg.yawpitchroll.y
        roll = msg.yawpitchroll.z

        # Print the values (you can modify this part as needed)
        print(f"Yaw: {yaw}, Pitch: {pitch}, Roll: {roll}")

def main(args=None):
    rclpy.init(args=args)

    common_subscriber = CommonSubscriber()

    try:
        rclpy.spin(common_subscriber)
    except KeyboardInterrupt:
        # Handle Ctrl+C gracefully
        pass
    finally:
        # Shutdown when done
        common_subscriber.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
