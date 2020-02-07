/*
 * Master.c
 *
 * Created: 5/13/2018 5:19:01 PM
 * Author : Ahmed Hussein
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU   1000000UL
#include <util/delay.h> 


#include "LCD.h"
#include "Keypad.h"
#include "SPI.h"

#define  size 4       /*maximum number of inputs from the keypad */

int Matching_counter = -1;
volatile int error_counter = 0;
unsigned char S_flag  = 1;
unsigned char No_flag = 2;

int main(void)
{
	
	unsigned char Input[size];           /* array for the inputs of the keypad */
	unsigned char Password[]= {1,1,1,1};
	
	
	int counter = 0;
	unsigned char key= NO_VALID_INPUT;
	
	
	
	
	DDRC = 0xFF;                   /* FF for Directing the output */
	DDRD = (0x02|0x01);         /* First pin or ( | ) with second pin only because I need to use the remaining pins for another purposes*/
    
	
	sei();                   /* Interrupt Enable */
	GICR  |= (1<<INT0)|(1<<INT1);
	MCUCR |= (1<<ISC01);    /* Falling Edge */
    MCUCR |= (1<<ISC11);
	
	vSPI_MasterInit();
	vLCD_Init();
	vKeypad_Init();
	
	vLCD_Set_Cursor(1,10);
	vLCD_Write_String("Welcome Ahmed");
	_delay_ms(2000);
	vLCD_Clear();
	vLCD_Write_String("Enter password:");
	vLCD_Set_Cursor(2,0);
	
	while (1)
	{
		key=ucKeypad_Scan();
		
			if (( key!= NO_VALID_INPUT)&&(key!='*')&&(key!='/')&&(key!='+')&&(key!='-')&&(key!='=')&&(key!='C'))
			{
			
				if (counter<size)
				{
					Input[counter]=key-48;
					vLCD_Write('*');
					counter++;
					if (counter!=size)
					{
						continue;
					}
					
				}
				
				if ((Input[0]==Password[0])&&(Input[1]==Password[1])&&(Input[2]==Password[2])&&(Input[3]==Password[3]))
				{
					Matching_counter=1;
					
				}
				
				else if((Input[0]!=Password[0])||(Input[1]!=Password[1])||(Input[2]!=Password[2])||(Input[3]!=Password[3]))
				{
					Matching_counter=0;
				}
				
				if (Matching_counter==1)
				{  
					vSPI_MasterTransmit(S_flag);
					vLCD_Clear();
					vLCD_Set_Cursor(2,10);
					vLCD_Write_String("Correct");
					
				}
				else if (Matching_counter==0)
				{   
					vSPI_MasterTransmit(No_flag);
					vLCD_Clear();
					vLCD_Set_Cursor(2,10);
					vLCD_Write_String("Incorrect");
					error_counter++;
					
				}
				
				
				
				
			}
			
			          if (error_counter==3)
			          {    
						   
				           vLCD_Clear();
				           vLCD_Set_Cursor(1,1);
				           vLCD_Write_String("System Locked");
				           vLCD_Set_Cursor(2,1);
				           vLCD_Write_String("Contact Admin Please");
				          
			          }
			
			          while (error_counter==3);
			         
		
		            	if ((key=='C'))
		            	{
			            	memset(&Input[0],0,sizeof(Input));
			            	counter=0;
			            	vLCD_Clear();
			            	vLCD_Write_String("Enter password:");
			            	vLCD_Set_Cursor(2,0);
		            	}
		
		 	
	}


}

ISR(INT0_vect)
{   	
	error_counter = 0;	
	
}

ISR(INT1_vect)
{
	vLCD_Clear();
	vLCD_Write_String("Well Done");
	vLCD_Clear();	
}

