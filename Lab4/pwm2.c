#include <stdio.h>
#include <wiringPi.h>

const int ledPin = 7;
int brightness = 0;

int main(void)
{
  wiringPiSetup();
  pinMode(ledPin, OUTPUT);
  
  softPwmCreate(ledPin, 0, 100);
  
  while(brightness < 100)
  {
    softPwmWrite(ledPin, brightness);
    brightness++;
    delay(20);
  }
  softPwmWrite(ledPin, 0);
  
  return 0;
}
