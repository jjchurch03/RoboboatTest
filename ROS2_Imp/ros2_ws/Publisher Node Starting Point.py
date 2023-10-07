# Publisher Node Starting Point
import rclpy 
from rclpy.node import Node 
import string 

class PublisherNode(Node): 
    def __init__(self): 
        super().__init__('publisher_node')                                     # Initalize node which is defined as a 'publisher_node'
        self.publisher = self.create_publisher(string, 'detection', 10)        # Create node with the name of it being 'detection' which is a string variable with a queue size of 10
        timer_period = 0.1                                                     # 0.1 second                 
        self.timer = self.create_timer(timer_period, self.publish_message)     # timer is created with a callback to execute every tenth of a second
        self.count = 0                                                         # Initalize count
        
    def publish_message(self): 
        msg = string()                                                         # defines 'msg' as a string variable
        msg.data = f'Hello World {self.count}'                                 # makes the string stored in msg be Hello World (to be updated)
        self.publisher.publish(msg)                                            # sends out msg via publisher node
        self.get_logger().info(f'Publishing: {msg.data}')                      # This is used for logging. When message is published it will add 'Publishing: Hello World' to log
        self.count += 1                                                        # Update count
        
    def main(args=None): 
        rclpy.init(args=args)                                                  # Initalize rcply
        publisher_node = PublisherNode()                                       # Make 'publisher_node' defined as a Publisher node
        try: 
            rclpy.spin(publisher_node)                                         # “spins” the node so its callbacks are called
        except KeyboardInterrupt: 
            pass                                                               # Allows you to exit code using 'ctrl + C' cleanly exit without trace error
        publisher_node.destroy_node()                                          # destroys publisher_node
        rclpy.shutdown()                                                       # stops rclpy
    if __name__ == '__main__': 
        main()                                                                 # calls main()
