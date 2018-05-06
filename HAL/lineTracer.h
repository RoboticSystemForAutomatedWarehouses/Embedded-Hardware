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

//define two sensors
#define FIRSTMODULE  0
#define SECONDMODULE 1
///first lineTracer port config
#define firstLineTracerPort 'F'
#define firstLineTracerPortDirection 'F'

//second lineTracer port config
#define secondLineTracerPort 'C'
#define secondLineTracerPortDirection 'C'

//cross detection sensors port
#define crossDetectionPort 'G'
#define crossDetectionPortDirection 'G'

//cross detection pins
#define firstCrossDetectionSensor  1
#define secondCrossDetectionSensor 4

//lineTracer pin form lef to right
//first sensor
#define Sensor10 1
#define Sensor11 2
#define Sensor12 3
#define Sensor13 4
#define Sensor14 0
//second sensor
#define Sensor20 0
#define Sensor21 1
#define Sensor22 2
#define Sensor23 3
#define Sensor24 4

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
uint8_t readLineTracer(uint8);

#endif /* LINETRACER_H_ */
