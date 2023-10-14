#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from my_client_server_pkg.srv import MyService

class MyServerNode(Node):

    def __init__(self):
        super().__init__('my_server_node')
        self.server = self.create_service(MyService, 'gps_coord', self.callback)

    def callback(self, request, response):
        self.get_logger().info(f"Received request: {request.input_data}")
        response.output_data = f"Server processed: {request.input_data}"
        return response

def main(args=None):
    rclpy.init(args=args)
    server_node = MyServerNode()
    rclpy.spin(server_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
