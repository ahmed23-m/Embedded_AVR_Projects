/*
 * LCD_Cfg.h
 *
 * Created: 2024/3/2 9:42:02 PM
 *  Author: Ahmed Adel
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
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define LCD_4BIT_MODE		(4U)
#define LCD_8BIT_MODE		(8U)

#define LCD_OPERATION_MODE	LCD_4BIT_MODE

#define RS_PIN				DIO_PORTA_PIN3
#define E_PIN				DIO_PORTA_PIN2

#define D4_PIN				DIO_PORTB_PIN0
#define D5_PIN				DIO_PORTB_PIN1
#define D6_PIN				DIO_PORTB_PIN2
#define D7_PIN				DIO_PORTB_PIN4

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern const uint8 LCD_CUSTOM_CHARACTERS_g[8][8];

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/




#endif /* LCD_CFG_H_ */