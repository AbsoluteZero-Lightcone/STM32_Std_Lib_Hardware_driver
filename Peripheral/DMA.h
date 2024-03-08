/**
  ******************************************************************************
  * @file    DMA.c
  * @author  Lightcone
  * @version V1.0.1
  * @date    2024-03-08
  * @brief   STM32F10x DMA
  ******************************************************************************
  */

#ifndef __DMA_H
#define __DMA_H

#include "STM32Device.h"
void DMA_Transfer(DMA_Channel_TypeDef* DMAy_Channelx,uint32_t DataSize,uint32_t AddrA,uint32_t Addr_B,uint16_t DataLength);

	
#endif /* __DMA_H */
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
