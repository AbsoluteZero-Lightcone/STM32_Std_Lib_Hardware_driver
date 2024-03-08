/**
  ******************************************************************************
  * @file    DMA.c
  * @author  Lightcone
  * @version V1.1.0
  * @date    2024-03-08
  * @brief   STM32F10x DMA
  ******************************************************************************
  */

#ifndef __DMA_H
#define __DMA_H

#include "STM32Device.h"

/**
  * @param  DMAy_Channelx
  *     @arg y = 1 时，x = 1~7；y = 2 时，x = 1~5
  * @param  AddrA:数据转运的来源地址(uint32_t, 标准库寄存器定义的数据类型也是uint32_t)
  * @param  AddrB:数据转运的目的地址(uint32_t, 标准库寄存器定义的数据类型也是uint32_t)
  * @param  DataSize
  *   This parameter can be one of the following values:
  *     @arg DMA_PeripheralDataSize_Byte			8bit
  *     @arg DMA_PeripheralDataSize_HalfWord	16bit
  *     @arg DMA_PeripheralDataSize_Word			32bit
* @param  DataCount:要转运的数组数据的个数0~65535
  */
typedef struct{
	DMA_Channel_TypeDef* DMAy_Channelx;
	uint32_t AddrA;
	uint32_t Addr_B;
	uint32_t DataSize;
	uint16_t DataCount;
}DMA_Transfer_Channel_TypeDef;

uint32_t to_DMAx_FLAG_TCy(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_Transfer_Channel_Config(DMA_Transfer_Channel_TypeDef* DMA_Transfer_Channel_x);
void DMA_Transfer(DMA_Transfer_Channel_TypeDef* DMA_Transfer_Channel_x);
	
#endif /* __DMA_H */
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
