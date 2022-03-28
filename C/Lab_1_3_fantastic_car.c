/**************************************************************
*	Lab practice 1
*	Exercise 3
*	Author: Josep Barbera
*	Date: 20 March 2022
*
*	Shifting the light alternately from right to left between
*	the 8 LEDs with a software delay of 0.1 s between each
*	displacement.
***************************************************************/ 

#include <avr/io.h>


void delay(float);

int main(void){
	DDRC = 0xFF;
	int pin = 0x01;
	int t;
	int i;

	while (1){
		for (i=0 ; i<7 ; i++){
			PORTC = pin;
			delay(2000);
			pin = pin << 1;
		}
		for (i=0 ; i<7 ; i++){
			PORTC = pin;
			delay(2000);
			pin = pin >> 1;
		}
	}
}

void delay (float t){
	float j;
	for (j=0 ; j<t ; j++){
		;
	}
}

