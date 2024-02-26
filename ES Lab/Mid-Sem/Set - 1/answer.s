;Using subroutine, calculate the factorial of all numbers in array and store it in memory location.

	AREA RESET, DATA, READONLY
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
	LDR R1,=DST
	MOV R2,#6
L1	CMP R2,#0
	BEQ BREAK
	LDR R3,[R0],#4
	MOV R6,#1
	BL FACT
	STR R6,[R1],#4
	SUB R2,#1
	B L1
BREAK
STOP B STOP
FACT 
L2	CMP R3,#1
	BEQ B1
	MUL R6,R3
	SUB R3,#1
	B L2
B1 	BX LR
SRC DCD 5,4,8,7,9,6
	AREA mydata, DATA, READWRITE
DST DCD 0,0,0,0,0,0
	END
