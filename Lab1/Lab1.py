import RPi.GPIO as GPIO
import time

LEDPin = 16

def setup():
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(LEDPin, GPIO.OUT)
	GPIO.output(LEDPin, GPIO.HIGH)

def loop():
	print 'LED on'
	GPIO.output(LEDPin, GPIO.LOW)
	time.sleep(0.5)
	print 'LED off'
	GPIO.output(LEDPin, GPIO.HIGH)
	time.sleep(0.5)

def destroy():
	GPIO.output(LEDPin, GPIO.HIGH)
	GPIO.cleanup()

if __name__ == '__main__':
	setup()
	try:
		while(True):
			loop()
	except KeyboardInterrupt:
		destroy()
