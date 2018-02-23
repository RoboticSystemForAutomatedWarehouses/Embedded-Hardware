/***************************************************************
 *  Source File: PWM.h
 *
 *  Description: PWM driver for ATMEGA128
 *
 **************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "pwm_cfg.h"

/*************************************************
 *  API functions
 *************************************************/

void PWM_init(uint8_t);
void PWM_SetDutyValue(uint8_t, uint8_t);
void PWM_SetDutyCycle(uint8_t, uint8_t);

#endif /* PWM_H_ */
