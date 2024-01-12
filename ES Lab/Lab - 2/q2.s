;Write an ARM assembly language program to transfer a 32-bit number from one location in the data memory
;to another location in the data memory

VAL1 DCD OxFFFF1111 , Ox12341111
VAL2 DCD OxABCD1234 , Ox12345678

DST DCD 0

LDR R0, =VAL1
LDR R1, =VAL2
LDR R2,[R0],#4
LDR R3,[R1],#4
ADDS R4,R2,R3
LDR R5,=DST
STR R4,[R5],#4
LDR R2,[R0]
LDR R3,[R1]
ADCS R4,R2,R3
STR R4,[R5]
