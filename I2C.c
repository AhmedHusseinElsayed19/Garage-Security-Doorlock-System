/*
 * I2C.c
 *
 * Created: 5/16/2018 8:41:21 PM
 *  Author: Ahmed Hussein
 */ 


#include "I2C.h"

#include <avr/io.h>


void vI2C_Init(void)
{
	TWCR=(1<<TWEN);
	TWSR=0x00;
	TWBR=0x0C;   /*12 same as UART */
	
	return;
}

void vI2C_StartBit(void)
{
	TWCR=(1<<TWEN)|(1<<TWSTA)|(1<<TWINT);
	while((TWCR&(1<<TWINT))==0);
	
	return;
}

void vI2C_StopBit(void)
{
	TWCR=(1<<TWEN)|(1<<TWSTO)|(1<<TWINT);
	
	return;
}

unsigned char ucI2C_GetStatus(void)
{
	/* uint8_t status;
	   mask status
	status = TWSR & 0xF8; 
	return status */
	return (TWSR&0xF8);
}

void vI2C_Write(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWEN)|(1<<TWINT);
	while((TWCR&(1<<TWINT))==0);
	
	return;
}

unsigned char ucI2C_ReadACK(void)
{
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while((TWCR&(1<<TWINT))==0);
	
	return TWDR;
}

unsigned char ucI2C_ReadNack(void)
{
	TWCR=(1<<TWEN)|(1<<TWINT);
	while((TWCR&(1<<TWINT))==0);
	
	return TWDR;
}
