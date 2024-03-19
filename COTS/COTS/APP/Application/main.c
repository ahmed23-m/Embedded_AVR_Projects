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

#define F_CPU	16000000U
#include <avr/interrupt.h>
#include <util/delay.h>



int main(void)
{
	PORT_Init();
	IRQH_SetGlobalINT(INT_ENABLE);
	IRQH_SetExternalINT();
	//LCD_Init();
	KeyPad_Init();
	LED_Init(RED);
	LED_Init(BLUE);
	uint8 Button_Value = 1;
	
    while (1) 
    {
		/*Button_Value = KeyPad_GetValue();
		if (!Button_Value)
		{
			LED_Toggle(RED);
			_delay_ms(1000);
			LED_Toggle(BLUE);
		}*/
    }
}

ISR(INT1_vect)
{
	LED_Toggle(RED);
}