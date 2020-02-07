/*
 * LCD.h
 *
 * Created: 5/14/2018 10:37:11 AM
 *  Author: Ahmed Hussein
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCDconfig.h"

void vLCD_Command(unsigned char cmd);
void vLCD_Clear(void);
void vLCD_Init(void);
void vLCD_Write(unsigned char data);
void vLCD_Write_String(unsigned char *str);
void vLCD_Set_Cursor(int cursor, int position);



#endif /* LCD_H_ */