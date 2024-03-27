/*
 * ADC_Core.c
 *
 * Created: 2024/3/22 9:19:23 PM
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
#include "ADC_Cfg.h"
#include "ADC_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32	ADC_VinValue_mv;
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
void ADC_Init(void)
{
	#if		(ADC_VOLTAGE_REFERENCE == ADC_VREF_AVCC)
	
	SET_Bit(ADMUX, 6);
	CLR_Bit(ADMUX, 7);
	
	#elif	(ADC_VOLTAGE_REFERENCE == ADC_VREF_AREF)
	
	CLR_Bit(ADMUX, 6);
	CLR_Bit(ADMUX, 7);
	
	#elif	(ADC_VOLTAGE_REFERENCE == ADC_VREF_INTERNAL)
	
	SET_Bit(ADMUX, 6);
	
	SET_Bit(ADMUX, 7);
	
	#endif /* ADC_VOLTAGE_REFERENCE */
	
	#if		(ADC_CHANNEL == ADC_CHANNEL_0)
	
	ADMUX |= 0x00;
	
	#elif	(ADC_CHANNEL == ADC_CHANNEL_1)
	
	ADMUX |= 0x01;
	
	#elif	(ADC_CHANNEL == ADC_CHANNEL_2)
	
	ADMUX |= 0x02;
	
	#elif	(ADC_CHANNEL == ADC_CHANNEL_3)
	
	ADMUX |= 0x03;
	
	#elif	(ADC_CHANNEL == ADC_CHANNEL_4)
	
	ADMUX |= 0x04;
	
	#elif	(ADC_CHANNEL == ADC_CHANNEL_5)
	
	ADMUX |= 0x05;
	
	#elif	(ADC_CHANNEL == ADC_CHANNEL_6)
	
	ADMUX |= 0x06;
	
	#elif	(ADC_CHANNEL == ADC_CHANNEL_7)
	
	ADMUX |= 0x07;
	
	#endif /* ADC_CHANNEL */
	
	#if		(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_SINGLE)
	
	CLR_Bit(ADCSRA, 5);
	
	#elif	(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_FREE_RUNNING)
	
	SET_Bit(ADCSRA, 5);
	SFIOR |= (0x00 << 5);
	
	#elif	(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_ANALOG_COMPARATOR)
	
	SET_Bit(ADCSRA, 5);
	SFIOR |= (0x01 << 5);
	
	#elif	(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_EXTERNAL_INTERRUPT_0)
	
	SET_Bit(ADCSRA, 5);
	SFIOR |= (0x02 << 5);
	
	#elif	(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER0_COMPARE_MATCH)
	
	SET_Bit(ADCSRA, 5);
	SFIOR |= (0x03 << 5);
	
	#elif	(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER0_OVERFLOW)
	
	SET_Bit(ADCSRA, 5);
	SFIOR |= (0x04 << 5);
	
	#elif	(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER1_COMPARE_MATCH)
	
	SET_Bit(ADCSRA, 5);
	SFIOR |= (0x05 << 5);
	
	#elif	(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER1_OVERFLOW)
	
	SET_Bit(ADCSRA, 5);
	SFIOR |= (0x06 << 5);
	
	#elif	(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER1_CAPTURE_EVENT)
	
	SET_Bit(ADCSRA, 5);
	SFIOR |= (0x07 << 5);
	
	#endif /* ADC_CONVERSION_TRIGGER */
	
	#if		(ADC_PRESCALER == ADC_PRESCALER_2)
	
	ADCSRA |= 0x01;
	
	#elif	(ADC_PRESCALER == ADC_PRESCALER_4)
	
	ADCSRA |= 0x02;
	
	#elif	(ADC_PRESCALER == ADC_PRESCALER_8)
	
	ADCSRA |= 0x03;
	
	#elif	(ADC_PRESCALER == ADC_PRESCALER_16)
	
	ADCSRA |= 0x04;
	
	#elif	(ADC_PRESCALER == ADC_PRESCALER_32)
	
	ADCSRA |= 0x05;
	
	#elif	(ADC_PRESCALER == ADC_PRESCALER_64)
	
	ADCSRA |= 0x06;
	
	#elif	(ADC_PRESCALER == ADC_PRESCALER_128)
	
	ADCSRA |= 0x07;
	
	#endif /* ADC_PRESCALER */
	
	#if		(ADC_INTERRUPT_STATUS == ADC_INTERRUP_ENABLE)
	
	SET_Bit(ADCSRA, 3);
	
	#elif	(ADC_INTERRUPT_STATUS == ADC_INTERRUP_DISABLE)
	
	CLR_Bit(ADCSRA, 3);
	
	#endif /* ADC_INTERRUPT_STATUS */
	
	#if		(ADC_REG_ADJUST == ADC_RIGHT_ADJUST)
	
	CLR_Bit(ADMUX, 5);
	
	#elif	(ADC_REG_ADJUST == ADC_LEFT_ADJUST)
	
	SET_Bit(ADMUX, 5);
	
	#endif /* ADC_REG_ADJUST */
	
	/* ENABLE ADC */
	SET_Bit(ADCSRA, 7);
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
void ADC_Read(void)
{
	uint32 ADC_DigitalValue;
	
	/* Start Conversion	*/
	SET_Bit(ADCSRA, 6);
	
	#if	(ADC_INTERRUPT_STATUS == ADC_INTERRUP_DISABLE) // Polling "Blocking"
	
	while(GET_Bit(ADCSRA, 4) == 0U ); 
	// For Polling "Busy Wait" => While(Counter++ < 1000 && GET_Bit(ADCSRA, 4) == 0U);
	
	/* End of Conversion */
	
		#if		(ADC_REG_ADJUST == ADC_RIGHT_ADJUST)
		
			ADC_DigitalValue = ADC_INPUT_16BIT_ACCESS;
		
		#elif	(ADC_REG_ADJUST == ADC_LEFT_ADJUST)
		
			ADC_DigitalValue = (ADCH << 2) | (ADCL >> 6);
		
		#endif /* ADC_REG_ADJUST */
	
	ADC_VinValue_mv = (ADC_DigitalValue * ADC_VREF_VALUE) / ADC_RESOLUTION;
	
	#endif /* ADC_INTERRUPT_STATUS */
}

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
