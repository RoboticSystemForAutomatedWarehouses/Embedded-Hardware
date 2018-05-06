#include "tasksController.h"

void arm(){
	//set arm in ready pos
		//send to rasspberry to set arm in exact pos
		//grap "take put return to default" algorithem
}
void excuiteTask(uint8 taskNum){

	//route form current pos to start pos
	//arm
	//route from start to end pos
	//arm

	route(currentPos[X],currentPos[Y],task[taskNum].SPX,task[taskNum].SPY);
	currentPos[X] = task[taskNum].SPX;
	currentPos[Y] = task[taskNum].SPY;
	delayMs(2000);
	route(currentPos[X],currentPos[Y],task[taskNum].EPX,task[taskNum].EPY);
	delayMs(2000);
	currentPos[X] = task[taskNum].EPX;
	currentPos[Y] = task[taskNum].EPY;

}

void excuitePackage(){

	for(uint8 i = 0 ; i < numOfTasks ; i++)
		excuiteTask(i);

}
