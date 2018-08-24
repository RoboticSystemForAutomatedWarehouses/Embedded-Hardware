#include "arm.h"
#include <util/delay.h>


void armInitConnection(){
	GPIO_InitPin(ARMPORT,ARMSTARTPIN,OUTPUT);
	GPIO_InitPin(ARMPORT,ARMENDPIN,INPUT);
}

void armStart(){
   GPIO_SetPin(ARMPORT,ARMSTARTPIN);
   _delay_ms(100);
   GPIO_ClearPin(ARMPORT,ARMSTARTPIN);
}

void waitArm(){
   while(!( (GPIO_ReadPort(ARMPORT) & (1<<ARMENDPIN) )));
}

