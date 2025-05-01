#include"I2C_HEADER.H"

extern unsigned char f0,f2;

void EINT0_HANDLER(void)__irq
{
	f0=f0^1;
	f2=0;
	EXTINT|=1;					// next int 
	VICVectAddr=0;
}

	/*
	led (1<<17)
	f0=f0^1;
	if(f0)
		IOCLR0|=lcd1;
	else
		IOSET0|=lcd1;

	EXTINT|=1;					// next int 
	VICVectAddr=0;*/
