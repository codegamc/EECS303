#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

constant int dataPin = 23;
int timeElapsed;
int error = 0;
int data[40];
int byte1 = 0;
int byte2 = 0;
int byte3 = 0;
int byte4 = 0;

int main(void)
{
	wiringPiSetupGpio();
	pinMode(dataPin, OUTPUT);  
	digitalWrite(dataPin, 1);


	//for(;;){
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
		if(addBytes())
        {
            fprint("Temperature: %d C, Humidity: %d", byte1, byte3);
            
        }
        else{
            fprint("comparison to checksum failed");
            
        }


	//}


	return 0;
}

bool addBytes(){
    byte1 = 128*data[7]+64*data[6]+32*data[5]+16*data[4]+8*data[3]+4*data[2]+2*data[1]+data[0];
    byte2 = 128*data[15]+64*data[14]+32*data[13]+16*data[12]+8*data[11]+4*data[10]+2*data[9]+data[8];
    byte3 = 128*data[23]+64*data[22]+32*data[21]+16*data[20]+8*data[19]+4*data[18]+2*data[17]+data[16];
    byte4 = 128*data[31]+64*data[30]+32*data[29]+16*data[28]+8*data[27]+4*data[26]+2*data[25]+data[24];
    int checksum = 128*data[39]+64*data[38]+32*data[37]+16*data[36]+8*data[35]+4*data[34]+2*data[33]+data[32];
    if((byte1 + byte2 + byte3 + byte4) && 0xFF = checksum)
    {
        return(true);
    }
    else{
        return(false);
    }
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
