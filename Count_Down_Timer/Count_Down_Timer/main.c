/*
 * Count_Down_Timer.c
 *
 * Created: 2024/2/15 3:09:03 AM
 * Author : Ahmed Adel
 */ 

#include "SVN_Segment.h"
#include "LED_Core.h"
#include "Button_Core.h"
#include "Buzzer.h"

#define F_CPU	16000000
#include <util/delay.h>

#define Start_Btn	Button_0
#define Min_Btn		Button_1
#define Sec_Btn		Button_2
#define Reset_Btn	Button_3

int main(void)
{
	uint8 Start=0,Min=0,Sec=0,Reset=0,Btn=0;
	
	SVN_Init();
	Buzzer_Init();
	
	Button_Init(Button_0);
	Button_Init(Button_1);
	Button_Init(Button_2);
	Button_Init(Button_3);
	
	LED_Init(RED);
	LED_Init(GREEN);
	LED_Init(BLUE);
	
	LED_ON(RED);//Initial State "Setting Time"
	
    /* Replace with your application code */
    while (1) 
    {		
		Display_Number((Min*100)+Sec);
		
		Btn = Button_GetValue(Button_0);
		if(Btn == 0)
		{
			Start = 1;
			LED_OFF(RED);
			LED_ON(GREEN);
		}
		Btn = Button_GetValue(Button_1);
		if(Btn == 0)
		{
			if(Min<60)
				Min++;
		}
		Btn = Button_GetValue(Button_2);
		if(Btn == 0)
		{
			if(Sec<60)
				Sec++;	
		}
		Reset = Button_GetValue(Button_3);
		if(Reset == 0)
		{
			Min = Sec = Start = 0;
			LED_ON(RED);
			LED_OFF(GREEN);
		}
		while(Start)
		{

			while(Sec>0)
			{
				for (int i=0;i<100;i++)
				{
					Display_Number((Min*100)+Sec);
					_delay_ms(10);
				}
				Sec--;
				/*Buzzer_ON();
				_delay_ms(50);
				Buzzer_OFF();*/
			}
			if (Min>0)
			{
				Min--;
				Sec = 59;
			}
			else if(Min == 0 && Sec == 0)
			{
				//Display_Number((Min*100)+Sec);
				Start = 0;
				LED_OFF(GREEN);
				for (int i=0;i<5;i++)
				{
					LED_Toggle(BLUE);
					BUZZ();
					_delay_ms(30);
				}
				LED_OFF(BLUE);
				LED_ON(RED);
				break;
			}
		}
		
    }
}

