#include "../config.h"


int main(){
  UART_INIT(UART0);
  motor_init();
  while(1){
	 char x = UART_Read(UART0);
	 while(x == '1'){
		 RobotMove(FORWARD,80,FORWARD,80);
	     x = UART_Read(UART0);
	 }
	 UART_Transmit(x,UART0);

	 while(x == '0'){
		 motor_stop();
		 x = UART_Read(UART0);
	}
		 UART_Transmit(x,UART0);
  }
  return 0;
}
