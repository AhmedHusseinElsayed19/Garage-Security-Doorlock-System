/*
 * Motor.h
 *
 * Created: 5/14/2018 10:41:36 AM
 *  Author: Ahmed Hussein
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>

#define Motor_DIR  DDRA
#define Motor_Port PORTA


void vMotor_Init();
void vMotor_CW();
void vMotor_CCW();
void vMotor_Stop();




#endif /* MOTOR_H_ */