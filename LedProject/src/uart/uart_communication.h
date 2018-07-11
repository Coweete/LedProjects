/*
 * uart_communication.h
 *
 * Created: 2018-07-09 18:55:35
 *  Author: Jounne
 */ 


#ifndef UART_COMMUNICATION_H_
#define UART_COMMUNICATION_H_

void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);

#endif /* UART_COMMUNICATION_H_ */