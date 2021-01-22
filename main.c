/*
 * atmega128_servo_sg90_test.c
 *
 * Created: 2020-07-01 오후 5:07:46
 * Author : Yunseo Hwang
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd1602a_h68.h"

#define SERVO_DEG_0 450
#define SERVO_DEG_P90 700
#define SERVO_DEG_M90 250

void timer_init()
{
	TCCR1A = 0x82;
	TCCR1B = 0x1B;
	ICR1 = 4999;
	OCR1A = SERVO_DEG_0;
	TCNT1 = 0x00;
}

int main(void)
{
	struct lcd1602a_port lcd_port = {&DDRC, &DDRC, &PORTC, &PORTC};
	
	set_lcd_bit(4);	
	set_lcd_port(lcd_port);
	lcd_init(LCD_ROWS_MAX, LCD_COLS_MAX);
	
	DDRB = 0xFF;
	PORTB = 0x00;
	
	timer_init();
	
    while (1) 
    {
		lcd_move(0, 0);
		lcd_puts("-90 DEGREE");
		OCR1A = SERVO_DEG_M90;
		_delay_ms(1000);
		
		lcd_move(0, 0);
		lcd_puts("  0 DEGREE");
		OCR1A = SERVO_DEG_0;
		_delay_ms(1000);
		
		
		lcd_move(0, 0);
		lcd_puts("+90 DEGREE");
		OCR1A = SERVO_DEG_P90;
		_delay_ms(1000);
		
		
		lcd_move(0, 0);
		lcd_puts("  0 DEGREE");
		OCR1A = SERVO_DEG_0;
		_delay_ms(1000);
    }
}

