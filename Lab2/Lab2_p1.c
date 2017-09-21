#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

constant int dataPin = 23;
int timeElapsed;
int error = 0;
int data[40];

int main(void)
{
	wiringPiSetupGpio();
	pinMode(dataPin, OUTPUT);  
	digitalWrite(dataPin, 1);


	for(;;){
		digitalWrite(dataPin, 0);
		delayMicroseconds(501);
		digitalWrite(dataPin, 1);
		delayMicroseconds(30);
		pinMode(dataPin, INPUT); 

		waitForLow();
		timeElapsed = waitForHigh();
		//make sure timeElapsed is ~80

		timeElapsed = waitForLow();
		//make sure time elapsed is 80

		//first 50 us low signal
		

		int bitCount = 0;

		while(bitCount < 40){

			e = waitForHigh();
			//low before first bit, check it's roughly 50
			if(e > 52 || e < 48){
				break;
			}
			timeElapsed = waitForLow();
			append(timeElapsed, bitCount);//append checks how long it was high for and adds that data to a shift variable


			bitCount++;
		}
		if(bitCount < 40){
			break;
		}
		int sum = addBytes();


	}


	return 0;
}

int addBytes(){
	int byte1 = 2^7*data[7]+2^6*data[6]+2^5*data[5]+
}




void append(int time, int index){
	if(time > 25 && time < 30)
	{
		data[index] = 1;
	}
	else if(time < 72 && time > 68)
	{
		data[index] = 0;
	}



}

int waitForLow(){
	clock_t start = clock(), diff;
	while(digitalRead(dataPin) == 1){

	}
	diff = clock() - start;
	return(diff * 1000000 / CLOCKS_PER_SEC);

}

int waitForHigh(){
	clock_t start = clock(), diff;
	while(digitalRead(dataPin) == 0){

	}
	diff = clock() - start;
	return(diff * 1000000 / CLOCKS_PER_SEC);

}
