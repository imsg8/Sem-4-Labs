	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA MY,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	MOV R2,#4
	MOV R3,#1
	MOV R4,#0
	MOV R7,#10
L	LDRB R5,[R0],#1
	AND R6,R5,#0xF
	MLA R4,R6,R3,R4
	MUL R3,R7
	AND R6,R5,#0XF0
	LSR R6,#4
	MLA R4,R6,R3,R4
	MUL R3,R7
	SUBS R2,#1
	BNE L
	STR R4,[R1]
STOP B STOP
SRC DCD 0x00000098
	AREA D,DATA,READWRITE
DST DCD 0
	END