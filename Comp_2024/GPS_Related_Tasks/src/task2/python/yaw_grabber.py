import rclpy
from rclpy.node import Node
from vectornav_msgs.msg import CommonGroup

class CommonSubscriber(Node):

    def __init__(self):
        super().__init__('common_subscriber')
        self.subscription = self.create_subscription(CommonGroup, 'vectornav/raw/common', self.attitude_callback, 10)
        self.subscription  # prevent unused variable warning
        
    def attitude_callback(self, msg):
        # Access the yaw variabale
        yaw = msg.yawpitchroll.x
        if yawCompare is None:
            yawCompare = yaw
        