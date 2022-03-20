;**************************************************************
;*  Academic Exercise 2
;*  Author: Josep Barbera
;*  Date: 20 March 2022
;*  
;*  A subroutine that allows delays of up to 255 milliseconds 
;*  by blocking, to which the number of milliseconds to wait 
;*  is passed in register r16.
;*  We are assuming a clock of 8MHz.
;**************************************************************

 Delay:
        PUSH r16                ; saving r16 in the stack 
        PUSH r17                ; saving r17 in the stack 
        Loop_1:                 ; 1 millisecond loop
            LDI r16, 10
            Loop_2:             ; 100 microsecond loop
                LDI r17, 100
                Loop_3:         ; 8 cycle loop = 1 microseconds
                    NOP
                    NOP
                    NOP
                    NOP
                    NOP
                    DEC r17     ; please note that these 
                    BRNE Loop_3 ; instructions spend time (3 
                DEC r16         ; cycles per 800) as it is a    
                BRNE Loop_2     ; small error, we despise it
            DEC r18
            BRNE Loop_1
        POP r17                 ; getting r17 from the stack
        POP r16                 ; getting r16 from the stack
        RET
