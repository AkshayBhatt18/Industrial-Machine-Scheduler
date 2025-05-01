#include<lpc21xx.h>

extern void I2C_INIT(void);

extern void I2C_SEND(char sa,char mr , char data);

extern char I2C_READ(char sa,char mr);

extern void start(void);

extern void stop(void);

extern void UART0_INIT(unsigned int boud);

extern void UART0_TX_STRING( char *p);

extern void UART0_TX(unsigned char data);

extern void LCD_DATA(unsigned char data);

extern void LCD_CMD(unsigned	 char cmd);

extern void LCD_INIT(void);

extern void LCD_STRING(char *p);

extern void delay_ms(unsigned int ms);
