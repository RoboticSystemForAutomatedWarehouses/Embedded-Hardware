/*
 * Source File: motor.c
 *
 *  Description: Motor driver for ATMEGA128
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include "../pwm/pwm.h"

/*************************************************
 *  API functions
 *************************************************/
void motor_init();
void set_speed_left (uint8_t);
void set_speed_right (uint8_t);
void move_forward();
void move_backward();
void move_right(uint8_t);
void move_left(uint8_t);
void motor_stop();




#endif /* MOTOR_H_ */
