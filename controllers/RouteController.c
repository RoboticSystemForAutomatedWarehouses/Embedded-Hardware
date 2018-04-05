#include "RouteController.h"

int sx = 0 ,sy = 0 ,ex=3,ey=2;
int dx = 3;
int dy = 2;

void excuiteXY(){
	//excute x
	uint8 counted = 0;
	while(dx > 0){
	lineFollow();
	if(lineTracerValue == 31 && !counted){
		--dx;
		counted = 1;
	}else{
		counted = 0;
	}
	}

	//turn
	while(lineTracerValue&1){
				RobotMove(FORWARD,0,FORWARD,80);
			}
		while((lineTracerValue&1) == 0){
			RobotMove(FORWARD,0,FORWARD,80);
		}
	//exuite y
	 counted = 0;
	while(dy > 0){
	lineFollow();
	if(lineTracerValue == 31 && !counted){
		--dy;
		counted = 1;
	}else{
		counted = 0;
	}
	}
	motor_stop();
	while(1);

	}
