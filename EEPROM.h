/*
 * EEPROM.h
 *
 * Created: 5/16/2018 8:58:33 PM
 *  Author: Ahmed Hussein
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


char EEPROM_Write(unsigned int addr,unsigned char Data);
char EEPROM_Read(unsigned int addr,unsigned char *Data);


#endif /* EEPROM_H_ */