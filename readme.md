# Tiny Second Display

This is a very tiny display to clone your PC screen.
![Big picture](01_doc/TinyDisplayBigPicture.jpg)
Link to youtube is bellow:  
[![Youtube](http://img.youtube.com/vi/grzDsh2M5ko/0.jpg)](http://www.youtube.com/watch?v=grzDsh2M5ko)
<img src="01_doc/picture_00.jpg" alt="代替テキスト" height="300px">
<img src="01_doc/picture_01.jpg" alt="代替テキスト" height="300px">

## Environment
* Atmel Studio 7.0  
or
* avr-gcc (makefile)
	* make
	* sudo avrdude -c avrispv2 -P /dev/ttyACM0 -p m328p -U flash:w:hello.out:e


## Devices
* ATmega328P (not arduino)
* ST7735R Display

## PC Side
### Software needed
* python 2.7.x

### Install Libraries
* pip install PIL
* pip install pyserial
* pip install pyautogui

### How to Run
%> python tinyDisplayServer.py

### Note
* UART Baudrate is 2,000,000 bps


## Software Structure
![Software Structure](01_doc/TinyDisplaySoftwareStructure.jpg)


## Portmap
```
## IO

PORTA0 = 
PORTA1 = 
PORTA2 = 
PORTA3 = 
PORTA4 = 
PORTA5 = 
PORTA6 = 
PORTA7 = 
PORTB0 = 
PORTB1 = LCD_ST7735_DC
PORTB2 = LCD_ST7735_CS
PORTB3 = LCD_ST7735_MOSI
PORTB4 = 
PORTB5 = LCD_ST7735_SCK
PORTB6 = 
PORTB7 = 
PORTC0 = 
PORTC1 = 
PORTC2 = 
PORTC3 = 
PORTC4 = 
PORTC5 = 
PORTC6 = 
PORTC7 = 
PORTD0 = RX : IN
PORTD1 = TX : OUT
PORTD2 = 
PORTD3 = 
PORTD4 = 
PORTD5 = 
PORTD6 = 
PORTD7 = 


## Function

USART0 = COM
TIMER0 = System Timer (1msec)
TIMER1 = 
SIO = LCD_ST7735
```
