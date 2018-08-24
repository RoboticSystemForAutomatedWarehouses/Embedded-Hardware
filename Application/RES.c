#include "../config.h"
#include "../communication/reciveTask.h"
#include "../communication/arm.h"





ISR(USART0_RX_vect) {
	//cli();
	taskBuffer[taskBufferCnt] = UDR0;
	//this is super dum but the code dose't run without it
    UDR0 = taskBuffer[taskBufferCnt];
    if(taskBuffer[taskBufferCnt] == '#')
    	newPackage = 1;

    taskBufferCnt++;
}




int main()
{
motor_init();
lineTracer_init();
UART_INIT(UART0);
sei() ;

int cnt = 1500;
		while(cnt--)
		_delay_ms(10);


while(1){
	if(newPackage == 1){
		cli();
		int cnt = 200;
				while(cnt--)
				_delay_ms(10);
		loadTasks();
		excuitePackage();
		//clear buffer &newPackage
		clearTask();
		//UART_Transmit(task[0].id  + '0',UART0);
		sei();
	}
  }
}

