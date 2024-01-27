	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =VAL1 
	LDR R1, =VAL2 
	LDR R6, =QUO
	LDR R7, =REM
	LDR R2, [R0] ;dividend
	LDR R3, [R1] ;divisior
	MOV R4,#0
L2	CMP R2, R3
	BCC L1
	SUBS R2,R3
	ADD	R4,#1
	B L2
L1	STR R4, [R6]
	STR R2, [R7]
STOP
	B STOP
VAL1 DCD 15
VAL2 DCD 3
	AREA mydata, DATA, READWRITE
QUO DCD 0
REM DCD 0
	END