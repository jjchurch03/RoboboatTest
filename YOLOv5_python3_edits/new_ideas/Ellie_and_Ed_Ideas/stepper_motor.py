step = 16 
# Pin 18: PWM Output - Controls Right Thruster (Grey wire)
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)

# Imports
import RPi.GPIO as GPIO
import time

# Initial GPIO Setup
GPIO.setmode(GPIO.BOARD)
GPIO.setup(step, GPIO.OUT, initial=GPIO.LOW)
# GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
# GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

class Motor:
	# 1500 = neuteral
	# 500 = max ahead
	# 2500 = max reverse
	p = GPIO.PWM(step, 50)
	# p_l = GPIO.PWM(l_thrust_pwm, 50)
	# right_speed and left_speed should be initiated at 1500, which is neuteral
	def __init__(motor, speed_step):
		motor.speed_step = speed_step
		motor.changeSpeed(speed_step)
		
	def changeSpeed(motor,speed_step):
		# Change right thruster to set value
		motor.speed_step = speed_step
		motor.p.start(speed_step/200)
		
	def stop(motor):
		motor.p.stop()
		

motor = Motor(1500)
time.sleep(5)
motor.changeSpeed(1350)
time.sleep(2)
motor.changeSpeed(1500)
time.sleep(5)
motor.changeSpeed(1650)