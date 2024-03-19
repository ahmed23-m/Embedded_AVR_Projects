/*
 * KeyPad_Core.c
 *
 * Created: 3/1/2024 11:19:03 PM
 *  Author: Ahmed Adel
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
#include "KeyPad_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define F_CPU 16000000U
#include <util/delay.h>

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
void KeyPad_Init(void)
{
	DIO_WriteChannel(KEYPAD_ROW_0 , PIN_HIGH);
	DIO_WriteChannel(KEYPAD_ROW_1 , PIN_HIGH);
	DIO_WriteChannel(KEYPAD_ROW_2 , PIN_HIGH);
	DIO_WriteChannel(KEYPAD_ROW_3 , PIN_HIGH);
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
uint8 KeyPad_GetValue(void)
{
	uint8 LOC_Column = 0, LOC_Row = 0, Button_Value = 0, Temp = 2;

	for(LOC_Row = ROW_INIT ; LOC_Row >= ROW_FINAL ; LOC_Row--)
	{
		DIO_WriteChannel(LOC_Row , PIN_LOW);
		
			for(LOC_Column = COL_INIT ; LOC_Column >= COL_FINAL  ;LOC_Column--)//Decrement Because of pins [7 -> 2]
			{
				if(LOC_Column == 4)
				{
					continue;
				}
				
				DIO_ReadChannel(LOC_Column , &Temp);
				
				if(Temp == KEYPAD_PRESSED)
				{
					Button_Value = KEYPAD_VALUES[ROW_INIT - LOC_Row][COL_INIT - LOC_Column];
					
					while(Temp == KEYPAD_PRESSED)// Prevent Spam
					{
						DIO_ReadChannel(LOC_Column , &Temp);
					}
					_delay_ms(10);// Solving Bouncing Problem ( DeBouncing )
				}
			}
			
		DIO_WriteChannel(LOC_Row , PIN_HIGH);
		
	}
	return Button_Value;
}


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
