#include<lpc21xx.h>
#include"I2C_HEADER.H"

extern void EINT0_HANDLER(void);
extern void EINT1_HANDLER(void);
extern void EINT2_HANDLER(void);


void config_vic_eint(void)
{
PINSEL0|=(0xA<<28);					//eint0,1
PINSEL1|=1;									// eini 3
	
	EXTMODE|=7;
	EXTPOLAR=0;
	
	VICIntSelect|=(1<<14);		// eint0 is fio
	
	VICVectCntl0|=15|(1<<5);
	VICVectAddr0=(unsigned int)EINT1_HANDLER;
	
	VICVectCntl1|=16|(1<<5);
	VICVectAddr1=(unsigned int)EINT2_HANDLER;

	VICIntEnable=(1<<14)|(1<<15)|(1<<16);
}
