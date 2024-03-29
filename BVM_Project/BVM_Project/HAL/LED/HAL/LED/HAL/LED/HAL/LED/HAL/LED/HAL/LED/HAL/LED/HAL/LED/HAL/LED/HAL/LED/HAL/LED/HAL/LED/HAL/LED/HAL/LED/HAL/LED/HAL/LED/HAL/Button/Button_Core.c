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
#include "Button_Core.h"
#define F_CPU	16000000
#include <util/delay.h>
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
void Button_Init(uint8 PIN_Number)
{
	CLR_Bit(DIO_PORTD->DDR,PIN_Number);
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
uint8 Button_GetValue(uint8 PIN_Number)
{
	uint8 Btn_Value=0,Temp=0;
	
	DIO_ReadChannel(PIN_Number,&Btn_Value);
// 	Btn_Value = GET_Bit(DIO_PORTD->PIN,PIN_Number);
	
	while(Temp==0)
	{
// 		Temp = GET_Bit(DIO_PORTD->PIN,PIN_Number);
		DIO_ReadChannel(PIN_Number,&Temp);
	}
	
	_delay_ms(10);
	
	return Btn_Value;
}

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
