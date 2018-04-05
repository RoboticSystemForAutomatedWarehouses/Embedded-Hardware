#include "lineTracer.h"

uint8_t lineTracerValue;


void lineTracer_init(){
  //initilaize pins as input
  GPIO_InitPin(lineTracerPort,Sensor0,INPUT);
  GPIO_InitPin(lineTracerPort,Sensor1,INPUT);
  GPIO_InitPin(lineTracerPort,Sensor2,INPUT);
  GPIO_InitPin(lineTracerPort,Sensor3,INPUT);
  GPIO_InitPin(lineTracerPort,Sensor4,INPUT);

}

uint8_t readLineTracer(){
//initilaize lineTracerValue to zero
lineTracerValue = 0;

//reading the port state
uint8 state = GPIO_ReadPort(lineTracerPort);

//sensor0 state
if(state&(1<<Sensor0)) lineTracerValue |=(1<<s0);
//sensor1 state
if(state&(1<<Sensor1))lineTracerValue |= (1<<s1);
//sensor2 state
if(state&(1<<Sensor2))lineTracerValue |= (1<<s2);
//sensor3 state
if(state&(1<<Sensor3))lineTracerValue |= (1<<s3);
//sensor4 state
if(state&(1<<Sensor4))lineTracerValue |= (1<<s4);


return lineTracerValue;
}
