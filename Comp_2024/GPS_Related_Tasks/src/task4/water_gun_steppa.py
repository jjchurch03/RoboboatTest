import RPi.GPIO as GPIO
import time

class WaterGun:
    def __init__(self, pin_number):
        self.pin_number = pin_number
        GPIO.setup(pin_number, GPIO.OUT)

    def fire(self):
        # Your water gun firing logic here
        print("Firing water gun.")
        # Crank stepper motor to 180 degrees
        water_gun_stepper_motor.crank_180_degrees()
        # Return stepper motor to original position
        water_gun_stepper_motor.return_to_original_position()

class StepperMotor:
    def __init__(self, pin_number):
        self.pin_number = pin_number
        GPIO.setup(pin_number, GPIO.OUT)

    def crank_180_degrees(self):
        # Crank the stepper motor to 180 degrees
        # Your stepper motor logic here
        print("Cranking stepper motor to 180 degrees.")

    def return_to_original_position(self):
        # Return the stepper motor to the original position
        # Your stepper motor logic here
        print("Returning stepper motor to original position.")

# Define your water gun stepper motor pin number
water_gun_stepper_pin = 22  # Example pin number

# Initialize the water gun stepper motor
water_gun_stepper_motor = StepperMotor(water_gun_stepper_pin)

# Example usage:
# water_gun = WaterGun(pin_number)
# water_gun.fire()