/*
 * Source File: lineTracer.h
 *
 *  Description: lineTracer module for ATMEGA128
 */

#ifndef LINETRACER_H_
#define LINETRACER_H_

#include <avr/io.h>
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"

///lineTracer port config
#define lineTracerPort 'F'
#define lineTracerPortDirection 'F'
//lineTracer pin form lef to right
#define Sensor0 1
#define Sensor1 2
#define Sensor2 3
#define Sensor3 4
#define Sensor4 0
//define shift values _port numbers and sensors number are not the same_
#define s0 0
#define s1 1
#define s2 2
#define s3 3
#define s4 4



extern uint8_t lineTracerValue;


/*************************************************
 *  API functions
 *************************************************/
void lineTracer_init();
uint8_t readLineTracer();

#endif /* LINETRACER_H_ */
