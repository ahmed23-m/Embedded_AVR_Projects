/*
 * LCD_Core.h
 *
 * Created: 2024/3/2 9:41:39 PM
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
#ifndef LCD_CORE_H_
#define LCD_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "LCD_Cfg.h"
#include "DIO_Core.h"
#define F_CPU 16000000
#include <util/delay.h>
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


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
void LCD_Init(void);

void LCD_WriteCMD(uint8 CMD); 

void LCD_WriteDATA(uint8 DATA); 

void LCD_WriteString(uint8* Str);

void LCD_WriteInt(sint32 Num);

void LCD_GoTo(uint8 ROW,uint8 COL);

void LCD_Clear(void);

void LCD_SetCustomChar(void);

void LCD_WriteCustomChar(uint8 ROW,uint8 COL,uint8 Special_Char);

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/





#endif /* LCD_CORE_H_ */