#include "../config.h"

char x ;
char input[100];
int i=0,j=0;

ISR(USART0_RX_vect) {
    input[i] =UDR0;
    UDR0=input[i++];
}




int main()
{
motor_init();
UART_INIT(UART0);
sei() ;

while(1)
{
	if(x == '8' )
		RobotMove(FORWARD,85,FORWARD,85);
	else if(x=='5')
		RobotMove(BACKWORD,85,BACKWORD,85);
	else if(x == '4')
		RobotMove(FORWARD,85,BACKWORD,85);
	else if(x == '6')
			RobotMove(BACKWORD,85,FORWARD,85);
	else if(x == '0')
			motor_stop();
	else if(x=='9')
			lineFollow();
}

}

