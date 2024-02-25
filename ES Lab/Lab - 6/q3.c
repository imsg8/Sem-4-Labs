#include<LPC17xx.h>
unsigned int i,j,sw;

int main(void){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0=0X0;
	LPC_PINCON->PINSEL1=0X0;
	LPC_GPIO0->FIODIR=0XFF<<15|0<<10;
	i=1;
	while(1){
			sw=LPC_GPIO0->FIOPIN>>10;
			sw&=1;
			LPC_GPIO0->FIOPIN=(i)<<(15);
			if(sw==1)
			{
				i=i<<1;
				if(i==256)
					i=1;
			}
			else
			{
				i=i>>1;
				if(i==0)
					i=0x80;
			}
			for(j=0;j<10000;j++);
	}
}
