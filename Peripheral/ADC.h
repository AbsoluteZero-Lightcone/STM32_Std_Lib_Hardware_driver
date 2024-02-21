/**
  ******************************************************************************
  * @file    ADC.h
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-21
  * @brief   STM32F10x ADC
  ******************************************************************************
  */

#ifndef __ADC_H
#define __ADC_H

#include "STM32Device.h"

void Simple_ADC1_Single_Channel_PA0_Init(void);
uint16_t get_Simple_ADC1_Single_Channel_PA0_Value(void);

#endif /* __ADC_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
