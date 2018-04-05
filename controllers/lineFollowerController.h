
#ifndef LINEFOLLOWERCONTROLLER_H_
#define LINEFOLLOWERCONTROLLER_H_

#include "../HAL/lineTracer.h"
#include "../HAL/motor.h"
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"
#include "../config.h"

#define TOTALSENS    5
#define AVERAGESENS  3


void readSensor(void);
void linePID();
void lineFollow(void);


#endif /* LINEFOLLOWERCONTROLLER_H_ */
