#include<lpc17xx.h>

unsigned int tohex[10]={0x66, 0x4F, 0x5B, 0x06};
unsigned int i=0, j=0;
int main(){
	LPC_PINCON->PINSEL3 = 0X0;
	LPC_PINCON->PINSEL0=0;
	LPC_PINCON->PINSEL1=0;
	
	LPC_GPIO0->FIODIR=0Xff<<15;
	LPC_GPIO1->FIODIR=0Xf<<23;
	
	while(1){
		LPC_GPIO0->FIOCLR=0XFF<<15;
		for (i=0;i<=4;i++){
			LPC_GPIO1->FIOPIN= (i-1)<<23;
			LPC_GPIO0->FIOPIN= tohex[i-1]<<15;
			for(j=0;j<10;j++);
		}
	}
}
