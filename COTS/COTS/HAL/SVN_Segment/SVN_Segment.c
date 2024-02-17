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
	SET_Bit(DIO_PORTA->PORT,2);
	SET_Bit(DIO_PORTA->PORT,3);
	SET_Bit(DIO_PORTB->PORT,5);
	SET_Bit(DIO_PORTB->PORT,6);

	switch (num)
	{
		case 1:
		CLR_Bit(DIO_PORTA->PORT,3);
		break;
		case 2:
		CLR_Bit(DIO_PORTA->PORT,2);
		break;
		case 3:
		CLR_Bit(DIO_PORTB->PORT,5);
		break;
		case 4:
		CLR_Bit(DIO_PORTB->PORT,6);
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
		CLR_Bit(DIO_PORTB->PORT,0);//0000 0000 : 0x00
		CLR_Bit(DIO_PORTB->PORT,1);
		CLR_Bit(DIO_PORTB->PORT,2);
		CLR_Bit(DIO_PORTB->PORT,4);
		break;
		case 1:
		SET_Bit(DIO_PORTB->PORT,0);//0000 0001 : 0x01
		CLR_Bit(DIO_PORTB->PORT,1);
		CLR_Bit(DIO_PORTB->PORT,2);
		CLR_Bit(DIO_PORTB->PORT,4);
		break;
		case 2:
		CLR_Bit(DIO_PORTB->PORT,0);//0000 0010 : 0x02
		SET_Bit(DIO_PORTB->PORT,1);
		CLR_Bit(DIO_PORTB->PORT,2);
		CLR_Bit(DIO_PORTB->PORT,4);
		break;
		case 3:
		SET_Bit(DIO_PORTB->PORT,0);//0000 0011 : 0x03
		SET_Bit(DIO_PORTB->PORT,1);
		CLR_Bit(DIO_PORTB->PORT,2);
		CLR_Bit(DIO_PORTB->PORT,4);
		break;
		case 4:
		CLR_Bit(DIO_PORTB->PORT,0);//0000 0100 : 0x04
		CLR_Bit(DIO_PORTB->PORT,1);
		SET_Bit(DIO_PORTB->PORT,2);
		CLR_Bit(DIO_PORTB->PORT,4);
		break;
		case 5:
		SET_Bit(DIO_PORTB->PORT,0);//0000 0101 : 0x05
		CLR_Bit(DIO_PORTB->PORT,1);
		SET_Bit(DIO_PORTB->PORT,2);
		CLR_Bit(DIO_PORTB->PORT,4);
		break;
		case 6:
		CLR_Bit(DIO_PORTB->PORT,0);//0000 0110 : 0x06
		SET_Bit(DIO_PORTB->PORT,1);
		SET_Bit(DIO_PORTB->PORT,2);
		CLR_Bit(DIO_PORTB->PORT,4);
		break;
		case 7:
		SET_Bit(DIO_PORTB->PORT,0);//0000 0111 : 0x07
		SET_Bit(DIO_PORTB->PORT,1);
		SET_Bit(DIO_PORTB->PORT,2);
		CLR_Bit(DIO_PORTB->PORT,4);
		break;
		case 8:
		CLR_Bit(DIO_PORTB->PORT,0);//0000 1000 : 0x08
		CLR_Bit(DIO_PORTB->PORT,1);
		CLR_Bit(DIO_PORTB->PORT,2);
		SET_Bit(DIO_PORTB->PORT,4);
		break;
		case 9:
		SET_Bit(DIO_PORTB->PORT,0);//0000 1001 : 0x09
		CLR_Bit(DIO_PORTB->PORT,1);
		CLR_Bit(DIO_PORTB->PORT,2);
		SET_Bit(DIO_PORTB->PORT,4);
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
