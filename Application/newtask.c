/*
 * newtask.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abdullah
 */

#include "newtask.h"
#define Task_BUFFER_SIZE		105
#define Response_BUFFER_SIZE 50

struct tasks
{
    int  id ;
    int  EPX;
    int  EPY ;
    int  EPZ ;
    int  SPX ;
    int  SPY ;
    int  SPZ ;

}task[3] ;

char task_buffer [Task_BUFFER_SIZE] ;
char Response_buffer[Response_BUFFER_SIZE] ;
int count = 0 ;

void clear_task_buffer()
{
	memset(task_buffer,0,Task_BUFFER_SIZE);
	count = 0 ;
}

ISR(USART0_RX_vect) {
	cli() ;
	task_buffer[count] = UDR0 ;
	count++ ;
	if(count == Task_BUFFER_SIZE){count = 0;}
}

void reguest_task_again()
{
	UART_Transmit_string("I need the tasks again",UART0) ;
}

void tasks_dividing()
{
	int d = 0 ;
	int number_of_tasks = ((task_buffer[0]-'0')*10) + (task_buffer[1]-'0') ;
	int total_size = ((number_of_tasks * 21) + 2) ;
	int cnt = 2;
	while(task_buffer[cnt] != '#')
	{
	if(task_buffer[cnt] == '/' )
	{
		if(cnt%3 == 2 || cnt == 2 ) {cnt++ ; continue ;}
	   else {request_task_again() ; clear_task_buffer() ; break ;}
	}
	if(task_buffer[cnt] != '/' && number_of_tasks != 0)
	{
		int determine = ((cnt/3 < 8)*0)+((((cnt/3)<15) && ((cnt/3)>= 8))*1)+((((cnt/3)<22) && ((cnt/3)>= 15))*2) ;
	    if(cnt % 21 == 3) {task[determine].id = ((task_buffer[cnt]-'0')*10) + (task_buffer[cnt+=1]-'0') ; }
	    else if(cnt % 21 == 6) {task[determine].SPX = ((task_buffer[cnt]-'0')*10) + (task_buffer[cnt+=1]-'0') ; d++ ;}
	    else if(cnt % 21 == 9) {task[determine].SPY = ((task_buffer[cnt]-'0')*10) + (task_buffer[cnt+=1]-'0') ; d++ ;}
	    else if(cnt % 21 == 12) {task[determine].SPZ = ((task_buffer[cnt]-'0')*10) + (task_buffer[cnt+=1]-'0') ;d ++ ;}
	    else if(cnt % 21 == 15) {task[determine].EPX = ((task_buffer[cnt]-'0')*10) + (task_buffer[cnt+=1]-'0') ;d++ ;}
	    else if(cnt % 21 == 18) {task[determine].EPY = ((task_buffer[cnt]-'0')*10) + (task_buffer[cnt+=1]-'0') ;d++ ;}
	    else if(cnt % 21 == 0) {task[determine].EPZ = ((task_buffer[cnt]-'0')*10) + (task_buffer[cnt+=1]-'0') ;d++ ;}
	}
	if(d == 7) {number_of_tasks-- ; d = 0 ;}
		cnt++ ;
	}
}

int main ()
{
	UART_INIT(UART0);
	clear_task_buffer();
	tasks_dividing() ;
}
