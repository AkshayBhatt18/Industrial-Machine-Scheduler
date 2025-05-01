#include<lpc21xx.h>
#include"HEADER.H"
#include<string.h>

////////////////////////////////////// LCD FUN ////////////////////////////
//void LCD_STRING(char *p)
//{
//	int i;
//	for(i=0;p[i];i++)
//	LCD_DATA(p[i]);
//}  

////////////////////////////////////// UART0 FUN //////////////////////////

#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)

void UART0_TX(unsigned char data)
{
	U0THR=data;
	while(THRE==0);
}

unsigned char UART0_RX(void )
{
while(RDR==0);
	return U0RBR ;
}

void UART0_TX_STRING( char *p)
{
int i=0;
	while(p[i])
	{
	UART0_TX(p[i++]);
	}
}

void UART0_RX_STRING(unsigned char *a ,int len)
{
int i;	
for(i=0;i<len-1;i++)
	{
		a[i]=UART0_RX();
		if(a[i]=='\r')
		break;
	}
	a[i]='\0';
}

void UART0_INTEGER(int num)
{
char arr[10];
	sprintf(arr,"%d",num);
	UART0_TX_STRING(arr);
	LCD_STRING(arr);
}

void UART0_FLOAT(float num)
{
char arr[10];
	sprintf(arr,"%1.f",num);
	UART0_TX_STRING(arr);
	LCD_STRING(arr);
}
