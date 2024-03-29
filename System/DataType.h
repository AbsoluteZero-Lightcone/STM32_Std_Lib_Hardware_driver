/**
  ******************************************************************************
  * @file    DataType.h
  * @author  Lightcone
  * @version V1.3.1
  * @date    2024-02-20
  * @brief   STM32F10x 数据类型转换库
  ******************************************************************************
  */

#ifndef __DATA_TYPE_H
#define __DATA_TYPE_H

#include "STM32Device.h"

// 数据类型转换
uint32_t to_RCC_APB2Periph(GPIO_TypeDef* GPIO);
uint8_t to_GPIO_PortSource(GPIO_TypeDef* GPIO);
uint8_t to_GPIO_PinSource(uint16_t Pin);
uint32_t to_EXTI_Line(uint16_t Pin);
uint8_t to_IRQn_Type(uint16_t Pin);

void (*(get_RCC_APBxPeriphClockCmd_Handler(uint32_t RCC_APBxPeriph)))(uint32_t RCC_APB2Periph, FunctionalState NewState);
uint32_t TIM_to_RCC_APBxPeriph(TIM_TypeDef* TIMx);
uint32_t DMA_Channel_to_RCC_AHBPeriph(DMA_Channel_TypeDef* DMAy_Channelx);

#endif /* __DATA_TYPE_H */


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
