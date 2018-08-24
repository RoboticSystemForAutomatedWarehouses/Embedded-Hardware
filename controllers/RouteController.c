#include "RouteController.h"


void pauseRobot();
void centreRobot(uint8);

BOOLEAN blocked = 0;



uint8 currPos[2];


void delayMs(uint32 ms) {
	while (ms--)
		_delay_ms(1);
}


void centreRobot(uint8 module){

		while(!CrossDetect())
			lineFollow(module);
}

void pauseRobot(){
	motor_stop();
	delayMs(1000);
}


BOOLEAN crossDetection(void) {
	if (lineTracerValue == 31 && !blocked) {
		blocked = 1;
		return 1;
	}
	if (lineTracerValue != 31)
		blocked = 0;

	return 0;
}

void setFinalPos(uint8 module) {

	while (readLineTracer(FIRSTMODULE) == 31)
		lineFollow(module);

	//pause
	motor_stop();
	delayMs(3000);
}

void excuitValue(uint8 va, uint8 module) {

	while (va) {
		lineFollow(module);
		if (crossDetection())
			--va;
	}
	//setFinalPos(module);
}

void excuitYStart(uint8 va,uint8 module) {
	//the robot will move forward so we will use the first line tracer module
	excuitValue(va, module);
	pauseRobot();
    centreRobot(module);
    pauseRobot();

}

void excuiteX(uint8 xs, uint8 xe) {
	sint8 xt = (xe - xs);

	//dependig on x if we r backing then will use second else we will use first module
	uint8 module = (xt > 0) ? FIRSTMODULE : SECONDMODULE;

	excuitValue(abs(xt), module);
	pauseRobot();
	centreRobot(module);
	pauseRobot();

}

void excuitYEnd(uint8 va,uint8 module) {
	//will always use second module when excuiting yend
	excuitValue(va, module);
	pauseRobot();
    centreRobot(module);
    pauseRobot();
}



 //two orientation clkwise & anticlkwise
 void rotate90(uint8 orientaion,uint8 module) {
 uint8 val = readLineTracer(FIRSTMODULE);

 if (orientaion == ANTICLKWIS) {

 //change it in backword val <=7
 //10000//11000//01000//00100//01100//11100
 if (val <= 7) {
 while ((readLineTracer(module) & (1 << 2)) == 0)
 RobotMove(BACKWORD, LEFTMOTORSPEED, FORWARD, RIGHTMOTORSPEED);

 while (readLineTracer(module) & (1 << 2))
 RobotMove(BACKWORD, LEFTMOTORSPEED, FORWARD, RIGHTMOTORSPEED);

 while ((readLineTracer(module) & (1 << 2)) == 0)
 RobotMove(BACKWORD, LEFTMOTORSPEED, FORWARD, RIGHTMOTORSPEED);
 } else {
 while (readLineTracer(module) & (1 << 2))
 RobotMove(BACKWORD, LEFTMOTORSPEED, FORWARD, RIGHTMOTORSPEED);

 while ((readLineTracer(module) & (1 << 2)) == 0)
 RobotMove(BACKWORD, LEFTMOTORSPEED, FORWARD, RIGHTMOTORSPEED);

 }
 }

 else if (orientaion == CLKWIS) {

 //10000//11000//01000//00100//01100//11100
 if (val > 7) {
 while ((readLineTracer(module) & (1 << 2)) == 0)
 RobotMove(FORWARD, LEFTMOTORSPEED, BACKWORD, RIGHTMOTORSPEED);

 while (readLineTracer(module) & (1 << 2))
 RobotMove(FORWARD, LEFTMOTORSPEED, BACKWORD, RIGHTMOTORSPEED);

 while ((readLineTracer(module) & (1 << 2)) == 0)
 RobotMove(FORWARD, LEFTMOTORSPEED, BACKWORD, RIGHTMOTORSPEED);
 } else {
 while (readLineTracer(module) & (1 << 2))
 RobotMove(FORWARD, LEFTMOTORSPEED, BACKWORD, RIGHTMOTORSPEED);

 while ((readLineTracer(module) & (1 << 2)) == 0)
 RobotMove(FORWARD, LEFTMOTORSPEED, BACKWORD, RIGHTMOTORSPEED);
 }
 }

 //pause
 pauseRobot();
 }

/*
void rotate90(uint8 orientation) {

	if (orientation == ANTICLKWIS) {
		while (CrossDetect() != 1)
			RobotMove(BACKWORD, 100, FORWARD, 100);
		while (CrossDetect() == 1 || CrossDetect() == 3)
			RobotMove(BACKWORD, 100, FORWARD, 100);
		while (CrossDetect() != 0)
			RobotMove(BACKWORD, 100, FORWARD, 100);
		while (readLineTracer(FIRSTMODULE) == 0)
			RobotMove(BACKWORD, 100, FORWARD, 100);

	}

	if (orientation == CLKWIS) {
		        while (CrossDetect() != 1)
					RobotMove(FORWARD, 100, BACKWORD, 100);
				while (CrossDetect() == 1 || CrossDetect() == 3)
					RobotMove(FORWARD, 100, BACKWORD, 100);
				while (CrossDetect() != 0)
					RobotMove(FORWARD, 100, BACKWORD, 100);
				while (readLineTracer(FIRSTMODULE) == 0)
					RobotMove(FORWARD, 100, BACKWORD, 100);
		 }

}
*/
void route(uint8 xs, uint8 ys, uint8 xe, uint8 ye) {

	sint8 ty = (ye-ys);
	sint8 tx = (xe-xs);
	sint8 module;

	//delete this code when u fix the rotation
	ys = ((3*xs)+ys);
	ye = ((3*xe)+ye);
	ty = (ye-ys);
	xs = xe  =  0 ;


	//excuit this routine if the start and end pos are on the same line
	if(xs == xe){
		uint8 module = (ye<ys)? SECONDMODULE:FIRSTMODULE;
		excuitValue(abs(ty),module);
		pauseRobot();
		centreRobot(module);
		pauseRobot();
		return;
	}

	excuitYStart(ys,FIRSTMODULE);
	module = (tx < 0)? SECONDMODULE : FIRSTMODULE;
	rotate90(ANTICLKWIS,module);
	excuiteX(xs, xe);
	rotate90(CLKWIS,SECONDMODULE);
	excuitYEnd(ye,SECONDMODULE);
}
