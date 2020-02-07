/*
 * UART.c
 *
 * Created: 5/16/2018 12:14:07 AM
 *  Author: Ahmed Hussein
 */ 

#include <avr/io.h>
#include "UART.h"

void vUART_Init (void)
{   
	
	UBRRL= (unsigned char) 12;       /* equals to 12 ( percentage of error 0.17) */
	UCSRB= (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	UCSRC= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	
	return;
}

void vUART_Transmit (unsigned char Data)
{
	while (( UCSRA & (1<<UDRE))==0);  
	UDR = Data;                      
	
	return;
}

unsigned char cUART_Recieve (void)
{   
	
	while((UCSRA&(1<<RXC))==0);
	return UDR;
}
