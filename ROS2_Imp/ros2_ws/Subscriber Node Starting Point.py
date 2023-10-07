# Subscriber Node Starting Point

import rclpy 
from rclpy.node import Node 
import string 

class SubscriberNode(Node): 
    def __init__(self): 
        super().__init__('subscriber_node')                                                             # Initalize node which is defined as a 'subscriber_node'
        self.subscription = self.create_subscription(string, 'detection', self.message_callback, 10)    # Create node with the name of it being 'detection' which is a string variable with a queue size of 10 callback is defined in publsiher node
        self.subscription                                                                               # prevent unused variable warning 
        
        def message_callback(self, msg): 
            self.get_logger().info(f'Received: {msg.data}')                                             # This is used for logging. When message is published it will add 'Recieved: Hello World' to log. This will help with error tracing
            
        def main(args=None): 
           rclpy.init(args=args)                                                                        # Initalize rcply
           subscriber_node = SubscriberNode()                                                           # Make 'subscriber_node' defined as a Subscriber node
           try: 
            rclpy.spin(subscriber_node)                                                                 # “spins” the node so its callbacks are called with publisher node
           except KeyboardInterrupt: 
            pass                                                                                        # Allows you to exit code using 'ctrl + C' cleanly exit without trace error
           subscriber_node.destroy_node()                                                               # destroys subscriber_node
           rclpy.shutdown()                                                                             # stops rclpy
            
        if __name__ == '__main__': 
           main()                                                                                       # calls main()
