import rclpy
from vectornav_msgs.msg import GpsGroup
from sensor_msgs.msg import NavSatFix

import logging

# global variable to store GPS data
latitude = None
longitude = None
node = None
subscription = None

def callback(msg):
    global latitude, longitude
    if latitude is None:
        # Grab the first set of information
        latitude = msg.latitude
        longitude = msg.longitude
        print(f"Received first set of information: {latitude}")
        print(f"Received second set of information: {longitude}")

        # Unsubscribe after receiving the first message
        node.get_logger().info('Unsubscribing from the topic...')
        subscription.destroy()
    if longitude is None:
        print("Failed to grab longitude information.")
    if latitude is None:
        print("Failed to grab latitude information")

def ros():
    rclpy.init()
    node = rclpy.create_node('task1_start')  # node is named here
    subscription = node.create_subscription(NavSatFix, 'vectornav/gnss', callback, 10)  # Adjust the queue size as needed
    rclpy.spin(subscription)
    node.destroy_node()

if __name__ == '__main__':
    try:
        ros()
    except KeyboardInterrupt:
        pass
    finally:
        # Print "Exiting script..." only if Ctrl+C is used
        if exit_signal is True:
            print("Exiting script...")