/*
 * UART.h
 *
 * Created: 5/16/2018 12:14:27 AM
 *  Author: Ahmed Hussein
 */ 


#ifndef UART_H_
#define UART_H_



void vUART_Init (void);
void vUART_Transmit (unsigned char Data);
unsigned char cUART_Recieve (void);



#endif /* UART_H_ */