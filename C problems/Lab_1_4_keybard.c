/*
 * teclado.c
 *
 * Created: 08/03/2022 17:52:55
 * Author : General
 */ 

#include <avr/io.h>

int main(void)
{
	DDRC = 0x0f;
	DDRA = 0xff;
	int barrido=0x01;
	int i;
	while (1)
	{	
		for (i=0 ; i<3 ; i++)
		{
			PORTC = barrido;
			if((PINC & 0xf0))
			{
				PORTA = PORTC;
			} 
			barrido = barrido << 1;
		}
		barrido = 0x01;
	}
}



