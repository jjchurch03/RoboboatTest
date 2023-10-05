# Publisher Node Starting Point
import rclpy 
from rclpy.node import Node 
import string 

class PublisherNode(Node): 
    def __init__(self): 
        
        super().__init__('publisher_node') 
        self.publisher = self.create_publisher(string, 'detection', 10) 
        timer_period = 1 # 1 second 
        self.timer = self.create_timer(timer_period, self.publish_message) 
        self.count = 0 
        
    def publish_message(self): 
        msg = string() 
        msg.data = f'Hello World {self.count}' 
        self.publisher.publish(msg) 
        self.get_logger().info(f'Publishing: {msg.data}') 
        self.count += 1 
        
    def main(args=None): 
        rclpy.init(args=args) 
        publisher_node = PublisherNode() 
        try: 
            rclpy.spin(publisher_node) 
        except KeyboardInterrupt: 
            pass 
        publisher_node.destroy_node()
        rclpy.shutdown()
    if __name__ == '__main__': 
        main()