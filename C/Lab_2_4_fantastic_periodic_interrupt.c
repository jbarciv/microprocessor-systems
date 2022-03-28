/*
 * coche_fantastico_interrupciones.c
 *
 * Created: 22/03/2022 16:51:55
 * Author : General
 */ 

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
