/*
 * SVN_Segment.c
 *
 * Created: 2023/8/27 4:50:09 PM
 *  Author: Ahmed Adel
 */ 

#include "SVN_Segment.h"


//static const uint8 SVN_Numbers[10] = {0x00,0x01,0x02,0x03,0x04,0x05,0x05,0x06,0x06,0x07,0x08,0x09};
	
void SVN_Init(void)
{
	
	SET_Bit(DIO_PORTB->DDR,0);
	SET_Bit(DIO_PORTB->DDR,1);
	SET_Bit(DIO_PORTB->DDR,2);
	SET_Bit(DIO_PORTB->DDR,4);
	
	// Set digit PORTs of Digits as output.
	SET_Bit(DIO_PORTA->DDR,2);
	SET_Bit(DIO_PORTA->DDR,3);
	SET_Bit(DIO_PORTB->DDR,5);
	SET_Bit(DIO_PORTB->DDR,6);
}

void Select_Digit(uint8 num)
{
	DIO_WriteChannel(DIO_PORTA_PIN2,PIN_HIGH);
	DIO_WriteChannel(DIO_PORTA_PIN3,PIN_HIGH);
	DIO_WriteChannel(DIO_PORTB_PIN5,PIN_HIGH);
	DIO_WriteChannel(DIO_PORTB_PIN6,PIN_HIGH);

	switch (num)
	{
		case 1:
		DIO_WriteChannel(DIO_PORTA_PIN3,PIN_LOW);
		break;
		case 2:
		DIO_WriteChannel(DIO_PORTA_PIN2,PIN_LOW);
		break;
		case 3:
		DIO_WriteChannel(DIO_PORTB_PIN5,PIN_LOW);
		break;
		case 4:
		DIO_WriteChannel(DIO_PORTB_PIN6,PIN_LOW);
		break;
		default:
		break;
	}
}

void Display_Digit(uint8 num)
{
	//DIO_PORTB->PORT = SVN_Numbers[num];
	switch(num)
	{
		case 0:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_LOW);//0000 0000 : 0x00
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_LOW);
		break;
		case 1:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_HIGH);//0000 0001 : 0x01
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_LOW);
		break;
		case 2:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_LOW);//0000 0010 : 0x02
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_HIGH);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_LOW);
		break;
		case 3:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_HIGH);//0000 0011 : 0x03
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_HIGH);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_LOW);
		break;
		case 4:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_LOW);//0000 0100 : 0x04
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_HIGH);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_LOW);
		break;
		case 5:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_HIGH);//0000 0101 : 0x05
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_HIGH);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_LOW);
		break;
		case 6:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_LOW);//0000 0110 : 0x06
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_HIGH);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_HIGH);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_LOW);
		break;
		case 7:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_HIGH);//0000 0111 : 0x07
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_HIGH);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_HIGH);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_LOW);
		break;
		case 8:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_LOW);//0000 1000 : 0x08
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_HIGH);
		break;
		case 9:
		DIO_WriteChannel(DIO_PORTB_PIN0,PIN_HIGH);//0000 1001 : 0x09
		DIO_WriteChannel(DIO_PORTB_PIN1,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN2,PIN_LOW);
		DIO_WriteChannel(DIO_PORTB_PIN4,PIN_HIGH);
		break;
		default:
		break;
		
	}
	_delay_ms(1);
}

void Display_Number(uint16 num)
{
	if (num/10000 == 0)
	{
		//SVN_Init();
		
		Select_Digit(1);
		Display_Digit((num%100)%10);
		
		Select_Digit(2);
		Display_Digit((num%100)/10);
		
		Select_Digit(3);
		Display_Digit((num/100)%10);
		
		Select_Digit(4);
		Display_Digit(num/1000);
	}
}
