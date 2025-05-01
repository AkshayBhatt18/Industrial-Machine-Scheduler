#include"I2C_HEADER.H"

extern unsigned char f2;

void EINT2_HANDLER(void)__irq
{
	f2++;
	if(f2==7)
		f2=0;
	EXTINT|=4;					// next int 
	VICVectAddr=0;
}


