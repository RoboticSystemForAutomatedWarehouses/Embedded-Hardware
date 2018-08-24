
#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include "uart_config.h"
#include <math.h>

#define BAUD_RATE ((FOSC)/(BAUD*16UL)-1) // Eqn to calculate BuadRate



/*********************************************************************
* Function    : UART_INIT(uint8_t UART));
*
* DESCRIPTION : initial the UART
*
* PARAMETERS  : none
*                
*
* Return Value: Nothing
***********************************************************************/
void UART_INIT(uint8_t UART);




/*********************************************************************
* Function    : UART_Transmit(uint8_t data, uint8_t UART);
*
* DESCRIPTION : transmit data
*
* PARAMETERS  :uint8_t data, uint8_t UART: Number of UART channel
*
*
* Return Value: Nothing
***********************************************************************/
void UART_Transmit(uint8_t data, uint8_t UART);





/*********************************************************************
* Function    : UART_Read(uint8_t UART);
*
* DESCRIPTION : recieve data
*
* PARAMETERS  : uint8_t UART: Number of UART channel
*
*
* Return Value: udr value
***********************************************************************/
uint8_t UART_Read(uint8_t UART);





/*********************************************************************
* Function    : UART_Transmit_string (char * str, uint8_t UART);
*
* DESCRIPTION : transmit string
*
* PARAMETERS  : char * str, uint8_t UART: Number of UART channel
*
*
* Return Value: Nothing
***********************************************************************/
void UART_Transmit_string (uint8 * str,uint8_t UART);


#endif /* UART_H_ */
