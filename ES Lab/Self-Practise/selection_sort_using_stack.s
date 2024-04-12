;THANKS A LOT  Sankalp Katyayanan ( @sank-k0904 ) for providing this code
  AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R1,=0X5
	LDR R2,=0X3
	LDR R3,=0X2
	LDR R4,=0X4
	LDR R5,=0X1
	LDR R6,=0X7
	LDR R7,=0X8
	LDR R8,=0X6
	LDR R9,=0X9
	LDR R10,=0X10
	STMIA R13!,{R1-R10}
	MOV R3,#0;i INDEX
	MOV R4,#0;j INDEX
	MOV R0,R13; POINTING AT THE ADDRESS OF ith VALUE
L3	MOV R1,R0;MAX INDEX
	MOV R2,R0
	SUB R2,#4;ADDRESS OF jth ELEMENT WHICH IS 4 BYTES BELOW THE ith ELEMENT
	ADD R4,R3,#1 ; IS MEANT TO ACT AS COUNTER FOR J LOOP SO J=i+1
L1	LDMDB R1,{R5};GIVE VALUE AT A[MAX] LOCATION TO R5
	LDMDB R2,{R6};GIVE VALUE AT JTH LOCATION TO R6
	CMP R5,R6
	BHS L2;IF A[MAX]>A[J] 
	MOV R1,R2;MAKE MAX INDEX POINT J
L2	SUB R2,#4; GO TO THE NEXT JTH ELEMENT
	ADD R4,#1;INCREASE INDEX j
	CMP R4,#10; TO CHECK IF THE INNER J LOOP ENDS BASICALLY N-1 ONLY COZ AS IT REACHES 10 IT WON'T LOOP AGAIN
	BNE L1
	LDMDB R0!,{R7};IF WE LOOK AT STACK I IS POINTING AT BLANK LOCATION SO FIRST WE DECREMENT IT AND GIVE THAT ADDRESS(R0 HOLDS
				  ;ADDRESS TO A[I] NOT VALUE)TO R7
				  ;MAKE THE NEW ADDRESS AS THE CURRENT
	LDMDB R1!,{R8};NOW WE WILL GO TO THE TRUE MAXIMUM VALUE WHICH IS ONE DOWN THE CURRENT R1 LOCATION USING LDMDB AND GIVE THAT
				  ; VALUE TO R8
	STM R0,{R8}
	STM R1,{R7}
	ADD R3,#1;INCREMENT I
	CMP R3,#9;TO CHECK FOR I INDEX LOOP BASICALLY N-2
	BNE L3
	
	
	
STOP
	B STOP
ARR DCD 0X5,0X1,0X3,0X2,0X4
	END
