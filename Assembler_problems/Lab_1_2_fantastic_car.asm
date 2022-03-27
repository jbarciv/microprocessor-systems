;**************************************************************
;*  Lab practice 1
;*  Exercise 2
;*  Author: Josep Barbera
;*  Date: 20/03/2022
;*
;*  Shifting the light alternately from right to left between 
;*  the 8 LEDs with a software delay of 0.1 s between each 
;*  displacement.
;**************************************************************

Init:
	LDI r16, 0xff   ; ob11111111
	OUT DDRC, r16
    LDI r16, 0x01   ; 0b00000001
    LDI r17, 0x80   ; 0b10000000
    LDI r18, 0x64   ; milliseconds to wait (0x64=100)

Start:
    RCALL Light_Left    ; moving light to left
    RCALL Light_Right   ; moving light to right
    RJMP Start

Light_Left:
    OUT PORTC, r16  ; LSB lighting
    ROL r16         ; shifting one position to the left
    RCALL Delay     
    CP r16, r17     ; comparing with 0b10000000
    BRNE Light_Left ; if not equal repeat again
    ROL r17         ; if equal shift 0b10000000 to 0b00000001
    RET
  
Light_Right:
    OUT PORTC, r16   ; MSB lighting
    ROR r16          ; shifting one position to the right
    RCALL Delay
    CP r16, r17      ; comparing with 0b00000001
    BRNE Light_Right ; if not equal repeat again
    ROR r17          ; if equal shift 0b00000001 to 0b10000000
    RET

Delay:                    ; r18 has the milliseconds to wait
    PUSH r16              ; saving r16 in the stack 
    PUSH r17              ; saving r17 in the stack 
    Loop_1:               ; 1 millisecond loop
        LDI r16, 10
        Loop_2:           ; 100 microsecond loop
            LDI r17, 100
            Loop_3:       ; 8 cycle loop = 1 microseconds
                NOP
                NOP
                NOP
                NOP
                NOP
                DEC r17
                BRNE Loop_3
            DEC r16
            BRNE Loop_2
        DEC r18
        BRNE Loop_1
    POP r17                ; getting r17 from the stack
    POP r16                ; getting r16 from the stack
    RET
