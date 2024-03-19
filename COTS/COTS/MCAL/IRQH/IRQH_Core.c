/*
 * IRQH_Core.c
 *
 * Created: 2024/3/17 12:00:38 AM
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
#include "IRQH_Core.h"

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
void IRQH_SetGlobalINT(uint8 GlobalINTStatus)
{
	switch(GlobalINTStatus)
	{
		case INT_ENABLE:
			SET_Bit(SREG, 7);
		break;
		
		case INT_DISABLE:
			CLR_Bit(SREG, 7);
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
void IRQH_SetExternalINT(void)
{
	#if (EXT_INT_0 == INT_ENABLE)
	
		//Enable EXT_INT0
		SET_Bit(GISR, 6);
		
		#if (EXT_INT0_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)
			CLR_Bit(MCUCR, 0);
			CLR_Bit(MCUCR, 1);
		#elif (EXT_INT0_TRIGGER == EXT_INT_TRIGGER_RISING_EDGE)
			SET_Bit(MCUCR, 0);
			CLR_Bit(MCUCR, 1);
		#elif (EXT_INT0_TRIGGER == EXT_INT_TRIGGER_LOW_LEVEL)
			CLR_Bit(MCUCR, 0);
			SET_Bit(MCUCR, 1);
		#elif (EXT_INT0_TRIGGER == EXT_INT_TRIGGER_ANY_LOGICAL)
			SET_Bit(MCUCR, 0);
			SET_Bit(MCUCR, 1);
		#endif /*(EXT_INT0_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)*/
		
	#endif /*if (EXT_INT_0 == INT_ENABLE)*/
	
	#if (EXT_INT_1 == INT_ENABLE)
	
		//Enable EXT_INT1
		SET_Bit(GISR, 7);
	
		#if (EXT_INT1_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)
			CLR_Bit(MCUCR, 2);
			CLR_Bit(MCUCR, 3);
		#elif (EXT_INT1_TRIGGER == EXT_INT_TRIGGER_RISING_EDGE)
			SET_Bit(MCUCR, 2);
			CLR_Bit(MCUCR, 3);		
		#elif (EXT_INT1_TRIGGER == EXT_INT_TRIGGER_LOW_LEVEL)
			CLR_Bit(MCUCR, 2);
			SET_Bit(MCUCR, 3);		
		#elif (EXT_INT1_TRIGGER == EXT_INT_TRIGGER_ANY_LOGICAL)
			SET_Bit(MCUCR, 2);
			SET_Bit(MCUCR, 3);		
		#endif /*(EXT_INT1_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)*/
		
	#endif /*if (EXT_INT_1 == INT_ENABLE)*/
	
	#if (EXT_INT_2 == INT_ENABLE)
	
		//Enable EXT_INT2
		SET_Bit(GISR, 5);
		
		#if (EXT_INT2_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)
			CLR_Bit(MCUSCR, 6);
		#elif (EXT_INT2_TRIGGER == EXT_INT_TRIGGER_RISING_EDGE)
			SET_Bit(MCUSCR, 6);
		#endif /*(EXT_INT2_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)*/
		
	#endif /*if (EXT_INT_2 == INT_ENABLE)*/
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
void IRQH_SetCallBacks(uint8 VectorTableIndex, void(*ptr)(void));

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
