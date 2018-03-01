/***************************************************************
 *  organization : Automated Warehouse Robotics Team
 *  Developer    : Abdallah Mustafa
 ***************************************************************
 *Description About Team :
 Automated Warehouse Robotics project is a graduation project
 for university students in the last year studying
 in the Automatic Control and Computer Science Department
 at Faculty of Engineering,Tanta University.
  ***************************************************************
 *  Source File: GPIO.c
 *  Description: GPIO driver For ATMEGA128
 *  Date   :     22/02/2018
 **************************************************************/

#include <avr/io.h>
#include "GPIO.h"



sint8  GPIO_InitPort (uint8 PortName, uint8 Value)
{
	sint8 state;

	state = 1;
	switch(PortName)
	{
	case 'a':
	case 'A':
		DDRA = Value;
		break;
	case 'b':
	case 'B':
		DDRB = Value;
		break;
	case 'c':
	case 'C':
		DDRC = Value;
		break;
	case 'd':
	case 'D':
		DDRD = Value;
		break;
	case 'e':
	case 'E':
		DDRE = Value;
		break;
	case 'f':
	case 'F':
		DDRF = Value;
		break;
	default:
		state = -1;

	}

	return(state);
}

sint8  GPIO_WritePort(uint8 PortName,uint8 Value)
{
	sint8 state;

	state = 1;
	switch(PortName)
	{
	case 'a':
	case 'A':
		PORTA = Value;
		break;
	case 'b':
	case 'B':
		PORTB = Value;
		break;
	case 'c':
	case 'C':
		PORTC = Value;
		break;
	case 'd':
	case 'D':
		PORTD = Value;
		break;
	case 'e':
	case 'E':
		PORTE = Value;
		break;
	case 'f':
	case 'F':
		PORTF = Value;
		break;
	default:
		state = -1;
	}

	return(state);
}

sint16 GPIO_ReadPort (uint8 PortName)
{
	volatile sint8  state;

	switch(PortName)
	{
	case 'a':
	case 'A':
		state = PINA;
		break;
	case 'b':
	case 'B':
		state = PINB;
		break;
	case 'c':
	case 'C':
		state = PINC;
		break;
	case 'd':
	case 'D':
		state = PIND;
		break;
	case 'e':
	case 'E':
		state = PINE;
		break;
	case 'f':
	case 'F':
		state = PINF;
		break;
	default:
		state = -1;
	}
	return(state);
}

BOOLEAN  GPIO_InitPin (uint8 PortName,uint8 PinNumber,uint8 Direction)
{
	BOOLEAN bState;


	bState = 1;
	switch(PortName)
	{
	case 'a':
	case 'A':
			switch(Direction)
			{
			case INPUT:
			DDRA &= ~(1 << PinNumber);
			break;
			case OUTPUT:
			DDRA |=  (1 << PinNumber);
			break;
			default:
			break;
			}
			break;
	case 'b':
	case 'B':
			switch(Direction)
			{
			case INPUT:
			DDRB &= ~(1 << PinNumber);
			break;
			case OUTPUT:
			DDRB |=  (1 << PinNumber);
			break;
			default:
			break;
			}
			break;
	case 'c':
	case 'C':
		    switch(Direction)
			{
		    case INPUT:
		    DDRC &= ~(1 << PinNumber);
		    break;
		    case OUTPUT:
		    DDRC |=  (1 << PinNumber);
		    break;
		    default:
		    break;
			}
		    break;
	case 'd':
	case 'D':
		   switch(Direction)
		   {
		   case INPUT:
		   DDRD &= ~(1 << PinNumber);
		   break;
		   case OUTPUT:
		   DDRD |=  (1 << PinNumber);
		   break;
		   default:
		   break;
		   }
		   break;
     case 'e':
     case 'E':
    	 switch(Direction)
    	 {
    	 case INPUT:
    	 DDRE &= ~(1 << PinNumber);
    	 break;
    	 case OUTPUT:
    	 DDRE |=  (1 << PinNumber);
    	 break;
    	 default:
    	 break;
    	 }
    	 break;
     case 'f':
     case 'F':
    	 switch(Direction)
    	 {
    	 case INPUT:
    	 DDRF &= ~(1 << PinNumber);
    	 break;
    	 case OUTPUT:
    	 DDRF |=  (1 << PinNumber);
    	 break;
    	 default:
    	 break;
    	 }
    	 break;
    	 default:
    	bState = -1;
		}

	return(bState);
}

sint8  GPIO_SetPin   (uint8 PortName, uint8 PinNumber)
{
	uint8 State;

	if(PinNumber > 7)
	{
		State = -1;
	}
	else
	{
		State = 1;
		switch(PortName)
		{
		case 'a':
		case 'A':
			PORTA |= (1 << PinNumber);
			break;
		case 'b':
		case 'B':
			PORTB |= (1 << PinNumber);
			break;
		case 'c':
		case 'C':
			PORTC |= (1 << PinNumber);
			break;
		case 'd':
		case 'D':
			PORTD |= (1 << PinNumber);
			break;
		case 'e':
		case 'E':
			PORTE |= (1 << PinNumber);
			break;
		case 'f':
		case 'F':
			PORTF |= (1 << PinNumber);
		   break;
		default:
			State = -1;
		}
	}
	return(State);

}

sint8  GPIO_ClearPin (uint8 PortName, uint8 PinNumber)
{
	sint8 State;

	if(PinNumber > 7)
	{
		State = -1;
	}
	else
	{
		State = 1;
		switch(PortName)
		{
		case 'a':
		case 'A':
			PORTA &= ~(1 << PinNumber);
			break;
		case 'b':
		case 'B':
			PORTB &= ~(1 << PinNumber);
			break;
		case 'c':
		case 'C':
			PORTC &= ~(1 << PinNumber);
			break;
		case 'd':
		case 'D':
			PORTD &= ~(1 << PinNumber);
			break;
		case 'e':
		case 'E':
			PORTE &= ~(1 << PinNumber);
			break;
		case 'f':
		case 'F':
			PORTF &= ~(1 << PinNumber);
			break;
		default:
			State = -1;
		}
	}
	return(State);

}

sint8  GPIO_SetPort  (uint8 PortName)
{
	sint8 State;

	State = 1;
	switch(PortName)
	{
	case 'a':
	case 'A':
		PORTA = 0xFF;
		break;
	case 'b':
	case 'B':
		PORTB = 0xFF;
		break;
	case 'c':
	case 'C':
		PORTC = 0xFF;
		break;
	case 'd':
	case 'D':
		PORTD = 0xFF;
		break;
	case 'e':
	case 'E':
		PORTE = 0xFF;
		break;
	case 'f':
	case 'F':
	  PORTF = 0xFF;
		break;
	default:
		State = -1;
	}

	return(State);
}

sint8  GPIO_ClearPort(uint8 PortName)
{
	sint8 State;

	State = 1;
	switch(PortName)
	{
	case 'a':
	case 'A':
		PORTA = 0x00;
		break;
	case 'b':
	case 'B':
		PORTB = 0x00;
		break;
	case 'c':
	case 'C':
		PORTC = 0x00;
		break;
	case 'd':
	case 'D':
		PORTD = 0x00;
		break;
	case 'e':
	case 'E':
	   PORTE = 0x00;
		break;
	case 'f':
	case 'F':
		PORTF = 0x00;
		break;
	default:
		State = -1;
	}

	return(State);
}


sint8  GPIO_TogglePin(uint8 PortName,uint8 PinNumber)
{
	sint8 State;

	if(PinNumber > 7)
	{
		State = -1;
	}
	else
	{
		State = 1;
		switch(PortName)
		{
		case 'a':
		case 'A':
			PORTA ^= (1 << PinNumber);
			break;
		case 'b':
		case 'B':
			PORTB ^= (1 << PinNumber);
			break;
		case 'c':
		case 'C':
			PORTC ^= (1 << PinNumber);
			break;
		case 'd':
		case 'D':
			PORTD ^= (1 << PinNumber);
			break;
		case 'e':
		case 'E':
			PORTE ^= (1 << PinNumber);
			break;
	   case 'f':
       case 'F':
    	   PORTF ^= (1 << PinNumber);
			break;
		default:
			State = -1;
		}
	}
	return(State);
}

sint8  GPIO_CheckPin (uint8 PortName,uint8 PinNumber)
{
	sint8 State = 0;

	if(PinNumber > 7)
	{
		State = -1;
	}
	else
	{
		switch(PortName)
		{
		case 'a':
		case 'A':
			State = (PINA & (1 << PinNumber))>>PinNumber;
			break;
		case 'b':
		case 'B':
			State = (PINB & (1 << PinNumber))>>PinNumber;
			break;
		case 'c':
		case 'C':
			State = (PINC & (1 << PinNumber))>>PinNumber;
			break;
		case 'd':
		case 'D':
			State = (PIND & (1 << PinNumber))>>PinNumber;
			break;
		case 'e':
		case 'E':
			State = (PINE & (1 << PinNumber))>>PinNumber;
			break;
		case 'f':
		case 'F':
			State = (PINF & (1 << PinNumber))>>PinNumber;
			break;
		default:
			State = -1;
		}
	}
	return(State);
}


sint8  GPIO_ROLPin   (uint8 PortName,uint8 PinNumber)
{
	sint8 State;

	if(PinNumber > 7)
	{
		State = -1;
	}
	else
	{
		State = 1;
		switch(PortName)
		{
		case 'a':
		case 'A':
			PORTA = (PORTA << PinNumber) | (PORTA >> (8-PinNumber));
			break;
		case 'b':
		case 'B':
			PORTB = (PORTB << PinNumber) | (PORTB >> (8-PinNumber));
			break;
		case 'c':
		case 'C':
			PORTC = (PORTC << PinNumber) | (PORTC >> (8-PinNumber));
			break;
		case 'd':
		case 'D':
			PORTD = (PORTD << PinNumber) | (PORTD >> (8-PinNumber));
			break;
		case 'e':
		case 'E':
			PORTE = (PORTE << PinNumber) | (PORTE >> (8-PinNumber));
			break;
		case 'f':
		case 'F':
			PORTF = (PORTF << PinNumber) | (PORTF >> (8-PinNumber));
		   break;
		default:
			State = -1;
		}
	}
	return(State);

}


sint8  GPIO_RORPin(uint8 PortName,uint8 PinNumber)
{
	sint8 State;

	if(PinNumber > 7)
	{
		State = -1;
	}
	else
	{
		State = 1;
		switch(PortName)
		{
		case 'a':
		case 'A':
			PORTA = (PORTA >> PinNumber) | (PORTA << (8-PinNumber));
			break;
		case 'b':
		case 'B':
			PORTB = (PORTB >> PinNumber) | (PORTB << (8-PinNumber));
			break;
		case 'c':
		case 'C':
			PORTC = (PORTC >> PinNumber) | (PORTC << (8-PinNumber));
			break;
		case 'd':
		case 'D':
			PORTD = (PORTD >> PinNumber) | (PORTD << (8-PinNumber));
			break;
		case 'e':
		case 'E':
			PORTE = (PORTE >> PinNumber) | (PORTE << (8-PinNumber));
			break;
		case 'f':
		case 'F':
			PORTF = (PORTF >> PinNumber) | (PORTF << (8-PinNumber));
		   break;
		default:
			State = -1;
		}
	}
	return(State);

}
