#include<lpc17xx.h>
unsigned int i=0, j=0, K;
unsigned int tohex[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
long int arr[4] = {0,0,0,0};
void inittimer(){
	LPC_TIM0->CTCR=0X0;
	LPC_TIM0->TCR=0X0;
	LPC_TIM0->PR=2999;
}
void delay(int milliseconds){
	LPC_TIM0->TCR=0x2;
	LPC_TIM0->TCR=0X1;
	while(LPC_TIM0->TC<milliseconds);
	LPC_TIM0->TCR=0x0;
}
int main(){
	SystemInit();
  inittimer();	
	SystemCoreClockUpdate();
	LPC_PINCON -> PINSEL0 = 0X0;
	LPC_GPIO0 -> FIODIR=0X400;
	K=LPC_GPIO0->FIOPIN>>10;
	K&=1;

	LPC_GPIO0 -> FIODIR = 0xFF << 15;
	LPC_GPIO1 -> FIODIR = 0xF << 23;
	while(1){
		if(K==1){
		for(arr[3]=0;arr[3]<=9;arr[3]++){
			for(arr[2]=0;arr[2]<=9;arr[2]++){
				for(arr[1]=0;arr[1]<=9;arr[1]++){
					for(arr[0]=0;arr[0]<=9;arr[0]++){
						for(i=0;i<4;i++){
							LPC_GPIO1->FIOPIN=i<<23;
							LPC_GPIO0->FIOPIN=tohex[arr[i]]<<15;
							delay(1000);
						}
						
					}
				}
			}
		}
	}
		else{
			for(arr[3]=9;arr[3]<=0;arr[3]--){
			for(arr[2]=9;arr[2]<=0;arr[2]--){
				for(arr[1]=9;arr[1]<=0;arr[1]--){
					for(arr[0]=9;arr[0]<=0;arr[0]--){
						for(i=0;i<4;i++){
							LPC_GPIO1->FIOPIN=i<<23;
							LPC_GPIO0->FIOPIN=tohex[arr[i]]<<15;
							delay(1000);
						}
					}
				}
			}
		}
		}
	}
}