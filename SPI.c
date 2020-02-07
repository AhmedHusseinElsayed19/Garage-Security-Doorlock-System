/*
 * SPI.c
 *
 * Created: 5/14/2018 10:42:48 AM
 *  Author: Ahmed Hussein
 */ 

#include "SPI.h"

void vSPI_SlaveInit(void)
{
	DIR_SPI = (1<<DD_MISO);
	SPCR = (1<<SPE)|(1<<DORD)|(1<<SPIE);        /* DORD -> I need to send the LSB first cuz the password is consisted of ones cuz when I send the MSB first the logic was incorrect*/
	
	return;
}

char cSPI_SlaveReceive(void)
{
	
	while(!(SPSR & (1<<SPIF)));
	
	return SPDR;
}

void vSPI_SlaveTransmit(char Data)
{
	SPDR = Data;
	while(!(SPSR & (1<<SPIF)));
	
	return;
}

char cSPI_MasterReceive(void)
{
	while(!(SPSR & (1<<SPIF)));
	
	
	return SPDR;
}

void vSPI_MasterTransmit(char Data)
{
	SPDR = Data;
	while(!(SPSR & (1<<SPIF)));
	
	
	return;
}

void vSPI_MasterInit(void)
{
	DIR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
	return;
}