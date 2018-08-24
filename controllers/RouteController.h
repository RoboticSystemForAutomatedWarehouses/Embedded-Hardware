
#ifndef CONTROLLERS_ROTUECONTROLLER_H_
#define CONTROLLERS_ROTUECONTROLLER_H_

#include "../HAL/lineTracer.h"
#include "../HAL/motor.h"
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"
#include "../config.h"

#define CLKWIS     0
#define ANTICLKWIS 1
#define X 0
#define Y 1
#define LEFTMOTORSPEED  100
#define RIGHTMOTORSPEED 92

extern uint8 currPos[2];

BOOLEAN crossDetection();
void route(uint8,uint8,uint8,uint8);
void rotate90(uint8 direction,uint8);
void excuitYEnd(uint8 va,uint8);
void setFinalPos(uint8);
void excuitValue(uint8 va,uint8);
void excuitYStart(uint8 va,uint8);
void  excuiteX(uint8 xs,uint8 xe);
void delayMs(uint32);
#endif /* CONTROLLERS_ROTUECONTROLLER_H_ */
