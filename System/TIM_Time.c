/**
  ******************************************************************************
  * @file    TIM_Time.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-11
  * @brief   STM32F10x 定时器
  ******************************************************************************
  */

#include "STM32Device.h"
#include "DataType.h"

/**
  * @brief  初始化一个定时器外设
  * @param  TIMx
  * @retval void
  */
void Time_Init(TIM_TypeDef* TIMx){
	
	get_RCC_APBxPeriphClockCmd_Handler(TIM_to_RCC_APBxPeriph(TIMx))(TIM_to_RCC_APBxPeriph(TIMx),ENABLE);
	
	TIM_InternalClockConfig(TIMx);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;//Filter Config
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 7200 -1;//PSC 16bit
	TIM_TimeBaseInitStruct.TIM_Period = 10000 -1;//ARR 16bit
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0x00;
	TIM_TimeBaseInit(TIMx,&TIM_TimeBaseInitStruct);
	// TIM_TimeBaseInit为使PSC和ARR即刻生效，手动产生更新事件
	// 此时已置更新中断标志位
	TIM_ClearFlag(TIMx,TIM_FLAG_Update);// 防止刚开启中断就进中断
	
	
}


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
