/*
 * Keypad.h
 *
 * Created: 5/14/2018 10:38:03 AM
 *  Author: Ahmed Hussein
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Keypadconfig.h"

#define YES					0
#define NO_VALID_INPUT		0xFF    /* value out of the range of buttons on keypad */
#define INPUT_STILL_THERE					   ((LINE0_INPUT_REG&(1U<<LINE0))\
                                              &&(LINE1_INPUT_REG&(1U<<LINE1))\
                                              &&(LINE2_INPUT_REG&(1U<<LINE2))\
                                              &&(LINE3_INPUT_REG&(1U<<LINE3)))

void vKeypad_Init(void);
unsigned char ucKeypad_Scan(void);



#endif /* KEYPAD_H_ */