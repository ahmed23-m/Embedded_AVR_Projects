/*
 * BVM_Project.c
 *
 * Created: 2024/3/25 8:40:33 PM
 * Author : dasah
 */ 

#include "PORT_Core.h"
#include "LCD_Core.h"
#include "Button_Core.h"
#include "BVM.h"


int main(void)
{
	PORT_Init();
	LCD_Init();
// 	Button_Init(Button_0);
// 	Button_Init(Button_1);
	//BVM_Init();
	
	uint8 Battery_CAP = 9;
// 	LCD_WriteString("Select Battery CAP:");
// 	LCD_GoTo(2,0);
// 	LCD_WriteString("1] 9v 2] 5v");
// 	while(Battery_CAP == 0)
// 	{
// 		if(Button_GetValue(Button_0))
// 		{
// 			Battery_CAP = 9;
// 		}
// 		else if(Button_GetValue(Button_1))
// 		{
// 			Battery_CAP = 5;
// 		}
// 	}	
	
 	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("Voltage = ");
	LCD_GoTo(2,0);
	LCD_WriteString("Battery Life: %");
	
    /* Replace with your application code */
    while (1) 
    {
		LCD_GoTo(0,0);
		LCD_WriteString("Voltage = ");
		LCD_GoTo(2,0);
		LCD_WriteString("Battery Life: %");
// 		LCD_GoTo(0,11);
// 		LCD_WriteInt(GetBVM_Value());
// 		LCD_WriteString(" mv");
// 		LCD_GoTo(2,16);
// 		LCD_WriteInt(GetBattery_Life(Battery_CAP));
// 		
// 		_delay_ms(1000);
// 		LCD_GoTo(0,11);
// 		LCD_WriteString("       ");
// 		LCD_GoTo(2,16);
// 		LCD_WriteString("       ");
    }
}

