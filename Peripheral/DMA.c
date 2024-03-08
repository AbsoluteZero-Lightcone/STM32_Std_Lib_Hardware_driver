/**
  ******************************************************************************
  * @file    DMA.c
  * @author  Lightcone
  * @version V1.1.0
  * @date    2024-03-08
  * @brief   STM32F10x DMA
  ******************************************************************************
  */
#include "STM32Device.h"
#include "DMA.h"

uint32_t to_DMAx_FLAG_TCy(DMA_Channel_TypeDef* DMAy_Channelx){
	if(DMAy_Channelx == DMA1_Channel1)return DMA1_FLAG_TC1;
	if(DMAy_Channelx == DMA1_Channel2)return DMA1_FLAG_TC2;
	if(DMAy_Channelx == DMA1_Channel3)return DMA1_FLAG_TC3;
	if(DMAy_Channelx == DMA1_Channel4)return DMA1_FLAG_TC4;
	if(DMAy_Channelx == DMA1_Channel5)return DMA1_FLAG_TC5;
	if(DMAy_Channelx == DMA1_Channel6)return DMA1_FLAG_TC6;
	if(DMAy_Channelx == DMA1_Channel7)return DMA1_FLAG_TC7;
	if(DMAy_Channelx == DMA2_Channel1)return DMA2_FLAG_TC1;
	if(DMAy_Channelx == DMA2_Channel2)return DMA2_FLAG_TC2;
	if(DMAy_Channelx == DMA2_Channel3)return DMA2_FLAG_TC3;
	if(DMAy_Channelx == DMA2_Channel4)return DMA2_FLAG_TC4;
	if(DMAy_Channelx == DMA2_Channel5)return DMA2_FLAG_TC5;
	return 0;
}

/**
  * @brief  配置一个DMA通道
  * @param  DMA_Transfer_Channel_x:DMA_Transfer_Channel_TypeDef结构体指针
  * @retval void
  */
void DMA_Transfer_Channel_Config(DMA_Transfer_Channel_TypeDef* DMA_Transfer_Channel_x){
	RCC_AHBPeriphClockCmd(DMA_Channel_to_RCC_AHBPeriph(DMA_Transfer_Channel_x->DMAy_Channelx),ENABLE);

	DMA_InitTypeDef DMA_InitStruct;
	DMA_InitStruct.DMA_PeripheralBaseAddr = DMA_Transfer_Channel_x->AddrA;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_Transfer_Channel_x->DataSize;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Enable;// 是否自动移位
	DMA_InitStruct.DMA_MemoryBaseAddr = DMA_Transfer_Channel_x->Addr_B;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_Transfer_Channel_x->DataSize;
	DMA_InitStruct.DMA_MemoryInc = DMA_PeripheralInc_Enable;
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;// 方向
	DMA_InitStruct.DMA_BufferSize = DMA_Transfer_Channel_x->DataCount;// 循环计数器
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;// 自动重装，不自动重装，因为M2M结束的条件是循环计数器清零
	DMA_InitStruct.DMA_M2M = DMA_M2M_Enable;// 软件触发：Memory to memory，因为软件一般是用DMA转移数据，只提供第一次触发，剩下的数据需要M2M自动触发，直到数据寄存器清零。
	DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA_Transfer_Channel_x->DMAy_Channelx,&DMA_InitStruct);
}

/**
  * @brief  触发一次DMA转换
  * @param  DMA_Transfer_Channel_x:DMA_Transfer_Channel_TypeDef结构体指针
  * @retval void
  */
void DMA_Transfer(DMA_Transfer_Channel_TypeDef* DMA_Transfer_Channel_x){
	DMA_Cmd(DMA_Transfer_Channel_x->DMAy_Channelx,DISABLE);
	DMA_SetCurrDataCounter(DMA_Transfer_Channel_x->DMAy_Channelx,DMA_Transfer_Channel_x->DataCount);
	DMA_Cmd(DMA_Transfer_Channel_x->DMAy_Channelx,ENABLE);
	while(DMA_GetFlagStatus(to_DMAx_FLAG_TCy(DMA_Transfer_Channel_x->DMAy_Channelx))==RESET);
	DMA_ClearFlag(to_DMAx_FLAG_TCy(DMA_Transfer_Channel_x->DMAy_Channelx));
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
