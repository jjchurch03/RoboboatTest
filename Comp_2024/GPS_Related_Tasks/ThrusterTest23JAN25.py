import RPi.GPIO as GPIO
import time

r_thrust_pwm = 18
l_thrust_pwm = 16
arduino_input_pin = 12 #what the arduino will send the signal on to go autonomous

class Thruster:
    # 1500 = neutral
    # 1100 = max ahead
    # 1900 = max reverse 
    # GPIO.PWM method allows a specific PWM to be sent out from a pin

    def __init__(self, left_speed, right_speed):   
        GPIO.setmode(GPIO.BOARD)  # Use physical pin numbering
        GPIO.setup(r_thrust_pwm, GPIO.OUT)
        GPIO.setup(l_thrust_pwm, GPIO.OUT)
        
        self.p_r = GPIO.PWM(r_thrust_pwm, 50)  # Arguments: (PIN, frequency)
        self.p_l = GPIO.PWM(l_thrust_pwm, 50)

        self.right_speed = right_speed
        self.left_speed = left_speed

        self.p_r.start(right_speed / 200)  # Start PWM with the right speed
        self.p_l.start(left_speed / 200)  # Start PWM with the left speed

    def changeSpeed(self, left_speed, right_speed):
        # Change thruster speeds
        self.right_speed = right_speed
        self.left_speed = left_speed
        
        self.p_r.start(right_speed / 200)  # Update duty cycle for right thruster
        self.p_l.start(left_speed / 200)  # Update duty cycle for left thruster

    def stop(self):
        self.p_r.stop()
        self.p_l.stop()
        GPIO.cleanup()

#this assumes the code is running!
try:
    thrusters = Thruster(1500, 1500)		
    time.sleep(3)
    
    while True: # Replace with actual Arduino input logic
        arduino_input = GPIO.input(arduino_input_pin)
        
        if arduino_input == GPIO.HIGH:
            print("Arduino input detected: Adjusting thruster speed.")
            thrusters.changeSpeed(1350, 1350)
            time.sleep(3000)
        else:
            print("No input detected from Arduino.")
            time.sleep(3)
            thrusters.stop()
        
	
except KeyboardInterrupt:
    print("\nExiting program.")
    thrusters.stop()
    GPIO.cleanup()
