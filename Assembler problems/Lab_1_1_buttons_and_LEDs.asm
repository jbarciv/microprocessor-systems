;**************************************************************
;*  Lab practice 1
;*  Exercise 1
;*  Author: Josep Barbera
;*  Date: 20 March 2022
;*  
;*  Display the status of 8 buttons connected to two different 
;*  I/O ports (Ports A and B) on 8 LEDs connected to another 
;*  I/O port continuously (Port C). 
;**************************************************************

Init: 
    ; Port E configuration (as Input) -> DDRE
    ; Input pins: 10000111=0x87. In DDRA, inputs are '0's
    ; ~(0x87) = 0x78 = 0b01111000 for ANDI instruction
    IN r16, DDRE    ; checking current DDRE status
    ANDI r16, 0x78  
    OUT DDRE, r16   ; setting to '0' the desired pins

    ; Port J configuration (as Input) -> DDRJ
    ; Input pins: 00001111=0x0f. In DDRJ, inputs are '0's
    ; ~(0x0f)=0xf0=0b11110000 for ANDI
    LDS r16, DDRJ    ; checking current DDRJ status
    ANDI r16, 0xf0  
    STS  DDRJ, r16  ; setting to '0' the desired pins

    ; Port C configuration (as Output) -> DDRC
    ; Output pins: 11111111=0xff. In DDRC, outputs are '1's
    LDI r16, 0xff
    OUT DDRC, r16   ; setting to '1' all DDRC pins

Start:
    IN r16, PINE    ; reading PINA
    ANDI r16, 0x87  ; removing undesired pins
    RCALL LightE    
    LDS r17, PINJ    ; reading PINJ
    ANDI r17, 0x0f  ; removing undesired pins
    RCALL LightJ
    OR r16, r17     ; adding LSB and MSB for output
    OUT PORTC, r16  ; setting PORTC according to inputs
    RJMP Start

LightE:
    ; Returns in r16 the state of the first four 
    ; push-buttons encoded in binary on the 4 LSB
    MOV r17, r16    ; copying buttons status
    ANDI r17, 0x07  ; saving the three LSB
    ROR r16         ; moving PA7 four positions to the right
    ROR r16
    ROR r16
    ROR r16
    ANDI r16, 0x08  ; saving the fourth LSB
    OR r16, r17     ; adding fourth LSB whit the other three
    RET             

LightJ:
    ROL r17
    ROL r17
    ROL r17
    ROL r17
    RET