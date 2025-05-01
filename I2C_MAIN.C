#include"I2C_HEADER.H"

extern void config_vic_eint(void);

unsigned char f0,f1,f2;
unsigned char dec_to_hex(unsigned char num);
#define SW ((IOPIN0>>15)&1)

int main()
{
char min=0,hour=0,sec=0,day=0,date,month=1,year,num=0;
LCD_INIT();
I2C_INIT();
config_vic_eint();

while(1)
{
if(f0==1)
{
if(f2==0)
{
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STRING("SET MINUTE");
			LCD_CMD(0xc0);
			min=0;
						while(1)
						{
								LCD_CMD(0xc0);
								num=dec_to_hex(min);
								LCD_DATA((num/0x10)+48);
								LCD_DATA((num%0x10)+48);
//								LCD_STRING("f2=");
	//							LCD_DATA(f2+48);
								
								if(f1==1)
								{
											min++;
											f1=0;
								}
								if(min==60)
										min=0;
//								if(SW == 0)
//								{
//									while(SW==0);
//										break;
//								}
								if(f2!=0)
									break;
						}
			min=dec_to_hex(min);
			I2C_SEND(0xd0,0x01,min);
}	
//LCD_CMD(0x1);
//	LCD_STRING("f2=");
//	LCD_DATA(f2+48);
								
//delay_ms(4000);
//if(f2==1)
{
			
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STRING("SET HOURS");
			
			//delay_ms(100);
			//LCD_CMD(0xc0);
			hour=0;
						while(1)
						{
								LCD_CMD(0xc0);
								num=dec_to_hex(hour);
								LCD_DATA((num/0x10)+48);
								LCD_DATA((num%0x10)+48);
								LCD_STRING("f2=");
								LCD_DATA(f2+48);
					//			delay_ms(100);	
								if(f1==1)
								{
											hour++;
											f1=0;
								}
								if(hour==24)
										hour=0;
								LCD_STRING(" f2=");
								LCD_DATA(f2+48);
								
//								if(SW == 0)
//								{
//									while(SW == 0);
//									//f2++;	
//									break;
//								}
								if(f2!=1)
									//while(1);
									break;
						}
			hour=dec_to_hex(hour);
			I2C_SEND(0xd0,0x02,hour);
}
//if(f2==2)
{
			LCD_CMD(0x01);
			LCD_CMD(0x80);
		while(1)
		{
			LCD_CMD(0x80);
				LCD_STRING("24 HOUR");
				LCD_STRING("f2=");
				LCD_DATA(f2+48);
				if(SW == 0)
								{
									while(SW == 0);
										break;
								}				
			//if(f2!=2)
			//			break;
		}
}
//															LCD_CMD(0xc0);
//																		while(1)
//																		{
//																				LCD_CMD(0xc0);
//																				num=dec_to_hex(hour);
//																				LCD_DATA((num/0x10)+48);
//																				LCD_DATA((num%0x10)+48);
//																				
//																				if(f1==1)
//																				{
//																							hour++;
//																							f1=0;
//																		   	}
//																				if(hour==13)
//																						hour=0;
//																				if(f2!=0)
//																						break;
//																		}
//															hour=dec_to_hex(hour);
//															I2C_SEND(0xd0,0x02,hour);
//												}
if(f2==3)
{
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STRING("SET DAY");
			LCD_CMD(0xc0);
			day=0;
						while(1)
						{
								LCD_CMD(0xc0);
								num=dec_to_hex(day);
								LCD_DATA((num/0x10)+48);
								LCD_DATA((num%0x10)+48);
								LCD_STRING("f2=");
								LCD_DATA(f2+48);
								
								if(f1==1)
								{
											day++;
											f1=0;
								}
								if(day==8)
										day=0;
								if(SW == 0)
								{
									while(SW == 0);
										break;
								}
								//if(f2!=3)
									//	break;
						}
			day=dec_to_hex(day);
			I2C_SEND(0xd0,0x03,day);
}
if(f2==4)
{
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STRING("SET DATE");
			LCD_CMD(0xc0);
			date=1;
						while(1)
						{
								LCD_CMD(0xc0);
								num=dec_to_hex(date);
								LCD_DATA((num/0x10)+48);
								LCD_DATA((num%0x10)+48);
								LCD_STRING("f2=");
								LCD_DATA(f2+48);
									
							
							if(f1==1)
								{
											date++;
											f1=0;
								}
								if(date==32)
										date=1;
								if(SW == 0)
								{
									while(SW == 0);
										break;
								}
								//if(f2!=4)
									//	break;
						}
			date=dec_to_hex(date);
			I2C_SEND(0xd0,0x04,date);
}
if(f2==5)
{
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STRING("SET MONTH");
			LCD_CMD(0xc0);
			month=1;
						while(1)
						{
								LCD_CMD(0xc0);
								num=dec_to_hex(month);
								LCD_DATA((num/0x10)+48);
								LCD_DATA((num%0x10)+48);
								
								if(f1==1)
								{
											month++;
											f1=0;
								}
								if(month==13)
										month=1;
								if(SW == 0)
								{
									while(SW == 0);
										break;
								}
								//if(f2!=5)
									//	break;
						}
			month=dec_to_hex(month);
			I2C_SEND(0xd0,0x05,month);
}
if(f2==6)
{
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STRING("SET YEAR");
			LCD_CMD(0xc0);
			year=20;
						while(1)
						{
								LCD_CMD(0xc0);
								num=dec_to_hex(year);
								LCD_DATA((num/0x10)+48);
								LCD_DATA((num%0x10)+48);
								if(f1==1)
								{
											year++;
											f1=0;
								}
								if(year==40)
										year=20;
								if(SW == 0)
								{
									while(SW == 0);
										break;
								}
								//if(f2!=6)
									//	break;
						}
			year=dec_to_hex(year);
			I2C_SEND(0xd0,0x06,year);
}
}
else
{
LCD_CMD(0x80);
sec=I2C_READ(0xd1,0x00);
LCD_DATA((sec/0x10)+48);
LCD_DATA((sec%0x10)+48);
LCD_DATA(':');
min=I2C_READ(0xd1,0x01);
LCD_DATA((min/0x10)+48);
LCD_DATA((min%0x10)+48);
LCD_DATA(':');
hour=I2C_READ(0xd1,0x02);
LCD_DATA((hour/0x10)+48);
LCD_DATA((hour%0x10)+48);

LCD_CMD(0xc0);		
date=I2C_READ(0xd1,0x04);
LCD_DATA((date/0x10)+48);
LCD_DATA((date%0x10)+48);

LCD_DATA('-');
month=I2C_READ(0xd1,0x05);
LCD_DATA((month/0x10)+48);
LCD_DATA((month%0x10)+48);
LCD_DATA('-');

year=I2C_READ(0xd1,0x06);
LCD_DATA('2');
LCD_DATA('0');
LCD_DATA((year/0x10)+48);
LCD_DATA((year%0x10)+48);

day=I2C_READ(0xd1,0x03);
//LCD_DATA((day/0x10)+48);
//LCD_DATA((day%0x10)+48);

LCD_DATA(' ');
switch(day)
{
	case 0x01 : LCD_STRING("Mon"); break;
	case 0x02 : LCD_STRING("Tues"); break;
	case 0x03 : LCD_STRING("Wed"); break;
	case 0x04 : LCD_STRING("Thu"); break;
	case 0x05 : LCD_STRING("Fri"); break;
	case 0x06 : LCD_STRING("Sat"); break;
	case 0x00 : LCD_STRING("Sun"); break;
}
}	
}
}

unsigned char dec_to_hex(unsigned char num)
{
char i,j;
i=num/10;
j=num%10;
num=(i<<4)|j;
return num;
}
