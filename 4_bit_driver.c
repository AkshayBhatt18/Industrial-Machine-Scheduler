#include<lpc21xx.h>
#include"HEADER.H"

void LCD_DATA(unsigned char data)
{
	unsigned int temp;
	IOCLR1=0xfe<<16;
	temp=(data&0xf0)<<16;
	IOSET1=temp;
	
	IOSET1=1<<17;			//rs=1
	IOCLR1=1<<18;			//sw=1
	IOSET1=1<<19;			//en=1
	delay_ms(2);
	IOCLR1=1<<19;			//en=0
	
	//lower bit 
	
	IOCLR1=0xfe<<16;
	temp=(data&0x0f)<<20;
	IOSET1=temp;

	IOSET1=1<<17; 		//rs=1
	IOCLR1=1<<18;			//rw=1
	IOSET1=1<<19;			//en=1
	delay_ms(2);
	IOCLR1=1<<19;			//en=0
}

void LCD_CMD(unsigned	 char cmd)
{
	unsigned int temp;
//higher bit
	IOCLR1=0xfe<<16;
	temp=(cmd&0xf0)<<16;
IOSET1=temp;
	
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
	
// lower bit 
	
	IOCLR1=0xfe<<16;
	temp=(cmd&0x0f)<<20;
	IOSET1=temp;
	
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
}

void LCD_INIT(void)
{
	IODIR1=0xfe<<16;
	
	LCD_CMD(0x02);
	LCD_CMD(0x28);
	LCD_CMD(0x0e);
	LCD_CMD(0x01);
}

void LCD_STRING(char *p)
{
	int i;
	for(i=0;p[i];i++)
		LCD_DATA(p[i]);
}
