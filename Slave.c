/*
 * Slave.c
 *
 * Created: 5/13/2018 5:20:45 PM
 * Author : Ahmed Hussein
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU  1000000UL
#include <util/delay.h>

#include "SPI.h"
#include "Motor.h"
#include "UART.h"
#include "I2C.h"
#include "EEPROM.h"


#define  size 4

unsigned char Admin_Password [size];
unsigned char Stored_Password [size];

volatile int U_counter = 0;
volatile int S_counter = 0;
volatile char S_flag = 0;
int Admin_counter = -1;
 
int main(void)
{  
   unsigned char *Admin="Hello, Welcome to Admin Control Room\n\r\0"; /* \r is carriage return */
   unsigned char *Incorrect="\n\rIncorrect Password\n\r\0";      /* I used to make it in an array of characters which is way longer than using pointer */
   unsigned char *Correct="\n\rCorrect Password\n\r\0";
   unsigned int  ADDRESS=0x001;
   unsigned char EEData = 0;
   int i = 0;
   
   
  
     sei();
  
	 DDRD |= (1<<2)|(1<<3);      /* These are for the interrupt that comes from the master  */ 
	 DDRA |= (1<<0);                          /* Buzzer */
	
	 vI2C_Init();
	 vSPI_SlaveInit();
	 vUART_Init();
	 vMotor_Init();
	
	for (i=0;Admin[i]!='\0';i++)
	{
		vUART_Transmit(Admin[i]);
	}
	
	
	EEPROM_Write(0x001,50);   /* 50 and address represent 2 in Admin password*/
	_delay_ms(20);
	EEPROM_Write(0x002,49);   /* 49 and address represent 1 in Admin password*/
	_delay_ms(20);
	EEPROM_Write(0x003,49);
	_delay_ms(20);
	EEPROM_Write(0x004,50);
	_delay_ms(20);
	
	
	for(i=0;i<size;i++)        /*This for....loop is for saving the Admin password in an array*/
	{
		EEPROM_Read(ADDRESS,&EEData);
		Stored_Password[i]=EEData;
		ADDRESS++;
	}
	 
	
 while(1)
 {
	 if (S_counter==0)
	 {
		 S_counter=0;
	 
	 if (S_flag==1)
	 { 
		 S_flag=0;
		   
		   for (i=0;Correct[i]!='\0';i++)
		   {
			   vUART_Transmit(Correct[i]);
		   }
		 vMotor_CCW();
		 _delay_ms(1000);
		 vMotor_Stop();
		 _delay_ms(1000);
		 vMotor_CW();
		 _delay_ms(1000);
		 vMotor_Stop();
	 }
	else if (S_flag==2)
	{      
		   for (i=0;Incorrect[i]!='\0';i++)
		   {
			 vUART_Transmit(Incorrect[i]);
		   }
		   vMotor_Stop();
		   PORTA |= (1<<0);
		   _delay_ms(750);
		   PORTA &= ~ (1<<0);
		 
	}
	
	}
	 
   if (U_counter==4)
   {
		
       U_counter=0;
    	  
	   if ((Admin_Password[0]==Stored_Password[0])&&(Admin_Password[1]==Stored_Password[1])&&(Admin_Password[2]==Stored_Password[2])&&(Admin_Password[3]==Stored_Password[3]))
	   {
		   Admin_counter=1;
	   }
	   else if ((Admin_Password[0]!=Stored_Password[0])||(Admin_Password[1]!=Stored_Password[1])||(Admin_Password[2]!=Stored_Password[2])||(Admin_Password[3]!=Stored_Password[3]))
	   {
		  Admin_counter=0;
	   }

	      if (Admin_counter == 1)
	      {
		   
		   for (i=0;Correct[i]!='\0';i++)
		   {
			   vUART_Transmit(Correct[i]);
		   }
		   vMotor_CCW();
		   _delay_ms(1000);
		   vMotor_Stop();
		   _delay_ms(1000);
		   vMotor_CW();
		   _delay_ms(1000);
		   vMotor_Stop();
		   Admin_counter=-1;
		   
		   PORTD |= (1<<3);
		   _delay_ms(50);
		   PORTD &= ~ (1<<3);
		   PORTD |= (1<<2);
		   _delay_ms(50);
		   PORTD &= ~ (1<<2);
		   
	      }

	     else if (Admin_counter == 0)
	     {
		   
		   for (i=0;Incorrect[i]!='\0';i++)
		   {
			   vUART_Transmit(Incorrect[i]);
		   }
		   vMotor_Stop();
		   Admin_counter=-1;
		   
		   PORTA |= (1<<0);
		   _delay_ms(750);
		   PORTA &= ~ (1<<0);
		   
	     }
	  
	}
	
	

 }
 
}

ISR(SPI_STC_vect)
{
	 
	 S_flag=cSPI_SlaveReceive();
	 S_counter = 0;
	 
}

ISR(USART_RXC_vect)
{
	 Admin_Password[U_counter]=cUART_Recieve();
	 U_counter++;
}