
#ifndef CONTROLLERS_TASKCONTROLLER_H_
#define CONTROLLERS_TASKCONTROLLER_H_

#include "../HAL/lineTracer.h"
#include "../HAL/motor.h"
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"
#include "RouteController.h"
#include "../communication/reciveTask.h"
#include "../config.h"

#define CLKWIS     0
#define ANTICLKWIS 1
extern uint8 currPos[2];


void excuitePackage();

#endif /* CONTROLLERS_TASKCONTROLLER_H_ */
