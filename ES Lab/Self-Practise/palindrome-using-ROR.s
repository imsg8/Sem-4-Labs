;palindrome
	AREA RESET, CODE, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R1,[R0]
	LDR R4,=DST
	MOV R5,#5
	MOV R6,#28
	MOV R7,#0
	MOV R8,#0
	MOV R9,#1
	
B1	SUB R5,#1
	CMP R5,#0
	BEQ STOP1
	MOV R2,R1
	MOV R3,R1
	ROR R2,R6
	ROR R3,R7
	AND R11,R2,#0XF
	AND R12,R3,#0XF
	SUB R6,#4
	ADD R7,#4
	CMP R11,R12
	BEQ B1
	STR R8,[R4]
STOP
	B STOP
STOP1
	STR R9,[R4]
	B STOP
SRC DCD 0X12344327
	AREA mydata, DATA, READWRITE
DST	DCD 0
	END
