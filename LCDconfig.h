/*
 * LCDconfig.h
 *
 * Created: 5/14/2018 10:37:29 AM
 *  Author: Ahmed Hussein
 */ 


#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA PORTC                /*LCD data port*/
#define ctrl     PORTD                  /*LCD control port*/
#define en       PD1                         /* enable signal*/
#define rs       PD0                     /* register select signal*/




#endif /* LCDCONFIG_H_ */