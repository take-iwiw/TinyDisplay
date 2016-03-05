/*
 * myStdio.c
 *
 * Created: 2016-03-02 9:41:48 PM
 *  Author: take-iwiw
 */ 

#include <avr/io.h>
#include "myRetarget.h"

#ifdef USE_CHAR_LCD
#include "../charLcd/charLcd.h"
#endif

#ifdef USE_UART0
#include "../uart0/uart0.h"
#endif

#ifdef USE_LCD_ST7735R_TEXT
#include "../lcdST7735R_SPI/lcdST7735R_SPI.h"
#endif


void stdioInit()
{
#ifdef USE_CHAR_LCD
	charLcdInit();
#endif
#ifdef USE_UART0
	uart0Init();
#endif
#ifdef USE_LCD_ST7735R_TEXT
	lcdST7735R_init();
#endif
}

char putchar(char c)
{
#ifdef USE_CHAR_LCD
	charLcdPutchar(c);
#endif
#ifdef USE_UART0
	uart0Send(c);
#endif
#ifdef USE_LCD_ST7735R_TEXT
	lcdST7735R_putchar(c);
#endif
	return c;
}

char getchar()
{
#ifdef USE_UART0
	return uart0Recv();
#endif
	return '\0';
}

uint8_t getcharTry(char *c)
{
#ifdef USE_UART0
	if(isUart0Recved() != 0) {
		*c = uart0Recv();
		return 1;
	} else {
		return 0;
	}
#endif
	return 0;
}

void print(const char *str)
{
	while(*str != '\0') {
		putchar(*str);
		str++;
	}
}

void printDec(const uint8_t dec)
{
	putchar('0' + dec/100);
	putchar('0' + (dec%100)/10);
	putchar('0' + (dec%10));
	putchar(' ');
}

void printHex(const uint8_t hex)
{
	uint8_t upper = (hex >> 4) & 0x0f;
	uint8_t lower = hex & 0x0f;
	if(upper < 10) {
		putchar('0' + upper);
	} else {
		putchar('A' + upper-10);
	}
	if(lower < 10) {
		putchar('0' + lower);
		} else {
		putchar('A' + lower-10);
	}
	putchar(' ');
}

void printDecPos(const uint8_t dec, const uint8_t x, const uint8_t y)
{
#ifdef USE_CHAR_LCD	
	charLcdSavePosition();
	charLcdPosition(x, y);
#endif
#ifdef USE_UART0
	uart0Send('\r');
	if(y != 0){ uart0Send('\n'); }
	for(int i=0; i<x;i++) {uart0Send(0x1b); uart0Send('['); uart0Send('C');}
#endif
#ifdef USE_LCD_ST7735R_TEXT
	lcdST7735R_saveCurPos();
	lcdST7735R_setCurPos(x, y);
#endif

	printDec(dec);

#ifdef USE_CHAR_LCD
	charLcdLoadPosition();
#endif
#ifdef USE_LCD_ST7735R_TEXT
	lcdST7735R_loadCurPos();
#endif
}

void printPos(const char *str, const uint8_t x, const uint8_t y)
{
	#ifdef USE_CHAR_LCD
	charLcdSavePosition();
	charLcdPosition(x, y);
	#endif
	#ifdef USE_UART0
	uart0Send('\r');
	if(y != 0){ uart0Send('\n'); }
	for(int i=0; i<x;i++) {uart0Send(0x1b); uart0Send('['); uart0Send('C');}
	#endif
	#ifdef USE_LCD_ST7735R_TEXT
	lcdST7735R_saveCurPos();
	lcdST7735R_setCurPos(x, y);
	#endif

	print(str);

	#ifdef USE_CHAR_LCD
	charLcdLoadPosition();
	#endif
	#ifdef USE_LCD_ST7735R_TEXT
	lcdST7735R_loadCurPos();
	#endif
}
