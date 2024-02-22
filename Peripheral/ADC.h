/**
  ******************************************************************************
  * @file    ADC.h
  * @author  Lightcone
  * @version V1.1.0
  * @date    2024-02-22
  * @brief   STM32F10x ADC
  ******************************************************************************
  */

#ifndef __ADC_H
#define __ADC_H

#include "STM32Device.h"

void Simple_ADC1_Single_Channel_Init(void);
uint16_t get_Simple_ADC1_Single_Channel_Value(uint8_t ADC_Channel_x);

#endif /* __ADC_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
