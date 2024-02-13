/**
  ******************************************************************************
  * @file    Pin_Config.h
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-10
  * @brief   用于STM32F10x标准库的引脚可用性和引脚功能的快速配置
  ******************************************************************************
  */
#ifndef __PIN_CONFIG_H
#define __PIN_CONFIG_H

#include "stm32f10x.h"                  // Device header

void setPowerPin(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x,uint8_t val);
void setFloatingPin(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x);
void setInputPullUpPin(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x);


void DisableJTRST(void);
void DisableJTAG(void);
void DisableFullSWJ(void);



#endif /* __PIN_CONFIG_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
