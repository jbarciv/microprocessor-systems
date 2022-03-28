/***************************************************************
*	Lab practice 2
*	Exercise 4
*	Author: Josep Barbera
*	Date: 22 March 2022
*
*	Exercise of the fantastic car from the previous practice 
*	(Lab_1_3), with 0.1 seconds delay for the LED-to-LED jumps, 
*	but using the functions of the provided temporary interrupts 
*	library. 
****************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Int01s.h"


unsigned char i = 0;
int pin = 0x01;

void toggle (){
	PORTC = pin;

	if (i < 7)	{
		pin = pin << 1;
		i++;
	}
	else if (i < 14){
		pin = pin >> 1;
		i++;
	}
	else i = 0;
}

int main (void) {
	cli();
	DDRC = 0xFF;
	setupPeriodicInt();
	setPeriodicIntCallback(toggle);
	sei();
	while (1){

	}
}
