/*
 * COTS.c
 *
 * Created: 2024/2/9 9:30:06 PM
 * Author : Ahmed Adel
 */ 

#include "LED_Core.h"
#include "Button_Core.h"
#include "PORT_Core.h"

#define F_CPU	16000000U
#include <util/delay.h>



int main(void)
{
	PORT_Init();
	LED_ON(RED);
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		
		
    }
}

