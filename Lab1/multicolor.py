import RPi.GPIO as GPIO
import time

LEDred = 16
LEDgreen = 18
LEDblue = 22

def setup():
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(LEDred, GPIO.OUT)
	GPIO.setup(LEDgreen, GPIO.OUT)
	GPIO.setup(LEDblue, GPIO.OUT)
        GPIO.output(LEDred, GPIO.HIGH)
	GPIO.output(LEDgreen, GPIO.HIGH)
	GPIO.output(LEDblue, GPIO.HIGH)

def loop():
       # print ‘red on'
        GPIO.output(LEDred, GPIO.LOW)
        time.sleep(0.5)
       # print ‘red off, green on’
	GPIO.output(LEDred, GPIO.HIGH)
	GPIO.output(LEDgreen, GPIO.LOW)
	time.sleep(0.5)
	#print ‘green off, blue on’
	GPIO.output(LEDgreen, GPIO.HIGH)
	GPIO.output(LEDblue, GPIO.LOW)
        time.sleep(0.5)
	#print 'blue off'
	GPIO.output(LEDblue, GPIO.HIGH)


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




