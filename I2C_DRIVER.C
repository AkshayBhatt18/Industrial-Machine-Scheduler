#include<lpc21xx.h>
#include"I2C_HEADER.H"

void I2C_INIT(void)
{
	PINSEL0|=0x50;		//0.2->sclk,0.3->sda
	I2SCLH=I2SCLL=75;	//100kbps
	I2CONCLR=(1<<6);	//i2en=1
}

#define SI ((I2CONSET>>3)&1)
void I2C_SEND(char sa,char mr , char data)
{
		//1.generate start coni
		start();
		
		// 2. send sa+w & check ack
		I2DAT=sa;			//as+w
		I2CONCLR=(1<<3);
	while(SI ==0);
		if(I2STAT==0x20)
		{
			UART0_TX_STRING("ERR : SA+W \r\n");
			stop();
		}
		
		//3. send mr & check ack
		I2DAT=mr;			//as+w
		I2CONCLR=(1<<3);
	while(SI ==0);
		if(I2STAT==0x30)
		{
			UART0_TX_STRING("ERR : m/r \r\n");
			stop();
		}
		
		//4.send data & check ack
		I2DAT=data;			//as+w
		I2CONCLR=(1<<3);
	while(SI ==0);
		if(I2STAT==0x30)
		{
			UART0_TX_STRING("ERR : data \r\n");
			stop();
		}
		
		//5. generate stop condi
		stop();
}

// receving 1byte data

char I2C_READ(char sa,char mr)
{
	char temp=0;
	//1. generate start condi
	start();
	
	//2. send sa+w & ack 
	I2DAT=sa^1;		// send sa+w
	I2CONCLR=(1<<3);	//si=0
	while(SI==0);
	if(I2STAT==0x20)
	{
		UART0_TX_STRING("ERR sa+w \r\n");
		stop();
	}
	
	//3. send mr &  ack
	I2DAT=mr;		// send mr
	I2CONCLR=(1<<3);	//si=0
	while(SI==0);
	if(I2STAT==0x30)
	{
		UART0_TX_STRING("ERR sa+w \r\n");
		stop();
	}
	
	//4. generate restart condi
	start();
	
	//.5 send sa+r & ack
	I2DAT=sa;		// send sa+r
	I2CONCLR=(1<<3);	//si=0
	while(SI==0);
	if(I2STAT==0x48)
	{
		UART0_TX_STRING("ERR sa+r \r\n");
		stop();
	}
	
	//6. receive data
	I2CONCLR=(1<<3);
	while(SI==0);
	temp=I2DAT;
	
	//.7 generate stop condi
	stop();
	
	//8. return data
	return temp;
	
}


void start(void)
{
I2CONSET=(1<<5);		//sta=1
I2CONCLR=(1<<3);		//si=0
while (SI==0);			//monitor si
I2CONCLR=(1<<5);		//sta=0
}

void stop(void)
{
	I2CONSET=(1<<4);		//sto=1
	I2CONCLR=(1<<3);		//si=0
}
