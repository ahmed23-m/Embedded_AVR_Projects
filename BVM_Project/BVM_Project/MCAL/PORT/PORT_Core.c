/*
 * PORT_Core.c
 *
 * Created: 2024/2/17 11:04:23 PM
 *  Author: dasah
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define		PORT_A     ((uint8)0U)
#define		PORT_B     ((uint8)1U)
#define		PORT_C     ((uint8)2U)
#define		PORT_D     ((uint8)3U)
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void PORT_Init(void)
{
	uint8 Loop_counter = 0,	PORT = 0,	PIN = 0,	Dir = 0;
	
	for(Loop_counter = 0; Loop_counter<DEFINED_PINS; Loop_counter++)
	{
		PORT = PORT_Init_Pins[Loop_counter].PIN_Order / Number_PORT_PINS;
		PIN  = PORT_Init_Pins[Loop_counter].PIN_Order % Number_PORT_PINS;
		Dir  = PORT_Init_Pins[Loop_counter].PIN_Dir;
		
		switch(Dir)
		{
			case PIN_OUTPUT:
			{	
				switch(PORT)
				{
					case PORT_A:
						SET_Bit(DIO_PORTA->DDR,PIN);
						break;
					case PORT_B:
						SET_Bit(DIO_PORTB->DDR,PIN);
						break;
					case PORT_C:
						SET_Bit(DIO_PORTC->DDR,PIN);
						break;
					case PORT_D:
						SET_Bit(DIO_PORTD->DDR,PIN);
						break;
					default:
						break;
				}
			}
			break;
			case PIN_INPUT:
			{
				switch(PORT)
				{
					case PORT_A:
						CLR_Bit(DIO_PORTA->DDR,PIN);
						break;
					case PORT_B:
						CLR_Bit(DIO_PORTB->DDR,PIN);
						break;
					case PORT_C:
						CLR_Bit(DIO_PORTC->DDR,PIN);
						break;
					case PORT_D:
						CLR_Bit(DIO_PORTD->DDR,PIN);
						break;
					default:
						break;
				}
			}
			break;
			
			default:
			break;
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
