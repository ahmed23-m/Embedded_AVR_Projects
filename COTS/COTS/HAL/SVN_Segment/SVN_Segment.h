/*
 * SVN_Segment.h
 *
 * Created: 2023/8/27 4:50:22 PM
 *  Author: Ahmed Adel
 */ 


#ifndef SVN_SEGMENT_H_
#define SVN_SEGMENT_H_


#include "STD.h"
#include "BIT_MATH.h"
#include "Registers.h"

#define F_CPU 16000000
#include <util/delay.h>


void SVN_Init(void);

void Select_Digit(uint8 num);

void Display_Digit(uint8 num);

void Display_Number(uint16 num);

#endif /* SVN_SEGMENT_H_ */