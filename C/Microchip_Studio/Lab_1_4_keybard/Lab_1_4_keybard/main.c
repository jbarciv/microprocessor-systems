/**************************************************************************
*	Lab practice 1
*	Exercise 4
*	Author: Josep Barbera
*	Date: 20 March 2022
*
*	A keypad scanning function that displays by LEDs the
*	row/column code of the last key pressed (by row/column code
*	we mean the value at the time the key is pressed of the port
*	to which the keyboard is connected, which will have active
*	the bit of the column that is being scanned and the bit of
*	the row whose key has been pressed. The value must remain
*	fixed in the LEDs until another key is pressed again).
*************************************************************************/

#include <avr/io.h>

int main(void)
{
	DDRC = 0x0F; /* DDRC0-3 as output, DDRC4-7 as input*/
	DDRA = 0xFF; /* DDRA0-7 as output*/
	int scan = 0x01;
	while (1){
		for (char i=0 ; i<4; i++){
			PORTC = scan;
			asm volatile (
				"nop \n"
				"nop \n"
				"nop \n"				
				"nop \n"
			);
			if (PINC & 0xF0){
				PORTA = PINC;
			}
			scan = scan << 1;
		}
		scan = 0x01;
	}
}



