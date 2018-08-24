#include "lineTracer.h"

uint8_t lineTracerValue;


void lineTracer_init(){
  //initilaize first lineTracer pins
  GPIO_InitPin(firstLineTracerPort,Sensor10,INPUT);
  GPIO_InitPin(firstLineTracerPort,Sensor11,INPUT);
  GPIO_InitPin(firstLineTracerPort,Sensor12,INPUT);
  GPIO_InitPin(firstLineTracerPort,Sensor13,INPUT);
  GPIO_InitPin(firstLineTracerPort,Sensor14,INPUT);
  //pull up resistor
 /*
  GPIO_SetPin(firstLineTracerPort,Sensor10);
  GPIO_SetPin(firstLineTracerPort,Sensor11);
  GPIO_SetPin(firstLineTracerPort,Sensor12);
  GPIO_SetPin(firstLineTracerPort,Sensor13);
  GPIO_SetPin(firstLineTracerPort,Sensor14);
 */
  //initilaize second lineTracer pins
  GPIO_InitPin(secondLineTracerPort,Sensor20,INPUT);
  GPIO_InitPin(secondLineTracerPort,Sensor21,INPUT);
  GPIO_InitPin(secondLineTracerPort,Sensor22,INPUT);
  GPIO_InitPin(secondLineTracerPort,Sensor23,INPUT);
  GPIO_InitPin(secondLineTracerPort,Sensor24,INPUT);
  //pull up resistor
  /*
  GPIO_SetPin(secondLineTracerPort,Sensor20);
  GPIO_SetPin(secondLineTracerPort,Sensor21);
  GPIO_SetPin(secondLineTracerPort,Sensor22);
  GPIO_SetPin(secondLineTracerPort,Sensor23);
  GPIO_SetPin(secondLineTracerPort,Sensor24);
*/
  //initilaize crossDetection pins
  GPIO_InitPin(crossDetectionPort,firstCrossDetectionSensor,INPUT);
  GPIO_InitPin(crossDetectionPort,secondCrossDetectionSensor,INPUT);
  //pull up resistor
  /*
  GPIO_SetPin(crossDetectionPort,firstCrossDetectionSensor);
  GPIO_SetPin(crossDetectionPort,secondCrossDetectionSensor);
  */

}


uint8 CrossDetect(){
	uint8 status = GPIO_ReadPort(crossDetectionPort);
	return ((status>>firstCrossDetectionSensor)&1) + 2*((status>>secondCrossDetectionSensor)&1);
}


uint8_t readLineTracer(uint8 selected){
//initilaize lineTracerValue to zero
lineTracerValue = 0;

if(selected == FIRSTMODULE){
//reading the port state
uint8 state = GPIO_ReadPort(firstLineTracerPort);

//sensor0 state
if(state&(1<<Sensor10))lineTracerValue |= (1<<s0);
//sensor1 state
if(state&(1<<Sensor11))lineTracerValue  |= (1<<s1);
//sensor2 state
if(state&(1<<Sensor12))lineTracerValue  |= (1<<s2);
//sensor3 state
if(state&(1<<Sensor13))lineTracerValue  |= (1<<s3);
//sensor4 state
if(state&(1<<Sensor14))lineTracerValue  |= (1<<s4);
}
else{
	//reading the port state
	uint8 state = GPIO_ReadPort(secondLineTracerPort);

	//sensor0 state
	if(state&(1<<Sensor20))lineTracerValue  |= (1<<s0);
	//sensor1 state
	if(state&(1<<Sensor21))lineTracerValue  |= (1<<s1);
	//sensor2 state
	if(state&(1<<Sensor22))lineTracerValue  |= (1<<s2);
	//sensor3 state
	if(state&(1<<Sensor23))lineTracerValue  |= (1<<s3);
	//sensor4 state
	if(state&(1<<Sensor24))lineTracerValue  |= (1<<s4);
	}
return lineTracerValue;
}
