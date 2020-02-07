/*
 * I2C.h
 *
 * Created: 5/16/2018 8:41:02 PM
 *  Author: Ahmed Hussein
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>

void vI2C_Init(void);
void vI2C_StartBit(void);
void vI2C_StopBit(void);
unsigned char ucI2C_GetStatus(void);
void vI2C_Write(unsigned char);
unsigned char ucI2C_ReadACK(void);
unsigned char ucI2C_ReadNack(void);




#endif /* I2C_H_ */