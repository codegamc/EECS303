#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

const int dataPin = 23;
int timeElapsed = 0;
int error = 0;
int data[40];
int byte1 = 0;
int byte2 = 0;
int byte3 = 0;
int byte4 = 0;
int e = 0;

//functions
void append(int time, int index);
int waitForLow();
int waitForHigh();


int main(void)
{
	wiringPiSetupGpio();
	pinMode(dataPin, OUTPUT);  
	digitalWrite(dataPin, 1);


	//for(;;){
		digitalWrite(dataPin, 0);
		delayMicroseconds(18050);
		digitalWrite(dataPin, 1);
		delayMicroseconds(20);
		
		pinMode(dataPin, INPUT); 

		waitForLow();
        	
		
		//printf("reached Ack part\n");
    		
		timeElapsed = waitForHigh();
		//printf("reached waiting for high, time was %d\n", timeElapsed);
		//make sure timeElapsed is ~80
    

		timeElapsed = waitForLow();
		//make sure time elapsed is 80

		//first 50 us low signal
		

		int bitCount = 0;

		while(bitCount < 40){
			//printf("in while loop");
			e = waitForHigh();
			printf("time low was %d\n", e);
			//low before first bit, check it's roughly 50
			if(e > 60 || e < 40){
				printf("Timing error, time was %d\n", e);				
				return(1);
			}
			timeElapsed = waitForLow();
			//printf("time high was %d\n", timeElapsed);
			append((int)timeElapsed, bitCount);//append checks how long it was high for and adds that data to a shift variable


			bitCount++;
		}
		printf("Through while loop");
		if(bitCount < 40){
			return(1);
		}
		//if(addBytes() == 1)
        //{
            printf("Temperature: %d C, Humidity: %d", byte1, byte3);
            
        //}
        ///else{
            //printf("comparison to checksum failed");
            
        //}


	//}


	return 0;
}

int addBytes(){
    byte1 = 128*data[7]+64*data[6]+32*data[5]+16*data[4]+8*data[3]+4*data[2]+2*data[1]+data[0];
    byte2 = 128*data[15]+64*data[14]+32*data[13]+16*data[12]+8*data[11]+4*data[10]+2*data[9]+data[8];
    byte3 = 128*data[23]+64*data[22]+32*data[21]+16*data[20]+8*data[19]+4*data[18]+2*data[17]+data[16];
    byte4 = 128*data[31]+64*data[30]+32*data[29]+16*data[28]+8*data[27]+4*data[26]+2*data[25]+data[24];
    int checksum = 128*data[39]+64*data[38]+32*data[37]+16*data[36]+8*data[35]+4*data[34]+2*data[33]+data[32];
    if((byte1 + byte2 + byte3 + byte4) && 0xFF == checksum)
    {
        return(1);
    }
    else{
        return(0);
    }
}




void append(int time, int index){
	if(time > 20 && time < 35)
	{
		data[index] = 1;
	}
	else if(time < 80 && time > 60)
	{
		data[index] = 0;
	}



}

int waitForChange(){
		
	clock_t start = clock(), diff;
	int initialVal = digitalRead(dataPin);
	while(digitalRead(dataPin) == initialVal){
	
	}
	
	diff = clock() - start;
	//printf("waiting for change\n");
	return((int)((double)diff * 1000000 / CLOCKS_PER_SEC));
}



int waitForLow(){
    		
	clock_t start = clock(), diff;
	while(digitalRead(dataPin) == 1){

	}
	diff = clock() - start;
	//printf("waiting for low\n");
	return((int)((double)diff * 1000000 / CLOCKS_PER_SEC));

}

int waitForHigh(){
	
	clock_t start = clock(), diff;
	while(digitalRead(dataPin) == 0){

	}
	diff = clock() - start;
	//printf("waiting for high\n");	
	return((int)((double)diff * 1000000 / CLOCKS_PER_SEC));

}
