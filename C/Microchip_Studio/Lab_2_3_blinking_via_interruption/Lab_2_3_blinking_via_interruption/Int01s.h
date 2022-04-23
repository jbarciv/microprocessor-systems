/*
 *  Int01s.h
 *
 *  Created: 15/03/2022 15:04:26
 *  Author: Yago Tarroja
 */ 


#ifndef INT01S_H_
#define INT01S_H_

/*/////////////////////////////////////////////////////////////
// This functions give support for 0.1s periodic interrupts */ 

/*/ Call setupPeriodicInt() during your program configuration */
void setupPeriodicInt();

/*/ Call setPeriodicIntCallback(function_pointer) to set the
// function to be called in every periodic interrupt */
void setPeriodicIntCallback( void (*fptr)() );


#endif /* INT01S_H_ */