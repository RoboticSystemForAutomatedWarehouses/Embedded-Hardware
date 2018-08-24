#include "tasksController.h"

void arm(){
	//set arm in ready pos
		//send to rasspberry to set arm in exact pos
		//grap "take put return to default" algorithem
}


void excuiteTask(uint8 taskNum){
    //UART_Transmit('3',UART0);
	//route form current pos to start pos
	//arm
	//route from start to end pos
	//arm

	route(currPos[X],currPos[Y],task[taskNum].SPX,task[taskNum].SPY);
	currPos[X] = task[taskNum].SPX;
	currPos[Y] = task[taskNum].SPY;

	//send current position to raspberry
	UART_Transmit(currPos[X]+'0',UART0);
	UART_Transmit(currPos[Y]+'0',UART0);
	delayMs(2000);
	armStart();
	waitArm();
	delayMs(500);


	//arm control

	route(currPos[X],currPos[Y],task[taskNum].EPX,task[taskNum].EPY);
	currPos[X] = task[taskNum].EPX;
	currPos[Y] = task[taskNum].EPY;

	//send current position to raspberry
	UART_Transmit(currPos[X]+'0',UART0);
	UART_Transmit(currPos[Y]+'0',UART0);
	delayMs(2000);
	armStart();
	waitArm();
	delayMs(500);


	//arm control
}

void excuitePackage(){
	//UART_Transmit('2',UART0);
	//UART_Transmit(taskCnt+'0',UART0);
	for(uint8 i = 0 ; i < taskCnt ; i++){
		excuiteTask(i);
		//UART_Transmit(numOfTasks+'0',UART0);
		delayMs(2000);
	}

	//UART_Transmit_string("finished",UART0);
}

