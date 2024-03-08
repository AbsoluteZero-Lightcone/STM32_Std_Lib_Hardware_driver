/**
  ******************************************************************************
  * @file    DMA.c
  * @author  Lightcone
  * @version V1.0.1
  * @date    2024-03-08
  * @brief   STM32F10x DMA
  ******************************************************************************
  */
#include "STM32Device.h"

/**
  * @brief  DMA数据转运
  * @param  DMAy_Channelx
  *     @arg y = 1 时，x = 1~7；y = 2 时，x = 1~5
  * @param  DataSize
  *   This parameter can be one of the following values:
  *     @arg DMA_PeripheralDataSize_Byte			8bit
  *     @arg DMA_PeripheralDataSize_HalfWord	16bit
  *     @arg DMA_PeripheralDataSize_Word			32bit
  * @param  AddrA:数据转运的来源地址(uint32_t, 标准库寄存器定义的数据类型也是uint32_t)
  * @param  AddrB:数据转运的目的地址(uint32_t, 标准库寄存器定义的数据类型也是uint32_t)
  * @param  DataLength:要转运的数组数据的个数0~65535
  * @retval void
  */
void DMA_Transfer(DMA_Channel_TypeDef* DMAy_Channelx,uint32_t DataSize,uint32_t AddrA,uint32_t Addr_B,uint16_t DataLength){
	RCC_AHBPeriphClockCmd(DMA_Channel_to_RCC_AHBPeriph(DMAy_Channelx),ENABLE);

	DMA_InitTypeDef DMA_InitStruct;
	DMA_InitStruct.DMA_PeripheralBaseAddr = AddrA;
	DMA_InitStruct.DMA_PeripheralDataSize = DataSize;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Enable;// 是否自动移位
	DMA_InitStruct.DMA_MemoryBaseAddr = Addr_B;
	DMA_InitStruct.DMA_MemoryDataSize = DataSize;
	DMA_InitStruct.DMA_MemoryInc = DMA_PeripheralInc_Enable;
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;// 方向
	DMA_InitStruct.DMA_BufferSize = DataLength;// 循环计数器
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;// 自动重装，不自动重装，因为M2M结束的条件是循环计数器清零
	DMA_InitStruct.DMA_M2M = DMA_M2M_Enable;// 软件触发：Memory to memory，因为软件一般是用DMA转移数据，只提供第一次触发，剩下的数据需要M2M自动触发，直到数据寄存器清零。
	DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMAy_Channelx,&DMA_InitStruct);

	DMA_Cmd(DMAy_Channelx,ENABLE);
}


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
