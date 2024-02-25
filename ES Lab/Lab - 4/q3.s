	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA MYCODE,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	LDR R2,[R0]
	MOV R6,#0
L2	CMP R2,#10
	BCC L1
	SUBS R2,#10
	ADD R3,#1
	B L2
L1	STRB R2,[R1],#1
	ADD R4,#1
	MOV R2,R3
	MOV R3,#0
	CMP R2,#0
	BNE L2
	LDR R0,=DST
L3	LDRB R5,[R0],#1
	LSL R5,R6
	ADD R7,R5
	ADD R6,#4
	SUBS R4,#1
	BNE L3
	STR R7,[R1]
STOP B STOP
SRC DCD 0x0016
	AREA D,DATA,READWRITE
DST DCD 0
	END