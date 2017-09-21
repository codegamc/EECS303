#include <stdio.h>    // Used for printf() statements
#include <wiringPi.h> // Include WiringPi library!

// Pin number declarations. We're using the Broadcom chip pin numbers.
const int ledPin1 = 23; // Regular LED - Broadcom pin 23, P1 pin 16
const int ledPin2 = 24;
const int ledPin3 = 25;
void cleanup (void) __attribute__((destructor));

void cleanup (void)
{
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 0);
    digitalWrite(ledPin3, 0);
    system("gpio unexport 23");
    system("gpio unexport 24");
    system("gpio unexport 25");
    

}


int main(void)
{
    // Setup stuff:
    wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers
    pinMode(ledPin1, OUTPUT);     // Set regular LED as output
    pinMode(ledPin2, OUTPUT); 
    pinMode(ledPin3, OUTPUT); 

    digitalWrite(ledPin1, 0);//initialize pins low
    digitalWrite(ledPin2, 0);
    digitalWrite(ledPin3, 0);
	int i;
	for(i = 0; i < 5 ; i++){
		// write pin low
		digitalWrite(ledPin1, 1);
		delay(1000);
		digitalWrite(ledPin1, 0);
		digitalWrite(ledPin2, 1);
		delay(1000);
		digitalWrite(ledPin2, 0);
		digitalWrite(ledPin3, 1);
		delay(1000);
		digitalWrite(ledPin3, 0);
	}
    //digitalWrite(ledPin, LOW);     // Regular LED off
    //digitalWrite(ledPin, HIGH);     // Regular LED off
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 0);
    digitalWrite(ledPin3, 0);
    system("gpio unexport 23");
    system("gpio unexport 24");
    system("gpio unexport 25");
    return 0;
}



