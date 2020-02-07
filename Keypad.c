/*
 * Keypad.c
 *
 * Created: 5/14/2018 10:37:48 AM
 *  Author: Ahmed Hussein
 */ 


#include "Keypad.h"
#include <stdint.h>
const static unsigned char s_KeypadMap[4][4]={{'7','8','9','/'},
                                              {'4','5','6','*'},
                                              {'1','2','3','-'},
                                              {'C','0','=','+'}};



void vKeypad_Init(void)
{
	//initialize rows as output
	ROW0_DIR_REG |=(1U<<ROW0);
	ROW1_DIR_REG |=(1U<<ROW1);
	ROW2_DIR_REG |=(1U<<ROW2);
	ROW3_DIR_REG |=(1U<<ROW3);
	//initialize lines as input
	LINE0_DIR_REG &=~(1U<<LINE0);
	LINE1_DIR_REG &=~(1U<<LINE1);
	LINE2_DIR_REG &=~(1U<<LINE2);
	LINE3_DIR_REG &=~(1U<<LINE3);
	//enable pull up for lines
	LINE0_PULLUP_REG |=(1U<<LINE0);
	LINE1_PULLUP_REG |=(1U<<LINE1);
	LINE2_PULLUP_REG |=(1U<<LINE2);
	LINE3_PULLUP_REG |=(1U<<LINE3);
	//initialize the rows state to no output state(ACTIVE LOW so they must be set to ones)
	ROW0_OUTPUT_REG |=(1U<<ROW0);
	ROW1_OUTPUT_REG |=(1U<<ROW1);
	ROW2_OUTPUT_REG |=(1U<<ROW2);
	ROW3_OUTPUT_REG |=(1U<<ROW3);

}

unsigned char ucKeypad_Scan(void)
{
	uint8_t row;
	uint8_t line = NO_VALID_INPUT;
	unsigned char result = NO_VALID_INPUT;
	
	//loop on the rows
	for (row=0;row<4;row++)
	{
		//reset the rows state to no output state(ACTIVE LOW so they must be set to ones)
		ROW0_OUTPUT_REG |=(1U<<ROW0);
		ROW1_OUTPUT_REG |=(1U<<ROW1);
		ROW2_OUTPUT_REG |=(1U<<ROW2);
		ROW3_OUTPUT_REG |=(1U<<ROW3);
		//generate output on certain row
		switch(row)
		{
			case 0:ROW0_OUTPUT_REG &=~(1U<<ROW0);break;
			case 1:ROW1_OUTPUT_REG &=~(1U<<ROW1);break;
			case 2:ROW2_OUTPUT_REG &=~(1U<<ROW2);break;
			case 3:ROW3_OUTPUT_REG &=~(1U<<ROW3);break;
			default:break;
		}
		if((LINE0_INPUT_REG&(1U<<LINE0))==0)	  {line=0;}
		else if((LINE1_INPUT_REG&(1U<<LINE1))==0) {line=1;}
		else if((LINE2_INPUT_REG&(1U<<LINE2))==0) {line=2;}
		else if((LINE3_INPUT_REG&(1U<<LINE3))==0) {line=3;}
		else {/* MISRA */}
		//check if there is a valid input
		if (line != NO_VALID_INPUT )
		{
			//wait till the input is gone
			while(INPUT_STILL_THERE == YES );
			//break from the loop
			result = s_KeypadMap[row][line];
			break;
		}
		
	}
	return result;
}