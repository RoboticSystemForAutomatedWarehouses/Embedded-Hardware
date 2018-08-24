
#ifndef CONTROLLERS_LINEFOLLOWERCONTROLLER_H_
#define CONTROLLERS_LINEFOLLOWERCONTROLLER_H_

#include "../HAL/lineTracer.h"
#include "../HAL/motor.h"
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"
#include "../config.h"

#define TOTALSENS    5
#define AVERAGESENS  3
#define PWRFACTOR    2

void readSensor(uint8);
void linePID(uint8);
void lineFollow(uint8);


#endif /* CONTROLLERS_LINEFOLLOWERCONTROLLER_H_ */
