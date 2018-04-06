#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_
#include "../config.h"

void SPI_Master(void);
void SPI_Slave(void);
void SPI_sendByte(const uint8 data);
uint8 SPI_recieveByte(void);
void SPI_sendString(const uint8 *Str);
void SPI_receiveString(char *Str);



#endif /* MCAL_SPI_H_ */
