	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	MOV R2,#2
L	LDRB R3,[R0],#1
	LDRB R4,[R0],#1
	LSL R4,#4
	ADD R4,R3
	STRB R4,[R1],#1
	SUBS R2,#1
	BNE L
STOP B STOP
SRC DCD 0x01020304
	AREA D,DATA,READWRITE
DST DCD 0
	END
