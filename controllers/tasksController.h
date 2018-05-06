
#ifndef CONTROLLERS_ROTUECONTROLLER_H_
#define CONTROLLERS_ROTUECONTROLLER_H_

#include "../HAL/lineTracer.h"
#include "../HAL/motor.h"
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"
#include "RouteController.h"
#include "../config.h"

#define CLKWIS     0
#define ANTICLKWIS 1


void excuitePackage();
void excuiteTask();

#endif /* CONTROLLERS_ROTUECONTROLLER_H_ */
