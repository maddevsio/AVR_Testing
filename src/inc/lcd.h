#ifndef LCD__H
#define LCD__H

#include <avr/io.h>


#define LCD_DATA PORTD
#define LCD_DATA_DDR DDRD
 
#define LCD_CTRL PORTC
#define LCD_CTRL_DDR DDRC
 
#define LCD_RS  _BV( 0 )  
#define LCD_RW  _BV( 1 )  
#define LCD_E   _BV( 2 )  
 
#define lcdSetEnable()   LCD_CTRL |= LCD_E  
#define lcdSetRS()  LCD_CTRL |= LCD_RS 
#define lcdSetRW()  LCD_CTRL |= LCD_RW 
 
#define lcdClearEnable()  LCD_CTRL &= ~LCD_E  
#define lcdClearRS() LCD_CTRL &= ~LCD_RS 
#define lcdClearRW() LCD_CTRL &= ~LCD_RW 




#define LCD_CLR              _BV( 0 ) 
 
#define LCD_HOME             _BV( 1 ) 
 
#define LCD_MODE             _BV( 2 ) 
#define LCD_MODE_INC         _BV( 1 ) 
#define LCD_MODE_SHIFT       _BV( 0 ) 
 
#define LCD_ON               _BV( 3 ) 
#define LCD_ON_DISPLAY       _BV( 2 ) 
#define LCD_ON_CURSOR        _BV( 1 ) 
#define LCD_ON_BLINK         _BV( 0 )
 
#define LCD_SHIFT            _BV( 4 ) 
#define LCD_SHIFT_DISPLAY    _BV( 3 )
#define LCD_SHIFT_RIGHT      _BV( 2 )
 
#define LCD_FUNCTION         _BV( 5 ) 
#define LCD_FUNCTION_8BIT    _BV( 4 )
#define LCD_FUNCTION_2LINES  _BV( 3 )
#define LCD_FUNCTION_10DOTS  _BV( 2 )
 
#define LCD_SET_CGRAM_ADDR   _BV( 6 ) 
 
#define LCD_SET_DDRAM_ADDR   _BV( 7 ) 


void lcdInit( void );
void lcdPutChar( unsigned char c );
void lcdPrintLn( const char *str);
void lcdSetPos( unsigned char x, unsigned char y );

#endif