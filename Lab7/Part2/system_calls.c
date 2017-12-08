
#include <stdio.h>

#include<stdlib.h>








int main(void)
{

	while(1)
	{
		printf("Temp: ");
		system("cat /sys/bus/iio/devices/iio\\:device0/in_temp_input");
		printf("\n");
		printf("Humidity:");
		system("cat /sys/bus/iio/devices/iio\\:device0/in_humidityrelative_input");
		printf("\n");
		delay(50);
	}



}