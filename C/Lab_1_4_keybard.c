/***************************************************************
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
****************************************************************/

#include <avr/io.h>

int main(void)
{
	DDRC = 0x0F;
	DDRA = 0xFF;
	int scan = 0x01;
	int i;
	while (1){	
		for (i=0 ; i<3 ; i++){
			PORTC = scan;
			if (PINC & 0xf0){
				PORTA = PORTC;
			} 
			scan = scan << 1;
		}
		scan = 0x01;
	}
}



