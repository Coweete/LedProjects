/*
 * uart_communication.h
 *
 * Created: 2018-07-09 18:55:35
 *  Author: Jounne
 */ 


#ifndef UART_COMMUNICATION_H_
#define UART_COMMUNICATION_H_

void init_usart();
void USART_send(unsigned char data);
unsigned char USART_receive(void);
void USART_putString(char* StringPtr);
void test_send();

#endif /* UART_COMMUNICATION_H_ */