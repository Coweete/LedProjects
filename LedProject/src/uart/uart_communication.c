/*
 * uart_communication.c
 *
 * Created: 2018-07-09 18:55:23
 *  Author: Jounne
 */ 
#include <avr/io.h>
#include "uart_communication.h"

#define USART_BAUDRATE 9600
//#define BAUD_PRESCALE (((F_CPU /(USART_BAUDRATE * 16UL)))-1)
#define BAUD_PRESCALE ((F_CPU/16/USART_BAUDRATE)-1)

void init_usart(){
	UBRR0H = (BAUD_PRESCALE >> 8);
	UBRR0L = (BAUD_PRESCALE);
	//UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0B = (1 << TXEN0);
	UCSR0C = ((1<<UCSZ01) | (1<<UCSZ00));	
}

void USART_send(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0))){
		UDR0 = data;
	}
}

unsigned char USART_receive(void){
	while (!(UCSR0A & (1<<RXEN0)));
	return UDR0;
}

void USART_putString(char* StringPtr){
	while(*StringPtr != 0x00){
		USART_send(*StringPtr);
		StringPtr++;
	}
}

void test_send(){
	UDR0 = '8';
}