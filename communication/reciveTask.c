/*
 * newtask.c
 *
 *  Created on: ??أ¾/??أ¾/????
 *      Author: Abdullah
 */

#include "reciveTask.h"
#include <string.h>


struct tasks task[3];
uint8 volatile taskBuffer [TASKBUFFERSIZE] ;
uint8 volatile newPackage = 0;
uint8 volatile taskBufferCnt = 0;
uint8 numOfTasks ;

void celarTaskBuffer()
{
	//clear taskBuffer Array
	for(int i = 0 ; i < TASKBUFFERSIZE ;i++)
		taskBuffer[i] = 0;
	taskBufferCnt = 0 ;
	newPackage =0;
	//motor_stop();

}




void loadTasks()
{
	int d = 0 ;
	numOfTasks = ((taskBuffer[0]-'0')*10) + (taskBuffer[1]-'0');
	//int total_size = ((numOfTasks * 21) + 2) ;
	int cnt = 2;
	while(taskBuffer[cnt] != '#')
	{
	if(taskBuffer[cnt] == '/' )
	{
		if(cnt%3 == 2 || cnt == 2 ) {cnt++ ; continue ;}
	   else {celarTaskBuffer() ; break ;}
	}
	if(taskBuffer[cnt] != '/')
	{
		int determine = ((cnt/3 < 8)*0)+((((cnt/3)<15) && ((cnt/3)>= 8))*1)+((((cnt/3)<22) && ((cnt/3)>= 15))*2) ;
	    if(cnt % 21 == 3) {task[determine].id = ((taskBuffer[cnt]-'0')*10) + (taskBuffer[cnt+1]-'0') ; }
	    else if(cnt % 21 == 6) {task[determine].SPX = ((taskBuffer[cnt]-'0')*10) + (taskBuffer[cnt+1]-'0') ; d++ ;}
	    else if(cnt % 21 == 9) {task[determine].SPY = ((taskBuffer[cnt]-'0')*10) + (taskBuffer[cnt+1]-'0') ; d++ ;}
	    else if(cnt % 21 == 12) {task[determine].SPZ = ((taskBuffer[cnt]-'0')*10) + (taskBuffer[cnt+1]-'0') ;d ++ ;}
	    else if(cnt % 21 == 15) {task[determine].EPX = ((taskBuffer[cnt]-'0')*10) + (taskBuffer[cnt+1]-'0') ;d++ ;}
	    else if(cnt % 21 == 18) {task[determine].EPY = ((taskBuffer[cnt]-'0')*10) + (taskBuffer[cnt+1]-'0') ;d++ ;}
	    else if(cnt % 21 == 0) {task[determine].EPZ = ((taskBuffer[cnt]-'0')*10) + (taskBuffer[cnt+1]-'0') ;d++ ;}
	}
	if(d == 7) {numOfTasks-- ; d = 0 ;}
		cnt++ ;
	}
}
