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
	LDR R10,=N
	LDR R1,[R10]
	SUB R1,R1,#1
	LDR R2,[R0],#4
	BL sm
	LDR R6,=DST
	STR	R2,[R6]
	
STOP
	B STOP
	
sm	push {LR}
	LDR R3,[R0],#4
	ADD r2,R2,R3
	SUB R1,#1
	CMP R1,#0
	BEQ pp
	B sm
	
pp pop {PC}

SRC DCD 10,3,4,5,6,7
N	DCD 6
	AREA mydata, DATA, READWRITE
DST	DCD 0
	END 
