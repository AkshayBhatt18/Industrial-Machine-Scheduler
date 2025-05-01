#include"I2C_HEADER.H"

extern unsigned char f1;

void EINT1_HANDLER(void)__irq
{
	f1=1;
	EXTINT|=2;					// next int 
	VICVectAddr=0;
}
