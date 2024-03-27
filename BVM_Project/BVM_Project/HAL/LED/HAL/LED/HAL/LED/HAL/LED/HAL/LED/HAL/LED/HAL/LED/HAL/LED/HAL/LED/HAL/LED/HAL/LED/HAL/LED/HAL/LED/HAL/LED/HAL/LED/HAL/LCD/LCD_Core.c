/*
 * LCD_Core.c
 *
 * Created: 2024/3/2 9:41:28 PM
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
#include "LCD_Core.h"
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
void LCD_Init(void)
{
	#if LCD_OPERATION_MODE  ==  LCD_4BIT_MODE
		/*4 BIT MODE Commands*/
		LCD_WriteCMD(0x33);
		LCD_WriteCMD(0x32);
		LCD_WriteCMD(0x28);
	
		LCD_WriteCMD(0x0C);//Cursor OFF
		LCD_WriteCMD(0x01);//Clear LCD
		LCD_WriteCMD(0x06);//Cursor Right To Left
		LCD_WriteCMD(0x02);//Return Home
		
	#elif LCD_OPERATION_MODE  ==  LCD_8BIT_MODE
		/*8 BIT MODE Commands*/
		LCD_WriteCMD(0x38);
	
		LCD_WriteCMD(0x0C);//Cursor OFF
		LCD_WriteCMD(0x01);//Clear LCD
		LCD_WriteCMD(0x06);//Cursor Right To Left
		LCD_WriteCMD(0x02);//Return Home
		
	#endif /*LCD_OPERATION_MODE  ==  LCD_4BIT_MODE*/
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
void LCD_WriteCMD(uint8 CMD)
{
	//Select CMD Register
	DIO_WriteChannel(RS_PIN,PIN_LOW);
	//Default LOW on E_PIN
	DIO_WriteChannel(E_PIN,PIN_LOW);
	
	DIO_WriteChannel(D4_PIN, GET_Bit(CMD,4));
	DIO_WriteChannel(D5_PIN, GET_Bit(CMD,5));
	DIO_WriteChannel(D6_PIN, GET_Bit(CMD,6));
	DIO_WriteChannel(D7_PIN, GET_Bit(CMD,7));
	
	/*PORTB |= ( ((CMD >> 4) & 1) << 0);  //CMD => 0000 0000 
	PORTB |= ( ((CMD >> 5) & 1) << 1);
	PORTB |= ( ((CMD >> 6) & 1) << 2);
	PORTB |= ( ((CMD >> 7) & 1) << 4);*/
	
	
	DIO_WriteChannel(E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN,PIN_LOW);
	
	DIO_WriteChannel(D4_PIN, GET_Bit(CMD,0));
	DIO_WriteChannel(D5_PIN, GET_Bit(CMD,1));
	DIO_WriteChannel(D6_PIN, GET_Bit(CMD,2));
	DIO_WriteChannel(D7_PIN, GET_Bit(CMD,3));
	
	/*PORTB |= ( ((CMD >> 0) & 1) << 0);
	PORTB |= ( ((CMD >> 1) & 1) << 1);
	PORTB |= ( ((CMD >> 2) & 1) << 2);
	PORTB |= ( ((CMD >> 3) & 1) << 4);*/
	
	DIO_WriteChannel(E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN,PIN_LOW);
	
	_delay_ms(5);
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
void LCD_WriteDATA(uint8 DATA)
{
	//Select DATA Register
	DIO_WriteChannel(RS_PIN,PIN_HIGH);
	//Default LOW on E_PIN
	DIO_WriteChannel(E_PIN,PIN_LOW);
	
	DIO_WriteChannel(D4_PIN, GET_Bit(DATA,4));
	DIO_WriteChannel(D5_PIN, GET_Bit(DATA,5));
	DIO_WriteChannel(D6_PIN, GET_Bit(DATA,6));
	DIO_WriteChannel(D7_PIN, GET_Bit(DATA,7));
	
	/*PORTB |= ( ((DATA >> 4) & 1) << 0);
	PORTB |= ( ((DATA >> 5) & 1) << 1);
	PORTB |= ( ((DATA >> 6) & 1) << 2);
	PORTB |= ( ((DATA >> 7) & 1) << 4);*/
	
	
	DIO_WriteChannel(E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN,PIN_LOW);
	
	DIO_WriteChannel(D4_PIN, GET_Bit(DATA,0));
	DIO_WriteChannel(D5_PIN, GET_Bit(DATA,1));
	DIO_WriteChannel(D6_PIN, GET_Bit(DATA,2));
	DIO_WriteChannel(D7_PIN, GET_Bit(DATA,3));
	
	/*PORTB |= ( ((DATA >> 0) & 1) << 0);
	PORTB |= ( ((DATA >> 1) & 1) << 1);
	PORTB |= ( ((DATA >> 2) & 1) << 2);
	PORTB |= ( ((DATA >> 3) & 1) << 4);*/
	
	DIO_WriteChannel(E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN,PIN_LOW);
	
	_delay_ms(5);
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
void LCD_WriteString(uint8* Str)
{
	uint8 cnt = 0;
	
	while(Str[cnt] != '\0')
	{
		LCD_WriteDATA(Str[cnt]);
		cnt++;
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
/*void LCD_WriteInt(sint32 Num)
{
	uint8 Result[8];
	uint8 index = 0;
	//uint8 NonZero = 1;
	
// 	if(Num == 0)
// 	{
// 		LCD_WriteDATA('0');
// 		NonZero = 0;
// 	}
// 	else if(Num < 0)
// 	{
// 		LCD_WriteDATA('-');
// 		Num *= -1;
// 	}
	
	while (Num)
	{
		Result[index++] = ((Num % 10) + '0');// From uint8 to char
		Num /= 10;
	}
	
// 	if(!NonZero)
// 	{
		for (int i = 0; i <= index; i++)
		{
			LCD_WriteDATA(Result[index - i]);
		}
	//}
}*/
void LCD_WriteInt(sint32 Num){	uint32 temp = 1;		if(Num == 0)	{		LCD_WriteDATA('0');	}	else if(Num < 0)	{		LCD_WriteDATA('-');		Num *= -1;	}		/*number reverse*/	while(Num > 0)	{		temp = (temp * 10) + (Num % 10);		Num /= 10;	}		/*digits writing*/	while(temp > 1)	{		LCD_WriteDATA((temp%10) + 48);		temp /= 10;	}	}
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
void LCD_GoTo(uint8 ROW,uint8 COL)
{
	uint8 Pos[4] = {0x80, 0xC0, 0x94, 0xD4};
	
	LCD_WriteCMD(Pos[ROW] + COL);
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
void LCD_Clear(void)
{
	LCD_WriteCMD(0x01);//Clear LCD
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
void LCD_SetCustomChar(void)
{
	uint8 CustomChar_ROW_LOC = 0;
	uint8 CustomChar_COL_LOC = 0;
	
	//CGRAM
	LCD_WriteCMD(0x40);
	
	for (CustomChar_ROW_LOC = 0; CustomChar_ROW_LOC<8 ; CustomChar_ROW_LOC++)
	{
		for (CustomChar_COL_LOC = 0; CustomChar_COL_LOC < 8; CustomChar_COL_LOC++)
		{
			LCD_WriteDATA(LCD_CUSTOM_CHARACTERS_g[CustomChar_ROW_LOC][CustomChar_COL_LOC]);
		}
	}
}

void LCD_WriteCustomChar(uint8 ROW,uint8 COL,uint8 Special_Char)
{
	LCD_SetCustomChar();
	LCD_GoTo(ROW,COL);
	LCD_WriteDATA(Special_Char);
}
/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
