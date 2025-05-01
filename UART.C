
#include<lpc21xx.h>
#include"header.h"

void UART0_INIT(unsigned int boud)
{
int a[]={15,60,30,15,15};
unsigned int PCLK,res;
PCLK = (a[VPBDIV%4]*1000000);
res = PCLK/(16*boud);

PINSEL0 |= 0x05; // set 0.0 txd0 and 0.1 rxd0
U0LCR= 0x83 ;		// 8N1 mode DLAB=1
U0DLL=res & 0xff;
U0DLM=(res>>8)&0xff;
U0LCR=0x03;
}


//extern void UART0_INIT(unsigned int boud);
//extern void UART0_TX_STRING( char *p);
//extern void UART0_INT(float num);
//extern void ADC_INIT(void);
////extern int ADC_READ(int ch_n);
//extern void LCD_DATA(unsigned char data);
//extern void LCD_CMD(unsigned	 char cmd);
//extern void LCD_INIT(void);
//extern void LCD_STRING(char *p);
//extern void delay_ms(unsigned int ms);
//extern unsigned char UART0_RX(void );

