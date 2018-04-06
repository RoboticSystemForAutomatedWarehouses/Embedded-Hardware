#include "SPI.h"


void SPI_Master(void)
{
	/******** Configure SPI Master Pins *********
	 * SS(PB0)   --> Output
	 * MOSI(PB2) --> Output
	 * MISO(PB3) --> Input
	 * SCK(PB1) --> Output
	 ********************************************/
	DDRB = DDRB | (1<<PB0);
	DDRB = DDRB | (1<<PB2);
	DDRB = DDRB & ~(1<<PB3);
	DDRB = DDRB | (1<<PB1);

	SPCR = (1<<SPE) | (1<<MSTR); // enable SPI + enable Master + choose SPI clock = Fosc/4
}

void SPI_Slave(void)
{
	/******** Configure SPI Slave Pins *********
	 * SS(PB0)   --> Input
	 * MOSI(PB2) --> Input
	 * MISO(PB3) --> Output
	 * SCK(PB1) --> Input
	 ********************************************/
	DDRB = DDRB & (~(1<<PB0));
	DDRB = DDRB & (~(1<<PB2));
	DDRB = DDRB | (1<<PB3);
	DDRB = DDRB & (~(1<<PB1));
	SPCR = (1<<SPE); // just enable SPI + choose SPI clock = Fosc/4
}

void SPI_sendByte(const uint8 data)
{
	SPDR = data; //send data by SPI
	while(!(SPSR&(1<<SPIF))){} //wait until SPI interrupt flag=1 (data is sent correctly)



}

uint8 SPI_recieveByte(void)
{
   while(!(SPSR&(1<<SPIF))){} //wait until SPI interrupt flag=1(data is receive correctly)
   return SPDR; //return the received byte from SPI data register
}

void SPI_SendString(const uint8 *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		SPI_sendByte(Str[i]);
		i++;
	}
}

void SPI_ReceiveString(char *Str)
{
	unsigned char i = 0;
	Str[i] = SPI_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = SPI_recieveByte();
	}
	Str[i] = '\0';
}
