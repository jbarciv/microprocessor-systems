;************************************************************
;* 	Lab Practice 2
;*  Exercise 1
;*  Author: Josep Barbera
;*  Date: 22/03/2022
;*
;* Changing the status of LEDs via button interrupts
;************************************************************

.org 0x00
JMP setup

;label obtained from the dependencies folder after 
.org INT7addr	;making a build in Microchip Studio
JMP rutina

; enter your own code from here so as not to disturb other 
.org INT_VECTORS_SIZE	;users who use interruptions 
setup:
	CLI
	LDI r16, 0x00
	OUT DDRE, r16
	LDI r16, 0xFF
	OUT DDRC, r16
	LDI r16, 0x80
	STS EICRB, r16
	OUT EIMSK, r16
	OUT EIFR, r16
	SEI

rutina:
	IN r17, PINC
	COM r17
	OUT PORTC, r17
	RETI