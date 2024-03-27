/*
 * ADC_Core.h
 *
 * Created: 2024/3/22 9:19:04 PM
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
#ifndef ADC_CORE_H_
#define ADC_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Registers.h"
#include "BIT_MATH.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ADC_VREF_AVCC			(0U)
#define ADC_VREF_AREF			(1U)
#define ADC_VREF_INTERNAL		(2U)

#define ADC_CHANNEL_0			(0U)
#define ADC_CHANNEL_1			(1U)
#define ADC_CHANNEL_2			(2U)
#define ADC_CHANNEL_3			(3U)
#define ADC_CHANNEL_4			(4U)
#define ADC_CHANNEL_5			(5U)
#define ADC_CHANNEL_6			(6U)
#define ADC_CHANNEL_7			(7U)

#define ADC_PRESCALER_2			(1U)
#define ADC_PRESCALER_4			(2U)
#define ADC_PRESCALER_8			(3U)
#define ADC_PRESCALER_16		(4U)
#define ADC_PRESCALER_32		(5U)
#define ADC_PRESCALER_64		(6U)
#define ADC_PRESCALER_128		(7U)

#define ADC_CONVERSION_SINGLE					(0U)
#define ADC_CONVERSION_FREE_RUNNING				(1U)
#define ADC_CONVERSION_ANALOG_COMPARATOR		(2U)
#define ADC_CONVERSION_EXTERNAL_INTERRUPT_0		(3U)
#define ADC_CONVERSION_TIMER0_COMPARE_MATCH		(4U)
#define ADC_CONVERSION_TIMER0_OVERFLOW			(5U)
#define ADC_CONVERSION_TIMER1_COMPARE_MATCH		(6U)
#define ADC_CONVERSION_TIMER1_OVERFLOW			(7U)
#define ADC_CONVERSION_TIMER1_CAPTURE_EVENT		(8U)

#define ADC_INTERRUP_ENABLE		(0U)
#define ADC_INTERRUP_DISABLE	(1U)

#define ADC_LEFT_ADJUST			(0U)
#define ADC_RIGHT_ADJUST		(1U)

#define ADC_RESOLUTION			(1024U) // 10 BIT Resolution
#define ADC_VREF_VALUE			(5000U) // mv

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern uint32	ADC_VinValue_mv;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void ADC_Init(void);
 
void ADC_Read(void);

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/





#endif /* ADC_CORE_H_ */