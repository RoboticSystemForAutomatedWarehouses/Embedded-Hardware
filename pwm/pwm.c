  /***************************************************************
 *  Source File: EF_PWM.c
 *
 *  Description: PWM driver for ATMEGA32
 *
 **************************************************************/
#include "pwm.h"


/*********************************************************************
* Function    : PWM_init(U8_t u8TimerNumber);
*
* DESCRIPTION : Initializes the PWM in fast mode.
*
* PARAMETERS  : The number of 8 bit timer to set for fast mode pwm.
*               Either Timer 0 or Timer 2.
*
* Return Value: Nothing
***********************************************************************/
void PWM_init(uint8_t u8TimerNumber)
{
	switch(u8TimerNumber)
	{
	    case TIMER_2:
	    	 /* OC2 PIN TO BE OUTPUT */
	    	TIMER2_DDR |= (1<<OC2_OUTPUT_SETTER);
	    	 /*Disable Timer 2*/
	    	 TCCR2 = DISABLE_MODULE_VALUE;
	    	 /* Setting pre scaler */
	    	 TCCR2 = PRESCLR1_VALUE|(FAST_PWM)|(NON_INVERT);
	    	 /* Initializing the timer with zero */
	    	 TCNT2 = ZER0_INITIALIZER;
	         break;

	    case TIMER_0:
	    	/* OC0 PIN TO BE OUTPUT */
	    	TIMER0_DDR |= (1<<OC0_OUTPUT_SETTER);
	    	/* Disable Timer 0 */
	    	TCCR0 = DISABLE_MODULE_VALUE;
	    	/* Setting pre scaler */
	    	TCCR0 = (PRESCLR1_VALUE)|(FAST_PWM)|(NON_INVERT);
	    	/* Initializing the timer with zero */
	    	TCNT0 = ZER0_INITIALIZER;
	    	break;

	    default:
	    	 break;
	}
	return;
}

/****************************************************************************
* Function    : PWM_SetDutyValue(U8_t DutyValue, U8_t u8TimerNumber)
*
* DESCRIPTION : Sets duty cycle for the  PWM
*
* PARAMETER 1 : The duty cycle value. A value between 0 (0 %) and 255 (100 %).
*
* PARAMETER 2 : The number of 8 bit timer. Either Timer 0 or Timer 2.
*
* Return Value: Nothing
******************************************************************************/
void PWM_SetDutyValue(uint8_t DutyValue, uint8_t u8TimerNumber)
{

	  switch(u8TimerNumber)
	  {

	  case TIMER_2:
		  /*Output Compare Register  OCR2
		   * contains an 8-bit value that is continuously compared
		   * with the counter value (TCNT2). A match can be used to
		   * generate an output compare interrupt
		   * */
		  OCR2 = DutyValue;
		  break;

	  case TIMER_0:
		  /*Output Compare Register  OCR0
		   * contains an 8-bit value that is continuously compared
		   * with the counter value (TCNT0). A match can be used to
		   * generate an output compare interrupt
		   * */
		  OCR0 = DutyValue;
		  break;

	  default:
		   break;
	  }
	  return;
}

/****************************************************************************
* Function    : PWM_SetDutyCycle(U8_t DutyCycle, U8_t u8TimerNumber)
*
* DESCRIPTION : Sets duty cycle for the  PWM
*
* PARAMETER 1 : The duty cycle value. A value between (0 %) and (100 %).
*
* PARAMETER 2 : The number of 8 bit timer. Either Timer 0 or Timer 2.
*
* Return Value: Nothing
******************************************************************************/
void PWM_SetDutyCycle(uint8_t DutyCycle, uint8_t u8TimerNumber)
{
	  uint8_t PWM_actual_Duty ;           //duty cycle is represented by a number from 0->255


	  PWM_actual_Duty = (DutyCycle * TIMER_MAX_VALUE) / DUTY_CYCLE_MAX_VALUE;
	  /*Output Compare Register OCRx
	   * contains an 8-bit value that is continuously compared
	   * with the counter value (TCNTx). A match can be used to
	   * generate an output compare interrupt
	   **/
	  switch(u8TimerNumber)
	  {

	  case TIMER_2:
		  OCR2 = PWM_actual_Duty;
		  break;

	  case TIMER_0:
		  OCR0 = PWM_actual_Duty;
		  break;

	  default:
		  break;
	  }
}
