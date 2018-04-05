#include "../config.h"

//line trace 1 is the leftmost sensor
int main(){
 motor_init();
 lineTracer_init();
  _delay_ms(1000);
while(1){
     excuiteXY();
	//lineFollow();
	//_delay_ms(3);
	//RobotMove(FORWARD,100,FORWARD,100);
}

  return 0;

}


