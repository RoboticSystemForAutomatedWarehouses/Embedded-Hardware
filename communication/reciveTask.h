/*
 * newtask.h
 *
 *  Created on: 30/4/2018
 *      Author: Abdullah
 */

#ifndef COMMUNICTION_RECIVETASK_H_
#define COMMUNICTION_RECIVETASK_H_

#include <avr/io.h>
#include "../ServiceLayer/std_types.h"
#include "../MCAL/GPIO.h"
#include "../HAL/motor.h"


#define TASKBUFFERSIZE		105


struct tasks
{
    uint8  id ;
    uint8 EPX;
    uint8  EPY ;
    uint8  EPZ ;
    uint8  SPX ;
    uint8  SPY ;
    uint8  SPZ ;

};


extern struct tasks task[3];
extern uint8 volatile taskBuffer [TASKBUFFERSIZE] ;
extern uint8 volatile newPackage;
extern uint8 volatile taskBufferCnt;
extern uint8 numOfTasks;

void celarTaskBuffer() ;
void loadTasks() ;


#endif /* COMMUNICTION_RECIVETASK_H_ */
