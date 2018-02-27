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
 *  Source File: GPIO.h
 *  Description: GPIO driver For ATMEGA128
 *  Date   :     22/02/2018
 **************************************************************/


#include "std_types.h"
#include "config.h"

#define INPUT   0
#define OUTPUT  1

/*********************************************************************
* Function    : GPIO_InitPort(uint8 PortName, uint8 Value)
* DESCRIPTION : This function used to Initialize port.
* PARAMETERS  :  
*             -PortName: write which port need to access.
*             -Value   : write the value (hex,binary,decimal)
* Return Value: return -1 if user enter wrong inputs or return 1 if OK.
***********************************************************************/
sint8  GPIO_InitPort (uint8 PortName, uint8 Value);

/*********************************************************************
* Function    : GPIO_WritePort(uint8 PortName,uint8 Value);
* DESCRIPTION : This function used to write value to any port.
* PARAMETERS  :  
*              -PortName: write which port need to access.
*              -Value   : write the value (hex,binary,decimal)
* Return Value: return -1 if user enter wrong inputs or return 1 if OK.
***********************************************************************/
sint8  GPIO_WritePort(uint8 PortName, uint8 Value);

/*********************************************************************
* Function    : GPIO_ReadPort (uint8 PortName);
* DESCRIPTION : This function used to read value from any port.
* PARAMETERS  :  
*             -PortName: write which port need to access.
* Return Value: return -1 if user enter wrong inputs or return value of port.
***********************************************************************/
sint16 GPIO_ReadPort (uint8 PortName);

/*********************************************************************
* Function    : GPIO_InitPin (uint8 PortName, uint8 PinNumber,uint8 Direction)
* DESCRIPTION : This function used to Initialize port.
* PARAMETERS  :
*              -PortName: write which port need to access.
*              -PinNumber: Pin Number between 0  and 7
*              -Direction: Either INPUT or OUTPUT
* Return Value: return -1 if user enter wrong inputs or return 1 if OK.
***********************************************************************/
BOOLEAN  GPIO_InitPin (uint8 PortName, uint8 PinNumber,uint8 Direction);

/*********************************************************************
* Function    : GPIO_SetPin (uint8 PortName, uint8 PinNumber);
* DESCRIPTION : This function used to set pin any port.
* PARAMETERS  :  
*             -PortName:  write which port need to access.
*             -PinNumber: write the value in range (0 -> 7).
* Return Value: return -1 if user enter wrong inputs or return 1 if OK.
***********************************************************************/
sint8  GPIO_SetPin   (uint8 PortName, uint8 PinNumber);

/*********************************************************************
* Function    : GPIO_ClearPin (uint8 PortName,uint8 PinNumber);
* DESCRIPTION : This function used to clear Pin in port.
* PARAMETERS  :
*            PortName: write which port need to access.
*            PinNumber:write the value in range (0 -> 7).
*Return Value: return -1 if user enter wrong inputs or return 1 if OK.
***********************************************************************/
sint8  GPIO_ClearPin (uint8 PortName, uint8 PinNumber);

/*********************************************************************
* Function    : GPIO_SetPort  (uint8 PortName);
* DESCRIPTION : This function used to set port.
* PARAMETERS  :  
*            -PortName: write which port need to access.
* Return Value: return -1 if user enter wrong inputs or return 1 if OK.
***********************************************************************/
sint8 GPIO_SetPort  (uint8 PortName);

/*********************************************************************
* Function    : GPIO_ClearPort(uint8 PortName);
* DESCRIPTION : This function used to clear port.
* PARAMETERS  :  
*            -PortName: write which port need to access.
* Return Value: return -1 if user enter wrong inputs or return 1 if OK.
***********************************************************************/
sint8  GPIO_ClearPort(uint8 PortName);

/*********************************************************************
* Function    : GPIO_TogglePin(uint8 PortName, uint8 PinNumber);
* DESCRIPTION : This function used to toggle any PIN in any PORT.
* PARAMETERS  :  
*             PortName:  write which port need to access.
*             PinNumber: write the value
* Return Value: return -1 if user enter wrong inputs or return 1 if OK.
***********************************************************************/
sint8  GPIO_TogglePin(uint8 PortName, uint8 PinNumber);

/*********************************************************************
* Function    : GPIO_CheckPin (uint8 PortName, uint8 PinNumber);
* DESCRIPTION : This function used to Check pin status .
* PARAMETERS  :  
*              PortName:   write which port need to access.
*              PinNumber:  write the value
* Return Value: The function will return -1 if user enter wrong inputs.
*               or return 1 if Pin ON and 0 If pin OFF.  
***********************************************************************/
 sint8  GPIO_CheckPin (uint8 PortName, uint8 PinNumber);

 /*********************************************************************
 * Function    : GPIO_ROLPin (uint8 PortName, uint8 PinNumber);
 * DESCRIPTION : This function used to Rotate left pin at any port.
 *
 * PARAMETERS  :
 *           PortName: write which port need to access.
 *           PinNumber:write the value in range (0 -> 7).
 * Return Value: return -1 if user enter wrong inputs or return 1 if OK.
 ***********************************************************************/
 sint8  GPIO_ROLPin   (uint8 PortName, uint8 PinNumber);


 /*********************************************************************
 * Function    : GPIO_RORPin (uint8 PortName, uint8 PinNumber);
 * DESCRIPTION : This function used to Rotate right pin any port.
 * PARAMETERS  :
 *            PortName:  write which port need to access.
 *            PinNumber: write the value in range (0 -> 7).
 * Return Value: return -1 if user enter wrong inputs or return 1 if OK.
 ***********************************************************************/
 sint8  GPIO_RORPin   (uint8 PortName, uint8 PinNumber);
