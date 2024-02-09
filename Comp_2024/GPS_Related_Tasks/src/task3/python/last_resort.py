# Code for GPS calcs
# Pin Definitions
# Pin 18: PWM Output - Controls Right Thruster (Grey wire)
r_thrust_pwm = 18
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)
l_thrust_pwm = 15

# Imports
import RPi.GPIO as GPIO
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
import math

latitude = None
longitude = None



# Initial GPIO Setup
GPIO.setmode(GPIO.BOARD)
GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

class Thrusters:
    # 1500 = neuteral
    # 1100 = max ahead
    # 1900 = max reverse
    p_r = GPIO.PWM(r_thrust_pwm, 50)
    p_l = GPIO.PWM(l_thrust_pwm, 50)
    # right_speed and left_speed should be initiated at 1500, which is neuteral
    def __init__(thrusters, left_speed, right_speed):
        thrusters.right_speed = right_speed
        thrusters.left_speed = left_speed
        thrusters.changeSpeed(left_speed, right_speed)

    def changeSpeed(thrusters, left_speed, right_speed):
        # Change right thruster to set value
        thrusters.right_speed = right_speed
        thrusters.p_r.start(right_speed/200)
        # Change left thruster to set value
        thrusters.left_speed = left_speed
        thrusters.p_l.start(left_speed/200)

    def stop(thrusters):
        thrusters.p_r.stop()
        thrusters.p_l.stop()

# Initialize the thrusters into neutral then set them to go straight forward
thrusters = Thrusters(1500, 1500)
time.sleep(5)
thrusters.changeSpeed(1350, 1350)

class WaypointNavigator(Node):
    def __init__(self):
        super().__init__('waypoint_navigator')
        self.subscription = self.create_subscription(NavSatFix, 'vectornav/gnss', self.dirtbag_callback, 10)
        
        self.waypoint_tolerance = 1.6  # Tolerance for considering a waypoint reached (adjust as needed)
        self.steady_counter = 0  # Counter to keep track of steady state
        self.backward_duration = 2  # Duration (in seconds) to apply reverse thrust
        
    def dirtbag_callback(self, msg):
        global latitude, longitude
        current_latitude = msg.latitude
        current_longitude = msg.longitude
        distance_to_waypoint = self.calculate_distance(current_latitude, current_longitude, latitude, longitude)
        angle_to_waypoint = self.calculate_angle(current_latitude, current_longitude, latitude, longitude)
        self.navigate_to_waypoint(distance_to_waypoint, angle_to_waypoint) 

    def navigate_to_waypoint(self, distance, angle):
        # Tolerance for angle to consider facing the waypoint
        angle_tolerance = math.radians(10)  # Adjust as needed
        
        if distance <= self.waypoint_tolerance:
            print("Waypoint reached. Stabilizing.")
            if self.steady_counter < self.backward_duration * 10:
                # Apply reverse thrust for a short duration to counter forward momentum
                thrusters.changeSpeed(1600, 1100)
                self.steady_counter += 1
            else:
                # Stop thrusters after applying reverse thrust
                print("Vessel stabilized. Stopping thrusters.")
                thrusters.stop()
        else:
            # Reset the steady counter if not reached the waypoint yet
            self.steady_counter = 0
            
            if abs(angle) <= angle_tolerance:
                print("Facing waypoint. Continuing straight.")
                thrusters.changeSpeed(1350, 1350)
            elif angle > angle_tolerance:
                print("Need to turn right.")
                thrusters.changeSpeed(1400, 1300)
            elif angle < -angle_tolerance:
                print("Need to turn left.")
                thrusters.changeSpeed(1300, 1400)


    
    def calculate_angle(self, lat1, long1, lat2, long2):
        dLon = (long2 - long1) #this should be a double
        y = math.sin(dLon) * math.cos(lat2)
        x = math.cos(lat1) * math.sin(lat2) - math.sin(lat1)* math.cos(lat2) * math.cos(dLon)
        brng = math.atan2(y, x)
        brng = (brng + 2 * math.pi) % (2 * math.pi)
        brng = math.degrees(brng)
        brng = (brng + 360) % 360
        brng = 360 - brng #count degrees counter-clockwise - remove to make clockwise

        return brng

    def calculate_distance(self, lat1, lon1, lat2, lon2):
        # Calculate distance between two GPS coordinates using Haversine formula
        R = 6371  # Earth radius in kilometers
        d_lat = math.radians(lat2 - lat1)
        d_lon = math.radians(lon2 - lon1)
        a = math.sin(d_lat / 2) * math.sin(d_lat / 2) + math.cos(math.radians(lat1)) * math.cos(math.radians(lat2)) * math.sin(d_lon / 2) * math.sin(d_lon / 2)
        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
        distance = R * c
        distance_meters = distance * 1000  # Convert kilometers to meters
        return distance_meters

def main(args=None):
    try:
        rclpy.init(args=args)
        navigator = WaypointNavigator()
        rclpy.spin(navigator)
    except KeyboardInterrupt:
        print("Keyboard interrupt detected. Exiting...")
    except Exception as e:
        print(f"An error occurred: {str(e)}")
    finally:
        if 'navigator' in locals():
            navigator.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()


GPIO.cleanup()
