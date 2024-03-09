/**
  ******************************************************************************
  * @file    GPIO.h
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-03-09
  * @brief   STM32F10x 实用GPIO配置函数
  ******************************************************************************
  */

#ifndef __GPIO_H
#define __GPIO_H
#include "STM32Device.h"

void Waiting_Low(GPIO_TypeDef* GPIO,uint16_t Pin);
void Waiting_High(GPIO_TypeDef* GPIO,uint16_t Pin);
void PullLow_ms(GPIO_TypeDef* GPIO,uint16_t Pin,uint32_t xms);
void PullLow_us(GPIO_TypeDef* GPIO,uint16_t Pin,uint32_t xus);


#endif /* __GPIO_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
