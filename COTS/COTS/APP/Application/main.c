/*
 * COTS.c
 *
 * Created: 2024/2/9 9:30:06 PM
 * Author : Ahmed Adel
 */ 

#include "LED_Core.h"
#include "Button_Core.h"
#include "PORT_Core.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#include "IRQH_Core.h"
#include "ADC_Core.h"

#define F_CPU	16000000U
#include <avr/interrupt.h>
#include <util/delay.h>


/****************************/
void WrapperFunction()
{
	if (ADC_VinValue_mv)
	{
		LCD_GoTo(0,0);
		LCD_WriteInt(ADC_VinValue_mv);
		ADC_VinValue_mv = 0;
	}
	LED_Toggle(RED);
}

int main(void)
{
	PORT_Init();
	IRQH_SetGlobalINT(INT_ENABLE);
	IRQH_SetCallBacks(ADC_Conversion_Complete_VECTOR_INDEX,WrapperFunction);
	ADC_Init();
	LCD_Init();
	ADC_Read();
	LED_Init(RED);
	
    while (1) 
    {
		
// 		if (ADC_VinValue_mv)
// 		{
// 			LCD_GoTo(0,0);
// 			LCD_WriteInt(ADC_VinValue_mv);
// 			ADC_VinValue_mv = 0;
// 		}
    }
}
