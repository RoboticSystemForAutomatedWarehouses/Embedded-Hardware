#include "../config.h"


int main(){
  UART_INIT(UART0);
  while(1){
	 char x = UART_Read(UART0);
	 x+=3;
	 UART_Transmit(x,UART0);
  }
  return 0;
}
