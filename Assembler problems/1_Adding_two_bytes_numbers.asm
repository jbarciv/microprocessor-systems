;**************************************************************
;*  Academic Exercise 1
;*  Author: Josep Barbera
;*  Date: 20 March 2022
;*  
;*  A code that adds two two-byte numbers placed in memory 
;*  locations SumA and SumB and leaves the result in 
;*  memory locations Res (3 bytes). 
;**************************************************************

Adding:
    LDS r16, SumA       ; lower part
    LDS r17, SumB
    ADD r16, r17
    STS Res, r16
    LDS r16, SumA + 1   ; upper part
    LDS r17, SumB + 1
    ADC r16, r17
    STS Res + 1, r16
    LDI r16, 0          
    ADC r16, r16        ; for carry saving
    STS Res + 2, r16