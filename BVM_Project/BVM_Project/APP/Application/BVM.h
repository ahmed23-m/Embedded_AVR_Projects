/*
 * BVM.h
 *
 * Created: 2024/3/25 9:01:49 PM
 *  Author: dasah
 */ 


#ifndef BVM_H_
#define BVM_H_

#include "ADC_Core.h"
#include "IRQH_Core.h"
#include "LED_Core.h"




void BVM_Init(void);

uint32 GetBVM_Value(void);

uint8 GetBattery_Life(uint8 BATCAP);

#endif /* BVM_H_ */