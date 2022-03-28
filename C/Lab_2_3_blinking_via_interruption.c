/***************************************************************
*	Lab practice 2
*	Exercise 3
*	Author: Josep Barbera
*	Date: 22 March 2022
*
*	Change the state of the LEDs periodically (every 0.5 s  
*	approximately) using an external library and callbacks.
****************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Int01s.h"

unsigned char c;
void change()
{
	c++;
	if (c == 5){
		PORTC = ~PINC;
		c = 0;
	}
}

int main(void){
	cli();
	DDRC = 0xFF;
	setupPeriodicInt();
	setPeriodicIntCallback(change);
	sei();
	while (1){
		/*whatever*/
	}
}
