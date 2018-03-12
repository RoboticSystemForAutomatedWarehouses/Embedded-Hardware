#include "motor.h"


/*********************************************************************
* Function    : PWM_init(uint8_t);
*
* DESCRIPTION : Initializes the PWM in fast mode.
*
* PARAMETERS  : The number of 8 bit timer to set for fast mode pwm.
*               Either Timer 0 or Timer 2.
*
* Return Value: Nothing
***********************************************************************/
 void motor_init(){

//initilaize motor pins

//initilaize pwm
   PWM_init(TIMER_0);
   PWM_init(TIMER_2);

//inialize direction pins
   GPIO_InitPin(motorDirectionsPort,rightMotorDirection1,OUTPUT);
   GPIO_InitPin(motorDirectionsPort,rightMotorDirection2,OUTPUT);
   GPIO_InitPin(motorDirectionsPort,leftMotorDirection1,OUTPUT);
   GPIO_InitPin(motorDirectionsPort,leftMotorDirection2,OUTPUT);

//don't need it using micro vcc to power ic
//initilaize ic PORT
   //GPIO_InitPin(motorDriverICPort,motorDriverICVs,OUTPUT);

}


/*********************************************************************
* Function    : RobotMove(void);
*
* DESCRIPTION : Sets the direction in clockwise direction.
*
* PARAMETERS  : 4 PARAMETER _each motor direction and speed_
*
* Return Value: void
***********************************************************************/
void RobotMove(uint8 leftMotorDirection , uint8 RightmotorSpeed ,uint8 rightMotorDirection, uint8 leftMotorSpeed){
   //set right motor direction
   if(rightMotorDirection == FORWARD){
    setDirectionForward(RIGHT);
  }
  else if(rightMotorDirection == BACKWORD){
    setDirectionBackword(RIGHT);
  }

    //set left motor direction
    if(leftMotorDirection == FORWARD){
     setDirectionForward(LEFT);
   }
   else if(leftMotorDirection == BACKWORD){
     setDirectionBackword(LEFT);
   }

//set custome speed on each side
   set_speed_left(leftMotorSpeed);
   set_speed_right(RightmotorSpeed);
 }


 /*********************************************************************
 * Function    : move_forward(void);
 *
 * DESCRIPTION : Sets the direction in clockwise direction.
 *
 * PARAMETERS  : motor_which motor to applay function on_
 *
 * Return Value: void
 ***********************************************************************/
 void setDirectionForward(uint8 motor){
   if(motor == RIGHT){
     //set right motor forward
     GPIO_SetPin(motorDirectionsPort,rightMotorDirection1);
     GPIO_ClearPin(motorDirectionsPort,rightMotorDirection2);
   }
   else if(motor == LEFT){
     //set right motor forward
     GPIO_SetPin(motorDirectionsPort,leftMotorDirection1);
     GPIO_ClearPin(motorDirectionsPort,leftMotorDirection2);
   }
 }


 /*********************************************************************
 * Function    : move_backward();
 *
 * DESCRIPTION : Sets the direction in counter clockwise direction.
 *
 * PARAMETERS  : motor_which motor to applay function on_
 *
 * Return Value: void
 ***********************************************************************/
  void setDirectionBackword(uint8 motor){
    if(motor == RIGHT){
      //set right motor backword
      GPIO_ClearPin(motorDirectionsPort,rightMotorDirection1);
      GPIO_SetPin(motorDirectionsPort,rightMotorDirection2);
    }
    else if(motor == LEFT){
      //set right motor backword
      GPIO_ClearPin(motorDirectionsPort,leftMotorDirection1);
      GPIO_SetPin(motorDirectionsPort,leftMotorDirection2);
    }
    set_speed_left(100);
    set_speed_right(100);
  }

  /*********************************************************************
  * Function    : set_speed_left(uint8_t speed);
  *
  * DESCRIPTION : Changes the DutyCycle on TIMER_0 .
  *
  * PARAMETERS  : uint8_t speed sets A value to the DutyCycle
  *                between 0 (0 %) and 255 (100 %).
  *
  * Return Value: Nothing
  ***********************************************************************/
  void set_speed_left (uint8_t speed)
  {
	  PWM_SetDutyCycle( speed, TIMER_0);
  }

  /*********************************************************************
  * Function    : set_speed_right(uint8_t speed);
  *
  * DESCRIPTION : Changes the DutyCycle on TIMER_2 .
  *
  * PARAMETERS  : uint8_t speed sets A value to the DutyCycle
  *                between 0 (0 %) and 255 (100 %).
  *
  * Return Value: Nothing
  ***********************************************************************/
  void set_speed_right (uint8_t speed)
  {
	  PWM_SetDutyCycle( speed, TIMER_2);
  }

  /*********************************************************************
  * Function    : move_right(uint8_t speed);
  *
  * DESCRIPTION : Moves to the rigth by stoping the right motor and
  *               running the left motor to some speed
  *
  * PARAMETERS  : uint8_t speed_left sets A value to the DutyCycle
  *                between 0 (0 %) and 255 (100 %).
  *
  * Return Value: Nothing
  ***********************************************************************/
   void move_right(uint8_t speed_left)
   {
	    set_speed_right(0);
		  set_speed_left(speed_left);

   }

   /*********************************************************************
   * Function    : move_left(uint8_t speed);
   *
   * DESCRIPTION : Moves to the left by stoping the left motor(0) and
   *               running the right motor to some speed
   *
   * PARAMETERS  : uint8_t speed_right sets A value to the DutyCycle
   *                between 0 (0 %) and 255 (100 %).
   *
   * Return Value: Nothing
   ***********************************************************************/
    void move_left(uint8_t speed_right)
    {
      set_speed_right(speed_right);
	    set_speed_left(0);

    }

    /*********************************************************************
    * Function    : motor_stop();
    *
    * DESCRIPTION : stoping both the left and the right motors.
    *
    * PARAMETERS  : Nothing
    *
    * Return Value: Nothing
    ***********************************************************************/
	 void motor_stop()
	 {
     set_speed_left(0);
     set_speed_right(0);
	 }
