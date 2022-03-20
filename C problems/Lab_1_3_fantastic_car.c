/*
 * Fantastic_car.c
 *
 * Created: 08/03/2022 17:15:06
 * Author : General
 */ 

#include <avr/io.h>
void delay(float );
float a;

int main(void)
{
	DDRC = 0xff;
	int pin=0x01;
	int t;
	int i;
    while (1) 
    {
		for (i=0;i<7;i++)
		{
			PORTC = pin;
			delay(2000);
			pin = pin << 1;
		}
		for (i=0;i<7;i++)
		{
			PORTC = pin;
			delay(2000);
			pin = pin >> 1;
		}
    }
}

void delay(float t)
{
	for (a=0;a<t;a++){
		;
	}
}

