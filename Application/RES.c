/*
#include "../config.h"
#include "../communication/reciveTask.h"





ISR(USART0_RX_vect) {
	//cli();
	taskBuffer[taskBufferCnt] = UDR0;
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
sei() ;
/*
int cnt = 1500;
		while(cnt--)
		_delay_ms(10);
*/
/*
while(1){
	if(newPackage == 1){
		cli();
	//	UART_Transmit_string(taskBuffer,UART0);
		int cnt = 2000;
				while(cnt--)
				_delay_ms(10);
		RobotMove(FORWARD,80,FORWARD,80);
		loadTasks();
		celarTaskBuffer();
		UART_Transmit(task[0].id  + '0',UART0);


/*
			UART_Transmit(task[0].id  + '0',UART0);
			UART_Transmit(task[0].SPX + '0',UART0);
			UART_Transmit(task[0].SPY + '0',UART0);
			UART_Transmit(task[0].SPZ + '0',UART0);
		    UART_Transmit(task[0].EPX + '0',UART0);
			UART_Transmit(task[0].EPY + '0',UART0);
			UART_Transmit(task[0].EPZ + '0',UART0);

		sei();
	}

}
/*
while(1)
{
	//robotReverse();
	route(1,3,3,3);
	//rotat90(FORWARD);
	motor_stop();
	while(1);
}
*/
/*
	//RobotMove(FORWARD,80,FORWARD,80);
}
*
