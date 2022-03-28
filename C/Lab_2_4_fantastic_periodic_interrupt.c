/***************************************************************
* 	Lab practice 2
*  	Exercise 4
*  	Author: Josep Barbera
*  	Date: 22 March 2022
*
*	Exercise of the fantastic car from the previous practice 
* 	(Lab_1_3), with 0.1 seconds delay for the LED-to-LED jumps, 
*	but using the functions of the provided temporary interrupts 
*	library. 
****************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Int01s.h"

unsigned char c=0;
int pin=0x01;
void conmuta()
{
	PORTC = pin;
	
	if(c<7)
	{
		pin = pin << 1;
		c++;
	}
	else if(c<14)
	{
		pin = pin >> 1;
		c++;
	}
	else c=0;
}

int main(void)
{
	cli();
	DDRC = 0xFF;
    setupPeriodicInt();
	setPeriodicIntCallback(conmuta);
	sei();
    while (1) 
    {
    }
}
