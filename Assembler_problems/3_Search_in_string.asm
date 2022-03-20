;***************************************************************
;*  Academic Exercise 3
;*  Author: Josep Barbera
;*  Date: 20 March 2022
;*  
;*  Subroutine that searches for a given character within a 
;*  character string (ending with the character '\0'). 
;*  Parameter: a pointer to the string and the character to 
;*  search for in register r16. 
;*  Return: a signed integer in registers r16 (LSB) and 
;*  r17 (MSB), which will be -1 if the character is not 
;*  found, or the position within the string if it is found. 
;*  Pointer to the string is passed through register X (r27:r26)
;***************************************************************

Look_for_char:
; indirect loading of the string character to be compared
    LD r17, X+      
    TST r17             ; if string character is cero
    BREQ NoFound        ; we have finished
    CP r17, r16         ; if not, we make the comparison
    BREQ Found
    RJMP Look_for_char
Found:
    MOV r16, r26
    MOV r17, r27
    RET
NoFound:
    LDI r16, 0xFF       ; character not found
    LDI r17, 0xFF       ; we load a -1 in r17:r16
    RET
