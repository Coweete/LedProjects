/*
 * btnInterupt.c
 *
 * Created: 2018-07-02 19:16:58
 *  Author: Jounne
 */ 
#include "btnInterrupt.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Leds/LedFunctions.h"
#include "uart/uart_communication.h"

#define LED_PIN PORTB5

uint8_t state = 0;
char Res[]="Interrupt";

void initBtns(){
	
	//Clear the PD2 Pin
	DDRD &= ~(1 << DDD2);
	//PD2 is now an input
	
	//LED PIN as output
	DDRB |= (1 << LED_PIN);
	
	//Turn on the Pull-up
	PORTD |= (1<<PORTD2);
	//PD2 Is now an input with pull-up enabled
	
	EICRA |= (1 << ISC00); //set INT0 to trigger on ANY logic change ! @TODO Only on high
	EIMSK |= (1 << INT0); //Turns on INT0
	
	sei(); //Turn on interrupts
}

/************************************************************************/
/* The interrupt                                                        */
/************************************************************************/
ISR(INT0_vect){
	switch (state)
	{
	case 0:
		led_blue();
		state++;
		break;
	case 1:
		led_green();
		state++;
		break;
	case 2:
		led_red();
		state = 0;
		break;
	default:
		state = 0;
		break;
	}
	_delay_ms(10);
}