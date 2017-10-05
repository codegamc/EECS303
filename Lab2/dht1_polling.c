// gcc -Os dht1_polling.c -lwiringPi -o dht1_polling

#include <wiringPi.h>
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define MAXTIMINGS	1
#define DHTPIN		7
int dht11_dat[5] = { 0, 0, 0, 0, 0 };

void read_dht11_dat()
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0, i;
	float	f; 						// fahrenheit
 
	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
 
	// pull pin down for 18 milliseconds
	pinMode( DHTPIN, OUTPUT );
	digitalWrite( DHTPIN, LOW );
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
 


	int check = ((dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF);
 	if((j >= 40) && check)
 	{
 		f = dht11_dat[2] * 9. / 5. + 32;
 		printf("Time: %lld humidity = %d %% temp = %d C (%f F)\n", (long long) time(NULL), dht11_dat[0], dht11_dat[2], f);
 		FILE *fp;
 		fp = fopen("data.txt", "w");
 		fprintf(fp, "Time: %lld humidity = %d %% temp = %d C (%f F)\n", (long long) time(NULL), dht11_dat[0], dht11_dat[2], f);
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
