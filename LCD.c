/*
 * LCD.c
 *
 * Created: 5/14/2018 10:36:55 AM
 *  Author: Ahmed Hussein
 */ 

#include "LCD.h"

void vLCD_Command(unsigned char cmd)
{
	LCD_DATA=cmd;
	ctrl =(0<<rs)|(1<<en);
	_delay_ms(1);
	ctrl =(0<<rs)|(0<<en);
	_delay_ms(50);
	return;
}

void vLCD_Clear(void)
{
	vLCD_Command(0x01);
	
	return;
}


void vLCD_Init(void)
{
	vLCD_Command(0x38);                            /*initialization of 16X2 LCD in 8bit mode*/
	_delay_ms(1);
	vLCD_Command(0x0E);                           /* cursor ON */
	_delay_ms(1);

	return;
}

void vLCD_Write(unsigned char data)
{
	LCD_DATA= data;
	ctrl = (1<<rs)|(1<<en);
	_delay_ms(1);
	ctrl = (1<<rs)|(0<<en);
	_delay_ms(50);
	return ;
}
void vLCD_Write_String(unsigned char *str)             /*store address value of the string in pointer *str*/
{
	int i=0;
	while(str[i]!='\0')                               /* loop will go on till the NULL character in the string*/
	{
		vLCD_Write(str[i]);                            /*sending data on LCD byte by byte*/
		i++;
	}
	return;
}
void vLCD_Set_Cursor(int cursor,int position)
{
	if(cursor == 1)
	vLCD_Command(0x80+position);                  /* 8 go to first line */
	else if(cursor == 2)
	vLCD_Command(0xC0+position);                 /*C go to second line */
	return;
}