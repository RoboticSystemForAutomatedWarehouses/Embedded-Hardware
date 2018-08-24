/*
#include "../config.h"
#include "../communication/reciveTask.h"
#include "../communication/arm.h"


int x;

ISR(USART0_RX_vect) {
	//cli();
	x = taskBuffer[taskBufferCnt] = UDR0;
	//this is super dum but the code dose't run without it
    UDR0 = taskBuffer[taskBufferCnt];
    if(taskBuffer[taskBufferCnt] == '#')
    	newPackage = 1;

    taskBufferCnt++;
}


void robotReverse(){
	RobotMove(FORWARD,77,BACKWORD,77);
	int cnt = 900;
	while(cnt--)
	_delay_ms(10);
	motor_stop();
}

int main()
{
motor_init();
lineTracer_init();
UART_INIT(UART0);
armInitConnection();
sei() ;
delayMs(5000);
  route(0,0,0,2);
  armStart();
  waitArm();
  route(0,2,0,0);
  armStart();
  waitArm();
  motor_stop();
}
//route(0,0,0,2);
//route(0,2,0,0);


/*
while(1){
	if(x == '5')
		RobotMove(FORWARD,100,FORWARD,100);
	else if(x == '2')
		RobotMove(BACKWORD,100,BACKWORD,100);
	else if(x == '3')
		RobotMove(FORWARD,100,FORWARD,0);
	else if(x == '4')
		RobotMove(FORWARD,0,FORWARD,100);
	else
		motor_stop();
	clearTask();
*/
	//	lineFollow(FIRSTMODULE);
	/*
	uint8 x = readLineTracer(FIRSTMODULE);
	if(x==1)
		RobotMove(FORWARD,100,FORWARD,0);
	else if(x == 2)
		RobotMove(FORWARD,0,FORWARD,100);
	else if(x == 4)
		RobotMove(FORWARD,100,FORWARD,100);
	else if(x == 8)
		RobotMove(BACKWORD,100,BACKWORD,0);
	else if(x == 16)
		RobotMove(BACKWORD,0,BACKWORD,100);
	else
		RobotMove(FORWARD,100,FORWARD,100);
*/
//excuitValue(3,FIRSTMODULE);
//excuitYStart(3,FIRSTMODULE);
//rotate90(ANTICLKWIS,FIRSTMODULE);
//route(3,3,1,3);
//excuitYEnd(2,SECONDMODULE);
//excuiteX(1,3);
//rotate90(CLKWIS);
//motor_stop();
//rotate90(CLKWIS);
//motor_stop();
//while(1){
//lineFollow(SECONDMODULE);
//}
	//lineFollow(SECONDMODULE);
	/*
	//robotReverse();
	route(1,3,3,3);
	//rotat90(FORWARD);
	motor_stop();
	while(1);
	*/
