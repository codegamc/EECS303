// gcc -Os dht1_polling.c -lwiringPi -o dht1_polling
// gcc -Os dht_11_light.c -lwiringPi -o dht_11_light
#include <wiringPi.h>
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define MAXTIMINGS	85
#define DHTPIN		7

int led_pin = 29;

int dht11_dat[5] = { 0, 0, 0, 0, 0 };
int count = 0;
FILE *fp;

void read_dht11_dat()
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0, i;
	float	f; 						// fahrenheit
 
	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
 
	// pull pin down for 18 milliseconds
	pinMode( DHTPIN, OUTPUT );
	pinMode( led_pin, OUTPUT );
	digitalWrite( DHTPIN, LOW );
	digitalWrite( led_pin, LOW );
	delay( 18 );
	// pull it up for 40 microseconds
	digitalWrite( DHTPIN, HIGH );
	delayMicroseconds( 40 );
	// prepare to read the pin
	pinMode( DHTPIN, INPUT );
 
	// detect change and read data
	for ( i = 0; i < MAXTIMINGS; i++ )
	{
		counter = 0;
		while ( digitalRead( DHTPIN ) == laststate )
		{
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = digitalRead( DHTPIN );
 
		if ( counter == 255 )
			break;
 
		// ignore first 3 transitions
		if ( (i >= 4) && (i % 2 == 0) )
		{
			// shove each bit into the storage bytes
			dht11_dat[j / 8] <<= 1;
			if ( counter > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}
 

	fp = fopen("data.txt", "w+");
	int check = ((dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF);
 	if((j >= 40) && check)
 	{
 		count = count + 1;
 		f = dht11_dat[2] * 9. / 5. + 32;
 		printf("Time: %lld humidity = %d %% temp = %d C (%f F)\n", (long long) time(NULL), dht11_dat[0], dht11_dat[2], f);
 		//FILE *fp;
		
		if(dht11_dat[2] > 31)
		{
			//this means the temp is too high
			digitalWrite(led_pin, HIGH);
		}
		else
		{
			// this menas it cooled off
			//digitalWrite(led_pin, LOW);
		}
 		
 		//if(fp == NULL)
 		//{
 			
 			fprintf(fp, "Time: %lld humidity = %d %% temp = %d C (%f F)\n", (long long) time(NULL), dht11_dat[0], dht11_dat[2], f);
 			fclose(fp);
 		//}
 	}
 	else
 	{
 		printf("Checksum failed\n");
 	}
	// verify checksum with reading data.

	//print humidity and temperature

	//print time

	//write humidity and temperature into file
		
}
 
int main()
{ 
	if ( wiringPiSetup() == -1 )
		exit( 1 );
 
	while ( 1 )
	{
		read_dht11_dat();
		// wait 1sec to refresh
		delay( 1000 ); 
	}
 	
	return(0);
}
