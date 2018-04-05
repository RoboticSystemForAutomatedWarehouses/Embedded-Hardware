/*
 * Source File: motor.c
 *
 *  Description: Motor driver for ATMEGA128
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"
#include "../MCAL/pwm.h"

#define motorDirectionsPort 'D'

#define rightMotorDirection1 5
#define rightMotorDirection2 4

#define leftMotorDirection1 6
#define leftMotorDirection2 7
//enable pins defined in pwm module.
//direction and motor selection
#define FORWARD 0
#define BACKWORD 1
#define RIGHT 0
#define LEFT 1

//SET MOTOR MAX SPEED
#define MAXSPEEDPRECENTAGE 0.75
#define MAX_SPEED (255*MAXSPEEDPRECENTAGE) // 255 * (0.75)

/*************************************************
 *  API functions
 *************************************************/
void motor_init();
void set_speed_left (uint8_t);
void set_speed_right (uint8_t);
void setDirectionForward(uint8);
void setDirectionBackword(uint8);
void move_right(uint8_t);
void move_left(uint8_t);
void motor_stop();
void RobotMove(uint8,uint8,uint8,uint8);




#endif /* MOTOR_H_ */
