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
    delay(40);
  }
  while(brightness > 0)
  {
    softPwmWrite(ledPin, brightness);
    brightness--;
    delay(40);
  }
  
  
  softPwmWrite(ledPin, 0);
  
  return 0;
}
