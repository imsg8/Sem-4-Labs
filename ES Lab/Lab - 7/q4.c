#include<LPC17xx.h>

unsigned char tohex[16]={0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned int i=0,j=0,t,k=0,sw;
void inittimer()
{
	LPC_TIM0->CTCR=0;
	LPC_TIM0->TCR=2;
	LPC_TIM0->PR=2999;
}
void delay()
{
	LPC_TIM0->TCR=1;
	while(LPC_TIM0->TC<1000);
	LPC_TIM0->TCR=2;
}
int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	inittimer();
	LPC_GPIO0->FIODIR=0XFF<<15;
	LPC_GPIO1->FIODIR=0XF<<23;
	while(1)
	{
		sw=LPC_GPIO0->FIOPIN>>10 & 1;
		k=0;
		j=i%0x10000;
		for(k=0;k<4;k++)
			{
				LPC_GPIO1->FIOPIN=k<<23;
				LPC_GPIO0->FIOPIN=tohex[j%16]<<15;
				j=j/16;
				for(t=0;t<500;t++);
			}
			delay();
		if(sw)
			i++;
		else
			i--;
}
	}