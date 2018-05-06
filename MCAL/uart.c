#include "uart.h"

void UART_INIT(uint8_t UART)
{
	switch (UART)
	{
	case UART0:
		//Send the low 8 bits of the UBRR0
		UBRR0L = (uint8_t)(BAUD_RATE);
		//Send the high 8 bits of the UBRR0
		UBRR0H = (uint8_t)((BAUD_RATE)>>8);
		//Enable transmit and receiver
		UCSR0B |=((1<<RXEN0)|(1<<TXEN0));
		//8-bit data frame, 1 stop bit, No parity, Asynchronous mode
		UCSR0B |=((1<<UCSZ01)|(1<<UCSZ00));
		//Enable Recive inpterrupt for UART0
		UCSR0B |=(1<<RXCIE0);
		break;

	case UART1:
		//Send the low 8 bits of the UBRR0
		UBRR1L = (uint8_t)(BAUD_RATE);
		//Send the high 8 bits of the UBRR0
		UBRR1H = (uint8_t)((BAUD_RATE)>>8);
		//Enable transmit and receiver
		UCSR1B |=((1<<RXEN1)|(1<<TXEN1));
		//8-bit data frame, 1 stop bit, No parity, Asynchronous mode
		UCSR1B |=((1<<UCSZ11)|(1<<UCSZ10));
		//Enable Recive inpterrupt for UART1
		UCSR1B |=(1<<RXCIE1);
		break;
	}

}



void UART_Transmit(uint8 data, uint8_t UART)
{
	switch (UART)
	{
	case UART0 :
		// wait until the buffer is empty
		while( !(UCSR0A & (1<<UDRE0)) ) ;
		UDR0 =data;
		break;
	case UART1:
		// wait until the buffer is empty
		while( !(UCSR1A & (1<<UDRE1)) ) ;
		UDR1 =data;
		break;
	}

}



uint8_t UART_Read(uint8_t UART)
{
	switch (UART)
	{
	case UART0:
		//wait until receiving complete
		while( !(UCSR0A & (1<<RXC0)) ) ;
		return UDR0;
		break;
	case UART1:
		//wait until the receiving complete
		while( !(UCSR1A & (1<<RXC1)) ) ;
		return UDR1;
		break;
	}
}


void UART_Transmit_string (uint8 * str,uint8_t UART)
{
	unsigned char i= 0;
	//send initial #
	//UDR0 = '#';
	 while(str[i]!=0)
	    {UART_Transmit(str[i],UART0) ; i++;}
}
/*
void UART_receiveString(unsigned char *Str,uint8_t UART)
{
	unsigned char i = 0;
	Str[i] = UART_Read(UART) ;
	while(Str[i] != '#')                //you need to cin '#' to complete this task or choose any symbol
	{
		i++;
		Str[i] = UART_Read(UART) ;
	}
	Str[i] = '\0';
}
*/
/*ISR(USART1_RX_vect) {
		//Here goes the ISR code of UART0
}*/
/*
ISR(USART1_RX_vect) {
		//Here goes the ISR code of UART1
}
*/
