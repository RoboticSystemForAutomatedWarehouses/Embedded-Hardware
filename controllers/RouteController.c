#include "RouteController.h"

BOOLEAN blocked = 0;
extern uint8 currentPos[2] ;


void delayMs(uint32 ms) {
	while (ms--)
		_delay_ms(1);
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

void setFinalPos() {

	while (readLineTracer(FIRSTMODULE) == 31)
		lineFollow(FIRSTMODULE);

	    motor_stop();
		delayMs(3000);

}

void excuitValue(uint8 va) {

	while (va) {
		lineFollow(FIRSTMODULE);
		if (crossDetection())
			--va;
	}
	setFinalPos();
}

void excuitYStart(uint8 va) {
	excuitValue(va);
}

void excuiteX(uint8 xs, uint8 xe) {
	uint8 xt = xe - xs;
	uint8 direction = (xt < 0) ? BACKWORD : FORWARD;

	excuitValue(xt);
}

void excuitYEnd(uint8 va) {
	excuitValue(va);
}




//two orientation clkwise & anticlkwise
void rotate90(uint8 direction) {
	uint8 val = readLineTracer(FIRSTMODULE);

	if (direction == ANTICLKWIS) {

		//change it in backword val <=7
		//10000//11000//01000//00100//01100//11100
		if (val > 7) {
			while ((readLineTracer(FIRSTMODULE) & (1 << 2)) == 0)
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);

			while (readLineTracer(FIRSTMODULE) & (1 << 2))
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);

			while ((readLineTracer(FIRSTMODULE) & (1 << 2)) == 0)
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);
		} else {
			while (readLineTracer(FIRSTMODULE) & (1 << 2))
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);

			while ((readLineTracer(FIRSTMODULE) & (1 << 2)) == 0)
				RobotMove(BACKWORD, 70, FORWARD, 70);
		}
	}

	else if (direction == CLKWIS) {

		//10000//11000//01000//00100//01100//11100
		if (val <= 7) {
			while ((readLineTracer(FIRSTMODULE) & (1 << 2)) == 0)
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);

			while (readLineTracer(FIRSTMODULE) & (1 << 2))
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);

			while ((readLineTracer(FIRSTMODULE) & (1 << 2)) == 0)
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);
		} else {
			while (readLineTracer(FIRSTMODULE) & (1 << 2))
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);

			while ((readLineTracer(FIRSTMODULE) & (1 << 2)) == 0)
				RobotMove(BACKWORD, MAX_SPEED, FORWARD, MAX_SPEED);
		}
	}

}

void route(uint8 xs, uint8 ys, uint8 xe, uint8 ye) {
    uint8 xt = xe-xs;
    uint8 yt = ye-ys;
	uint8 orientation = (xt < 0) ? CLKWIS:ANTICLKWIS;

    excuitYStart(ys);
	rotate90(orientation);
	excuiteX(xs, xe);
	rotate90(orientation);
	excuitYEnd(ye);
	rotate90(orientation);
	rotate90(orientation);
	//setFinalPos();

}
