# existing imports

#imports for ROS 2
import rclpy
from geometry_msgs.msg import Twist

# existing code for Main Control

class Thrusters:
    # beginning part here

    def receive_twist_message(self, twist_msg):
        # Extract linear and angular velocities from Twist message
        linear_vel = twist_msg.linear.x
        angular_vel = twist_msg.angular.z

        # Convert velocities to PWM values for thrusters (adjust as needed)
        right_pwm = 1500 + int(linear_vel * 500) + int(angular_vel * 500)
        left_pwm = 1500 + int(linear_vel * 500) - int(angular_vel * 500)

        # Set thruster speeds
        self.changeSpeed(left_pwm, right_pwm)

def main():
    # Initialize RPi.GPIO and thrusters
    GPIO.setmode(GPIO.BOARD)
    thrusters = Thrusters(1500, 1500)

    # Initialize ROS 2 node
    rclpy.init()
    node = rclpy.create_node('thruster_control_node')

    # Create subscriber to receive Twist messages
    def twist_callback(msg):
        thrusters.receive_twist_message(msg)

    subscriber = node.create_subscription(Twist, 'cmd_vel', twist_callback, 10)

    # Spin ROS 2 node
    rclpy.spin(node)

    # Cleanup
    thrusters.stop()
    GPIO.cleanup()

if __name__ == '__main__':
    main()
