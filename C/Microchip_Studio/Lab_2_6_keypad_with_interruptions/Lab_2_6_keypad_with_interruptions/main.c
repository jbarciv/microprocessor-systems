/*******************************************************************
*	Lab practice 2
*	Exercise 6
*	Author: Josep Barbera
*	Date: 22 March 2022
*
*	Use interrupts to scan the keyboard and get its value from the
*	LEDs.
*	We will set all the output lines of the keyboard (let's assume
*	that they are the columns) to high level, and we will enable
*	PCINT type interrupts on the inputs (let's assume that they are
*	the rows). If at any given moment a key is pressed, an interrupt
*	will be produced (since all the columns are at high level, the
*	value of one of the rows will change). In the interrupt
*	subroutine we will then scan the keyboard in the normal way (but
*	only once) to see which key is pressed. Once the scan is finished
*	(and its value is shown in the LEDs), we will set all the columns
*	to high level again and we will delete the pending interrupts
*	(since when scanning the keyboard we will have "moved" the rows
*	again, which will provoke new interrupt requests).
********************************************************************/

/* --> CAUTION <-- */
/*NOT FINISHED... UNDER CONSTRUCTION!!!!*/

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char scan = 0x01;


ISR (PCINT2_vect){
	for (char i=0 ; i<4 ; i++){
	 	PORTK = scan;
		asm volatile (
				"nop \n"
				"nop \n"
				"nop \n"				
				"nop \n"
			);
		if(PINK & 0xF0){
	 		PORTB = PINK;
	 	}
	 	scan = scan << 1;
	 }
 	scan = 0x01;
	PCIFR = 0X04;	//bajamos banderas de interrupción
	 
}

// emplearé el resgistro 2 para la interrupción externa
// pues usaré el conector J1 para tener desde PCINT 16 a PCINT 23 = registro 2

int main(void){
	DDRB = 0xFF;	// todos los LEDs como salida. 
	DDRK = 0x0F;	// PK(0:3) salida(1); PK(4:7) entrada (0)
	cli();
	PCICR = 0x04;	// pongo a 1 el pin 2  => habilito el registro 2
	PCMSK2 = 0xF0;	// habilitar interrupción en filas del keypad
	PCIFR = 0x04;
	sei();

	while (1){
		PORTK = 0X0F;
	}
}

