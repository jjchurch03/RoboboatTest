#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from my_client_server_pkg.srv import MyService

class MyClientNode(Node):

    def __init__(self):
        super().__init__('my_client_node')
        self.client = self.create_client(MyService, 'gps_coord')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')

    def send_request(self):
        request = MyService.Request()
        request.input_data = "Hello from client!"
        future = self.client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.get_logger().info(f"Received response: {future.result().output_data}")
        else:
            self.get_logger().error("Service call failed!")

def main(args=None):
    rclpy.init(args=args)
    client_node = MyClientNode()
    client_node.send_request()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
