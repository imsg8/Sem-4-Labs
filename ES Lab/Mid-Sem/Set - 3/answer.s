;find the 2s compliment of a number.

;convert a number into it's two's compliment
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler 0
	AREA mycode, CODE, READONLY
	ALIGN
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	LDR R2,[R0]
	MVN R3,#0xAB
	ADD R3,#1
	STR R3,[R1]
STOP B STOP
SRC DCD 0X43
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
