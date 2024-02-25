#include<LPC17xx.h>
unsigned int i,j,sw;

int main(void){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0=0X0;
	LPC_PINCON->PINSEL1=0X0;
	LPC_GPIO0->FIODIR=0XFF<<15|0<<10;
	i=0;
	while(1){
			sw=LPC_GPIO0->FIOPIN>>10;
			sw&=1;
			LPC_GPIO0->FIOPIN=(i%256)<<(15);
			if(sw==1)
				i++;
			else
				i--;
			for(j=0;j<10000;j++);
	}
}
