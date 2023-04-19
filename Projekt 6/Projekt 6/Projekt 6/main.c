/*
 * Projekt 6.c
 *
 * Created: 05.05.2021 15:29:46
 * Author : Tadzik
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define P_C0 !(PINC & (1<<0))
#define P_C1 !(PINC & (1<<1))
#define P_C2 !(PINC & (1<<2))
#define P_C3 !(PINC & (1<<3))
#define P_C4 !(PINC & (1<<4))
#define P_C5 !(PINC & (1<<5))
#define P_C6 !(PINC & (1<<6))
#define P_C7 !(PINC & (1<<7))


int main(void)
{
	DDRA = 0x00;
	DDRC =  0x00;
	PORTC = 0xFF;
	DDRD = 0xFF;

	TCCR1A = 0b10100011;
	TCCR1B = 0b00011010;
	OCR1A = 39999;
	//OCR1B = 2666;

	int x;
    while (1) 
    {
	
	if (P_C0) x=0;
	if (P_C1) x=1;
	if (P_C2) x=2;
	if (P_C3) x=3;
	if (P_C4) x=4;
	if (P_C5) x=5;
	if (P_C6) x=6;
	if (P_C7) x=7;


	
		if (x==0)
		{
			OCR1B = 1999;
		}
		if (x==1)
		{
			OCR1B = 2333;
		}
		if (x==2)
		{
			OCR1B = 2666;
		}
		if (x==3)
		{
			OCR1B = 2999;
		}
		if (x==4)
		{
			OCR1B = 3333;
		}
		if (x==5)
		{
			OCR1B = 3666;
		}
		if (x==6)
		{
			OCR1B = 3999;
		}
		if (x==7)
		{

			ADMUX = 0b01000000;
			ADCSRA = 0b11000111;
			
			while (ADCSRA & 0b01000000);
			OCR1B = ADC*4000UL/1023;
			_delay_ms(50);
		}	
		
		}	
	}	