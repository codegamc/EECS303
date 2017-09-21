import RPi.GPIO as GPIO
import time

LEDPin1 = 16
LEDPin2 = 18
LEDPin3 = 22

def setup():
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(LEDPin1, GPIO.OUT)
        GPIO.setup(LEDPin2, GPIO.OUT)
        GPIO.setup(LEDPin3, GPIO.OUT)
        GPIO.output(LEDPin1, GPIO.LOW)
        GPIO.output(LEDPin2, GPIO.LOW)
        GPIO.output(LEDPin3, GPIO.LOW)

def loop():
        # light led 1
        print 'LED 1 on'
        GPIO.output(LEDPin1, GPIO.HIGH)
        time.sleep(0.5)
        print 'LED 1 off'
        GPIO.output(LEDPin1, GPIO.LOW)
        # light led 2
        print 'LED 2 on'
        GPIO.output(LEDPin2, GPIO.HIGH)
        time.sleep(0.5)
        print 'LED 2 off'
        GPIO.output(LEDPin2, GPIO.LOW)
        # light led 3
        print 'LED 3 on'
        GPIO.output(LEDPin3, GPIO.HIGH)
        time.sleep(0.5)
        print 'LED 3 off'
        GPIO.output(LEDPin3, GPIO.LOW)
        
                        
def destroy():
                GPIO.output(LEDPin1, GPIO.HIGH)
                GPIO.output(LEDPin2, GPIO.HIGH)
                GPIO.output(LEDPin3, GPIO.HIGH)
                GPIO.cleanup()

if __name__ == '__main__':
    setup()

    try:
                            while(True):
                                loop()
    except KeyboardInterrupt:
                                 destroy()
