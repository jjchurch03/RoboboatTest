import RPi.GPIO as GPIO
import time

class WaterGun:
    def __init__(self, pin_number, hold_duration):
        self.pin_number = pin_number
        self.hold_duration = hold_duration
        GPIO.setup(pin_number, GPIO.OUT)

        # Initialize the stepper motor
        self.stepper_motor = StepperMotor(stepper_pin)

    def fire(self):
        print("Firing water gun.")
        # Crank stepper motor to 90 degrees
        self.stepper_motor.crank_90_degrees()
        # Hold for specified duration
        time.sleep(self.hold_duration)
        # Return stepper motor to original position
        self.stepper_motor.return_to_original_position()
        print("Water gun fired.")

class StepperMotor:
    def __init__(self, pin_number):
        self.pin_number = pin_number
        GPIO.setup(pin_number, GPIO.OUT)
        self.sequence = [[1,0,0,1], [1,0,0,0], [1,1,0,0], [0,1,0,0], [0,1,1,0], [0,0,1,0], [0,0,1,1], [0,0,0,1]]
        self.step_delay = 0.005 # Adjust this value to control motor speed

    def step(self, direction, steps):
        for _ in range(steps):
            for i in range(4):
                GPIO.output(self.pin_number, self.sequence[i])
                time.sleep(self.step_delay)
            if direction == "clockwise":
                self.sequence.insert(0, self.sequence.pop())
            else:
                self.sequence.append(self.sequence.pop(0))

    def crank_90_degrees(self):
        # Crank the stepper motor to 90 degrees
        # Assuming a 90-degree movement requires 200 steps (adjust as needed)
        self.step("clockwise", 50)

    def return_to_original_position(self):
        # Return the stepper motor to the original position
        # Assuming returning to original position requires 200 steps (adjust as needed)
        self.step("counterclockwise", 50)

# Initialize GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

# Define your water gun stepper motor pin number
stepper_pin = 22  # Example pin number
water_gun_pin = 23  # Example pin number

# Initialize the water gun
water_gun = WaterGun(water_gun_pin, hold_duration=3)  # Adjust hold_duration as needed

# Example usage:
# water_gun.fire()

