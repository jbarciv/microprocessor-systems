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


void delay(int);

int main(void){
	DDRC = 0xFF;
	int pin = 0x01;
	
	while (1){
		for (int i=0 ; i<7 ; i++){
			PORTC = pin;
			delay(100);
			pin = pin << 1;
		}
		for (int i=0 ; i<7 ; i++){
			PORTC = pin;
			delay(100);
			pin = pin >> 1;
		}
	}
}

void delay (int ms){
	for (int i=0 ; i<ms ;i++){
		for (volatile int j=0 ; j<444 ;){
			 j++;
		}
	}
}

