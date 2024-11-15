;Write an ARM assembly language program to transfer block of ten 32-bit numbers from code memory to data
;memory when the source and destination blocks are non-overlapping

	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R5,=DST
	LDR R1,=0
	MOV R3,#10
UP  LDR R2,[R0],#4
	ADDS R1,R4
	ADC R4,#0
	MOV R4,#0
	ADDS R1,R2
	ADC R4,#0
	SUBS R3, #1
	BNE UP
	STR R4,[R5]
	STR R1,[R5,#4]
here
	B here
SRC DCD 1,2,3,4,5,6,7,8,9,10
STOP
	B STOP
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
