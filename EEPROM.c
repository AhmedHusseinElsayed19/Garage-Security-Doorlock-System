/*
 * EEPROM.c
 *
 * Created: 5/16/2018 8:58:17 PM
 *  Author: Ahmed Hussein
 */ 

#include "I2C.h"
#include "EEPROM.h"


char EEPROM_Write(unsigned int addr,unsigned char Data)
{
	vI2C_StartBit();
	if(ucI2C_GetStatus() != 0x08)
	return 1;
	vI2C_Write(0b10100000);
	if(ucI2C_GetStatus() != 0x18)
	return 2;
	vI2C_Write((unsigned char)(addr));
	if(ucI2C_GetStatus() != 0x28)
	return 3;
	vI2C_Write(Data);
	if(ucI2C_GetStatus() != 0x28)
	return 4;
	vI2C_StopBit();
	return 5;
}

char EEPROM_Read(unsigned int addr,unsigned char *Data)
{
	
	vI2C_StartBit();
	if(ucI2C_GetStatus() != 0x08)
	return 1;
	vI2C_Write(0b10100000);
	if(ucI2C_GetStatus() != 0x18)
	return 2;
	vI2C_Write((unsigned char)(addr));
	if(ucI2C_GetStatus() != 0x28)
	return 3;
	vI2C_StartBit();
	if(ucI2C_GetStatus() != 0x10)
	return 4;
	vI2C_Write(0b10100001);
	if(ucI2C_GetStatus() != 0x40)
	return 5;
	*Data=ucI2C_ReadNack();
	if(ucI2C_GetStatus() != 0x58)
	return 6;
	vI2C_StopBit();
	return 7;
}