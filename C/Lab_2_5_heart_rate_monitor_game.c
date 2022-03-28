/****************************************************************
* 	Lab practice 2
*  	Exercise 5
*  	Author: Josep Barbera
*  	Date: 22 March 2022
*
*	Heart rate monitor. Create a game where the student presses 
* 	a button as fast as he/she can and the number of presses per 
*	unit of time (for example every 3 tenths of a second) is 
*	continuously displayed on the led bar.

*	For this purpose, a time window or time base of 3 tenths must 
* 	be set (based on the time interrupt library), during which 
*	the number of presses per external interrupt on one of the 
*	buttons on the I/O board is counted, and at the end of each
*	period the number of presses is displayed on the LED bar.
*	The number of keystrokes must be displayed in such a way that
*	as many consecutive LEDs light up as there have been
*	keystrokes in the last counting period.
*****************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Int01s.h"

unsigned char i=0;
unsigned char pulse=0;
void toggle()
{
	if(i == 3){ /* time window of 3 tenths of a second */
		switch(pulse){
			case 1: 
				PORTC = 0b00000001;
				break;
			case 2:
				PORTC = 0b00000011;
				break;
			case 3:
				PORTC = 0b00000111;
				break;
			case 4:
				PORTC = 0b00001111;
				break;
			case 5:
				PORTC = 0b00011111;
				break;
			default: PORTC=0x00;
		}
		i=0;
		pulse=0;
	}
	i++;
}

ISR(INT7_vect){
	pulse++;
}

int main(void){
	cli();
	DDRC = 0xFF;
	DDRE = 0x00;
	EICRB = 0x80;
	EIMSK = 0x80;
	EIFR = 0x80;
    setupPeriodicInt();
	setPeriodicIntCallback(toggle);
	sei();

    while (1){
    }
}

