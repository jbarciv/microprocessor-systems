/*
 *  Int01s.c
 *
 *  Created: 15/03/2022 15:03:58
 *  Author: Yago Tarroja
 */ 

#include <stddef.h>
#include <avr/interrupt.h>
#include "Int01s.h"

void (*functionPointer)();

void setupPeriodicInt() {
  cli();
  // Timer 5 mode CTC counting up to 3125 interrupting on OCRA match
  TCCR5A = 0x00; 
  TCCR5B = 0x0C;
  OCR5A  = 3124;
  TIMSK5 = 0x02;
  sei();  
}

void setPeriodicIntCallback( void (*fptr)() ) {
  functionPointer = fptr;
}

ISR( TIMER5_COMPA_vect ) {
  if (functionPointer != NULL) functionPointer();
}