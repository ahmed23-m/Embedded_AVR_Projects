/*
 * Button_Core.h
 *
 * Created: 2024/2/10 10:26:18 PM
 *  Author: dasah
 */ 

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef BUTTON_CORE_H_
#define BUTTON_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"
#include "BIT_MATH.h"
#include "Registers.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Button_0	((uint8)(7U))
#define Button_1	((uint8)(6U))
#define Button_2	((uint8)(5U))
#define Button_3	((uint8)(3U))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Button_Init(uint8 PIN_Number);
uint8 Button_GetValue(uint8 PIN_Number);
 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/




#endif /* BUTTON_CORE_H_ */