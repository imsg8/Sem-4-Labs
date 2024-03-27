//Die Tossing
#include <LPC17xx.h>
#include<stdlib.h>
void lcd_init(void);
void write(int, int);
void inittime0(void);
void delay(int milliseconds);
void lcd_comdata(int, int);
void clear_ports(void);
void lcd_puts(unsigned int);
unsigned int num=0;
unsigned int a=0x30;

int main(void)
				{
	
				SystemInit();
				lcd_init();
				while(1){
						if(!(LPC_GPIO2->FIOPIN & 1<<12)){
								num=(rand()%6)+1;
								a=num+0x30;	
				lcd_comdata(0x80, 0);
				delay(800);
				lcd_puts(a);
						}
			}
					
				}
void lcd_init()
			{
			LPC_PINCON->PINSEL1 &= 0xFC003FFF; //P0.23 to P0.28 - CND
			LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28;
			clear_ports();
			delay(3200);
			lcd_comdata(0x33, 0);
			delay(30000);
			lcd_comdata(0x32, 0);
			delay(30000);
			lcd_comdata(0x28, 0); 
			delay(30000);
			lcd_comdata(0x0c, 0);
			delay(800);
			lcd_comdata(0x06, 0);
			delay(800);
			lcd_comdata(0x01, 0);
			delay(10000);
			return;
			}
void lcd_comdata(int temp1, int type)
		{
		int temp2 = temp1 & 0xf0;
		temp2 = temp2 << 19;
		write(temp2, type);
		temp2 = temp1 & 0x0f;
		temp2 = temp2 << 23;
		write(temp2, type);
		delay(100);
		return;
		}
		
void inittime0(){
		LPC_TIM0->CTCR = 0x0;
		LPC_TIM0->TCR = 0x2;
		LPC_TIM0->PR = 2999;
}

void delay(int milliseconds){
		LPC_TIM0->TCR = 0x2;
		LPC_TIM0->TCR = 0x1;
		while(LPC_TIM0->TC < milliseconds);
		LPC_TIM0->TCR = 0x0;
}
	
		
void write(int temp2, int type) 
			{
			clear_ports();
			LPC_GPIO0->FIOPIN = temp2; 
			if(type==0)
			LPC_GPIO0->FIOCLR = 1<<27;
			else
			LPC_GPIO0->FIOSET = 1<<27;
			LPC_GPIO0->FIOSET = 1<<28; 
			delay(25);
			LPC_GPIO0->FIOCLR = 1<<28; 
			return;
			}
		
void clear_ports(void)
		{
		LPC_GPIO0->FIOCLR = 0x0F<<23; 
		LPC_GPIO0->FIOCLR = 1<<27; 
		LPC_GPIO0->FIOCLR = 1<<28; 
		return;
		}
void lcd_puts(unsigned int buf1)
{
		lcd_comdata(buf1, 1);
	  return;
}
