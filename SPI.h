/*
 * SPI.h
 *
 * Created: 5/14/2018 10:43:01 AM
 *  Author: Ahmed Hussein
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK  7
#define DIR_SPI DDRB

void vSPI_MasterInit(void);
char cSPI_MasterReceive(void);
void vSPI_MasterTransmit(char Data);
void vSPI_SlaveInit(void);
char cSPI_SlaveReceive(void);
void vSPI_SlaveTransmit(char Data);



#endif /* SPI_H_ */