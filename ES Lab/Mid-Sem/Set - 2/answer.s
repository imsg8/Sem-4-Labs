;using subroutine, compare two numbers and find the smallest number in array.

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
	
	MOV R8,#6 ;counter
	LDR R2,[R0],#4 ;first as smallest ele, and checks first with all elements
	
LP	SUB R8,#1
	CMP R8,#0
	BEQ brk
	LDR R3,[R0],#4 ;will get second element
	CMP R2,R3
	BLT LP
	MOV R2,R3
	B LP
brk	STR R2,[R1]
STOP B STOP            
SRC DCD 0x33,0x15,0x54,0x65,0x88,0x3
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
