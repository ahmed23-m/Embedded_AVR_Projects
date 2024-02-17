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

#include "LED_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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
void LED_Init(uint8 Color){
	switch(Color)
	{
		case RED:
		SET_Bit(DIO_PORTB->DDR , 7);
		break;
		case GREEN:
		SET_Bit(DIO_PORTA->DDR , 4);
		break;
		case BLUE:
		SET_Bit(DIO_PORTA->DDR , 5);
		break;
		case YELLOW:
		SET_Bit(DIO_PORTA->DDR , 6);
		break;
		default:
		break;
	}
	
}


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
void LED_ON(uint8 Color){
	switch(Color)
	{
		case RED:
		SET_Bit(DIO_PORTB->PORT , 7);
		break;
		case GREEN:
		SET_Bit(DIO_PORTA->PORT , 4);
		break;
		case BLUE:
		SET_Bit(DIO_PORTA->PORT , 5);
		break;
		case YELLOW:
		SET_Bit(DIO_PORTA->PORT , 6);
		break;
		default:
		break;
	}
}


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
void LED_OFF(uint8 Color){
	switch(Color)
	{
		case RED:
		CLR_Bit(DIO_PORTB->PORT , 7);
		break;
		case GREEN:
		CLR_Bit(DIO_PORTA->PORT , 4);
		break;
		case BLUE:
		CLR_Bit(DIO_PORTA->PORT , 5);
		break;
		case YELLOW:
		CLR_Bit(DIO_PORTA->PORT , 6);
		break;
		default:
		break;
	}
}


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
void LED_Toggle(uint8 Color){
	switch(Color)
	{
		case RED:
		TOGGLE_Bit(DIO_PORTB->PORT , 7);
		break;
		case GREEN:
		TOGGLE_Bit(DIO_PORTA->PORT , 4);
		break;
		case BLUE:
		TOGGLE_Bit(DIO_PORTA->PORT , 5);
		break;
		case YELLOW:
		TOGGLE_Bit(DIO_PORTA->PORT , 6);
		break;
		default:
		break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
