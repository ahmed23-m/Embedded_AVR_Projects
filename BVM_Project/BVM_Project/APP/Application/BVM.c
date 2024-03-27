/*
 * BVM.c
 *
 * Created: 2024/3/25 9:02:15 PM
 *  Author: dasah
 */ 
#include "BVM.h"


uint32 Voltage_Value = 0;
uint8 R1 = 220, R2=220; //voltage divider => [ /2 ] => vin = vout * R2/(R1+R2)

void WrapperFunction()
{
	if (ADC_VinValue_mv)
	{
		Voltage_Value = (ADC_VinValue_mv * (R1 + R2)) / R2;
		ADC_VinValue_mv = 0;
	}
	else
	{
		Voltage_Value = 0;
	}
}

void BVM_Init()
{
	LED_Init(RED);
	LED_Init(YELLOW);
	LED_Init(GREEN);
	LED_Init(BLUE);
	
	IRQH_SetGlobalINT(INT_ENABLE);
	IRQH_SetCallBacks(ADC_Conversion_Complete_VECTOR_INDEX,WrapperFunction);
	ADC_Init();
	ADC_Read();
}

uint32 GetBVM_Value()
{
	return Voltage_Value;
}

uint8 GetBattery_Life(uint8 BATCAP)
{
	uint8 BAT_Life = (uint8) ( ((float)GetBVM_Value()/(BATCAP*1000)) * 100 );
	if(BAT_Life > 95)
	{
		LED_OFF(RED);
		LED_OFF(YELLOW);
		LED_OFF(GREEN);
		LED_ON(BLUE);
	}
	else if(BAT_Life > 90)
	{
		LED_OFF(RED);
		LED_OFF(YELLOW);
		LED_OFF(BLUE);
		LED_ON(GREEN);
	}
	else if(BAT_Life > 50)
	{
		LED_OFF(RED);
		LED_OFF(GREEN);
		LED_OFF(BLUE);
		LED_ON(YELLOW);
	}
	else
	{
		LED_OFF(YELLOW);
		LED_OFF(GREEN);
		LED_OFF(BLUE);
		LED_ON(RED);
	}
	return BAT_Life;
}