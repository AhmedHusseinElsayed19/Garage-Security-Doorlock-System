/*
 * Keypadconfig.h
 *
 * Created: 5/14/2018 10:38:23 AM
 *  Author: Ahmed Hussein
 */ 


#ifndef KEYPADCONFIG_H_
#define KEYPADCONFIG_H_



#include <avr/io.h>

#define ROW0			   0
#define ROW0_DIR_REG	   DDRA
#define ROW0_OUTPUT_REG	   PORTA

#define ROW1			   1
#define ROW1_DIR_REG	   DDRA
#define ROW1_OUTPUT_REG	   PORTA

#define ROW2			   2
#define ROW2_DIR_REG	   DDRA
#define ROW2_OUTPUT_REG    PORTA

#define ROW3			   3
#define ROW3_DIR_REG	   DDRA
#define ROW3_OUTPUT_REG	   PORTA

#define LINE0				4
#define LINE0_DIR_REG		DDRA
#define LINE0_INPUT_REG		PINA
#define LINE0_PULLUP_REG	PORTA

#define LINE1				5
#define LINE1_DIR_REG		DDRA
#define LINE1_INPUT_REG		PINA
#define LINE1_PULLUP_REG	PORTA

#define LINE2				6
#define LINE2_DIR_REG		DDRA
#define LINE2_INPUT_REG		PINA
#define LINE2_PULLUP_REG	PORTA

#define LINE3	            7
#define LINE3_DIR_REG		DDRA
#define LINE3_INPUT_REG		PINA
#define LINE3_PULLUP_REG	PORTA


#endif /* KEYPADCONFIG_H_ */