/*
 * adc_functions.c
 *
 * Created: 2018-07-09 17:23:20
 *  Author: User
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart/uart_communication.h"



void adc_init(){
	
	ADMUX |= (1 << REFS0) | (1 << MUX0);
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE) | (1 << ADIE) | (1 << ADPS2) | (1 <<ADPS1);
	sei();
}

ISR(ADC_vect){
	USART_putstring("ADC_INTERRUPT");
}