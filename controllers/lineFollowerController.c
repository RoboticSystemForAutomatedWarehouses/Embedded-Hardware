#include "lineFollowerController.h"

float activeSensor = 0; // Count active sensors
float totalSensor = 0; // Total sensor readings
float avgSensor = 3; // Average sensor reading

float Kp = (MAX_SPEED/(TOTALSENS-AVERAGESENS));   // Max deviation = 5-3 = 2 ||  MAX_SPEED(178.5)/2 = 89.25
float Ki = 0.00015; //0.00015
float Kd = 5; //5

float error = 0;
float previousError = 0;
float totalError = 0;

float power = 0;

int PWM_Right, PWM_Left;

void readSensor(uint8 select) {
	lineTracerValue = readLineTracer(select);

	if(lineTracerValue == 0 ){
		return ;
	}

  for(int i=0; i<5; i++) 
    {
      
      uint8 isActive = ((lineTracerValue>>i)&1);

      if(isActive) {++activeSensor;}

      totalSensor += (isActive * (i+1));
    }
      
    avgSensor = (totalSensor/activeSensor);
    activeSensor = 0; totalSensor = 0;
}

  
void linePID(uint8 select)
{ 
    readSensor(select);
    
    previousError = error; // save previous error for differential 
    error = avgSensor - 3; // Count how much robot deviate from center

    totalError += error; // Accumulate error for integral
    
    power = (Kp*error) + (Kd*(error-previousError)) + (Ki*totalError);
    
    if( power>MAX_SPEED ) { power = MAX_SPEED; }
    if( power<-MAX_SPEED ) { power = -MAX_SPEED; }
    

    if(power<0) // Turn left
    {
      PWM_Right = MAX_SPEED;
      PWM_Left = MAX_SPEED - abs((sint16)power);


    }
    
    else // Turn right
    {
      PWM_Right = MAX_SPEED - (sint16) power;
      PWM_Left = MAX_SPEED;
    }
    PWM_Left  = (PWM_Left/MAX_SPEED)  *100  * (MAX_SPEED/255.0);
    PWM_Right = (PWM_Right/MAX_SPEED) *100  * (MAX_SPEED/255.0);

}

void lineFollow(uint8 select) {
   linePID(select);
   if(select == FIRSTMODULE)
   RobotMove(BACKWORD,PWM_Right,BACKWORD,PWM_Left);
   else
   RobotMove(FORWARD,PWM_Right,FORWARD,PWM_Left);

}
