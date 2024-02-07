#!/usr/bin/env python

from sensor_msgs.msg import LaserScan
from threading import Thread
import rclpy
from sensor_msgs.msg import NavSatFix
from threading import Timer
from datetime import datetime

class LaserScanSubscriber:
    def __init__(self):
        self.scan_data = []
        self.file_path_1 = "laser_scan_data_time.txt"
        self.file_path_2 = "laser_scan_data_notime.txt"
        self.write_interval = 2  # Update interval in seconds
        self.timer = None

    def callback(self, msg):
        self.scan_data.append(msg)

        if self.timer is None:
            self.timer = Timer(self.write_interval, self.write_to_file)
            self.timer.start()
        else:
            pass

    def write_to_file(self):
        dt = datetime.now()
        config_dt = dt.strftime("%c")
        with open(self.file_path_1, 'a') as file:
            for scan in self.scan_data:
                file.write(f"{config_dt}: {scan.header}\n")
                file.write("Angle Min: {}\n".format(scan.angle_min))
                file.write("Angle Max: {}\n".format(scan.angle_max))
                file.write("Angle Increment: {}\n".format(scan.angle_increment))
                file.write("Time Increment: {}\n".format(scan.time_increment))
                file.write("Scan Time: {}\n".format(scan.scan_time))
                file.write("Range Min: {}\n".format(scan.range_min))
                file.write("Range Max: {}\n".format(scan.range_max))
                file.write("Ranges: {}\n".format(scan.ranges))
                file.write("Intensities: {}\n".format(scan.intensities))
                file.write("\n")
            print(f"Laser scan data written to file one.")

        with open(self.file_path_2, 'a') as file:
            for scan in self.scan_data:
                file.write(f"{scan.header}\n")
                file.write("Angle Min: {}\n".format(scan.angle_min))
                file.write("Angle Max: {}\n".format(scan.angle_max))
                file.write("Angle Increment: {}\n".format(scan.angle_increment))
                file.write("Time Increment: {}\n".format(scan.time_increment))
                file.write("Scan Time: {}\n".format(scan.scan_time))
                file.write("Range Min: {}\n".format(scan.range_min))
                file.write("Range Max: {}\n".format(scan.range_max))
                file.write("Ranges: {}\n".format(scan.ranges))
                file.write("Intensities: {}\n".format(scan.intensities))
                file.write("\n")
            print(f"Laser scan data written to file two.")

        self.timer = Timer(self.write_interval, self.write_to_file)
        self.timer.start()

class GPSSubscriber:
    def __init__(self):
        self.latitude = None
        self.longitude = None
        self.file_path_1 = "location_data_task1_time.txt"
        self.file_path_2 = "location_data_task1_notime.txt"
        self.write_interval = 2  # Update interval in seconds
        self.timer = None

    def callback(self, msg):
        self.latitude = msg.latitude
        self.longitude = msg.longitude

        if self.latitude is not None and self.longitude is not None:
            if self.timer is None:
                self.timer = Timer(self.write_interval, self.write_to_file)
                self.timer.start()
            else:
                pass

    def write_to_file(self):
        dt = datetime.now()
        config_dt = dt.strftime("%c")
        with open(self.file_path_1, 'a') as file:
            file.write(f"{config_dt}: {self.latitude}, {self.longitude}\n")
            print(f"Latitude: {self.latitude}, Longitude: {self.longitude} written to file one.")
        with open(self.file_path_2, 'a') as file:
            file.write(f"{self.latitude}, {self.longitude}\n")
            print(f"Latitude: {self.latitude}, Longitude: {self.longitude} written to file two.")

        self.timer = Timer(self.write_interval, self.write_to_file)
        self.timer.start()

def laser_scan_thread():
    rclpy.init()
    node = rclpy.create_node('laser_scan_subscriber_node')
    laser_subscriber = LaserScanSubscriber()
    subscription = node.create_subscription(LaserScan, '/scan', laser_subscriber.callback, 10)
    rclpy.spin(node)
    if laser_subscriber.timer:
        laser_subscriber.timer.cancel()
    node.destroy_node()

def gps_thread():
    rclpy.init()
    node = rclpy.create_node('gps_subscriber')
    gps_subscriber = GPSSubscriber()
    subscription = node.create_subscription(NavSatFix, 'vectornav/gnss', gps_subscriber.callback, 10)
    rclpy.spin(node)
    if gps_subscriber.timer:
        gps_subscriber.timer.cancel()
    node.destroy_node()

if __name__ == '__main__':
    laser_scan_thread = Thread(target=laser_scan_thread)
    gps_thread = Thread(target=gps_thread)

    laser_scan_thread.start()
    gps_thread.start()

    laser_scan_thread.join()
    gps_thread.join()