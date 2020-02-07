/*
 * Motor.c
 *
 * Created: 5/14/2018 10:41:24 AM
 *  Author: Ahmed Hussein
 */ 

#include "Motor.h"

void vMotor_Init()
{
	Motor_DIR |= (1<<4);
	Motor_DIR |= (1<<5);
	Motor_DIR |= (1<<6);
	
	return;
}

void vMotor_CCW()
{
	Motor_Port |= (1<<4);
	Motor_Port &= ~(0<<5);
	Motor_Port |= (1<<6);
	
	return;
}

void vMotor_CW()
{
	Motor_Port |= (1<<5);
	Motor_Port &= ~(1<<4);
	Motor_Port |= (1<<6);
	
	return;
}

void vMotor_Stop()
{
	Motor_Port &= ~(1<<4);
	Motor_Port &= ~(1<<5);
	Motor_Port |= (1<<6);
	
	return;
}