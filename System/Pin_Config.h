/**
  ******************************************************************************
  * @file    Pin_Config.h
  * @author  Lightcone
  * @version V1.1.0
  * @date    2024-02-14
  * @brief   用于STM32F10x标准库的引脚可用性和引脚功能的快速配置
  ******************************************************************************
  */
#ifndef __PIN_CONFIG_H
#define __PIN_CONFIG_H

#include "STM32Device.h"


void DisableJTRST(void);
void DisableJTAG(void);
void DisableFullSWJ(void);

void SimpleConfigGPIO(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode);
void setPowerPin(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x,uint8_t val);



#endif /* __PIN_CONFIG_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
