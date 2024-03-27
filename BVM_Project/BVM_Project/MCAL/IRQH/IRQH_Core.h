/*
 * IRQH.h
 *
 * Created: 2024/3/17 12:00:12 AM
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
#ifndef IRQH_H_
#define IRQH_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IRQH_Cfg.h"
#include "STD.h"
#include "Registers.h"
#include "BIT_MATH.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INT_ENABLE						(1u)
#define INT_DISABLE						(0u)

#define EXT_INT_TRIGGER_FALLING_EDGE	(0u)
#define EXT_INT_TRIGGER_RISING_EDGE		(1u)
#define EXT_INT_TRIGGER_LOW_LEVEL		(2u)
#define EXT_INT_TRIGGER_ANY_LOGICAL		(3u)


#define  VECTOR_ARRAY_SIZE								(20U)

#define  External_Interrupt_Request_0_VECTOR_INDEX      (0U)
#define  External_Interrupt_Request_1_VECTOR_INDEX      (1U)
#define  External_Interrupt_Request_2_VECTOR_INDEX		(2U)
#define  Timer_Counter2_Compare_Match_VECTOR_INDEX		(3U)
#define  Timer_Counter2_Overflow_VECTOR_INDEX			(4U)
#define  Timer_Counter1_Capture_Event_VECTOR_INDEX		(5U)
#define  Timer_Counter1_Compare_Match_A_VECTOR_INDEX	(6U)
#define  Timer_Counter1_Compare_Match_B_VECTOR_INDEX	(7U)
#define  Timer_Counter1_Overflow_VECTOR_INDEX			(8U)
#define  Timer_Counter0_Compare_Match_VECTOR_INDEX		(9U)
#define  Timer_Counter0_Overflow_VECTOR_INDEX			(10U)
#define  Serial_Transfer_Complete_VECTOR_INDEX			(11U)
#define  USART_Rx_Complete_VECTOR_INDEX					(12U)
#define  USART_Data_Register_Empty_VECTOR_INDEX			(13U)
#define  USART_Tx_Complete_VECTOR_INDEX					(14U)
#define  ADC_Conversion_Complete_VECTOR_INDEX			(15U)
#define  EE_RDY_EEPROM_Ready_VECTOR_INDEX				(16U)
#define  ANA_COMP_Analog_Comparator_VECTOR_INDEX		(17U)
#define  Two_wire_Serial_Interface_VECTOR_INDEX			(18U)
#define  Store_Program_Memory_Ready_VECTOR_INDEX		(19U)

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
void IRQH_SetGlobalINT(uint8 GlobalINTStatus);

void IRQH_SetExternalINT(void);

void IRQH_SetCallBacks(uint8 VectorTableIndex, void(*ptr)(void));

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/

#endif /* IRQH_H_ */