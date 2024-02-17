/*
 * PORT_Lcfg.h
 *
 * Created: 2024/2/17 10:49:02 PM
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
#ifndef PORT_LCFG_H_
#define PORT_LCFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DEFINED_PINS			4

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum
{
	PIN_INPUT = 0,
	PIN_OUTPUT= 1
}PIN_DIRECTION_TYPE;
 
typedef enum{	PORTA_PIN_0 = 0,	PORTA_PIN_1 = 1,	PORTA_PIN_2 = 2,	PORTA_PIN_3 = 3,	PORTA_PIN_4 = 4,	PORTA_PIN_5 = 5,	PORTA_PIN_6 = 6,	PORTA_PIN_7 = 7,	PORTB_PIN_0 = 8,	PORTB_PIN_1 = 9,	PORTB_PIN_2 = 10,	PORTB_PIN_3 = 11,	PORTB_PIN_4 = 12,	PORTB_PIN_5 = 13,	PORTB_PIN_6 = 14,	PORTB_PIN_7 = 15,	PORTC_PIN_0 = 16,	PORTC_PIN_1 = 17,	PORTC_PIN_2 = 18,	PORTC_PIN_3 = 19,	PORTC_PIN_4 = 20,	PORTC_PIN_5 = 21,	PORTC_PIN_6 = 22,	PORTC_PIN_7 = 23,	PORTD_PIN_0 = 24,	PORTD_PIN_1 = 25,	PORTD_PIN_2 = 26,	PORTD_PIN_3 = 27,	PORTD_PIN_4 = 28,	PORTD_PIN_5 = 29,	PORTD_PIN_6 = 30,	PORTD_PIN_7 = 31}PIN_ORDER_Type;

typedef struct
{
	PIN_ORDER_Type	PIN_Order;
	PIN_DIRECTION_TYPE	PIN_Dir;
}PIN_PARAMETERS_Type;

extern PIN_PARAMETERS_Type	PORT_Init_Pins[DEFINED_PINS];
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/





#endif /* PORT_LCFG_H_ */