#ifndef COMMUNICTION_ARM_H_
#define COMMUNICTION_ARM_H_

#include <avr/io.h>
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"
#include "../HAL/motor.h"

#define ARMPORT 'B'
#define ARMSTARTPIN 6
#define ARMENDPIN 5

void armInitConnection();
void armStart();
void waitArm();

#endif
