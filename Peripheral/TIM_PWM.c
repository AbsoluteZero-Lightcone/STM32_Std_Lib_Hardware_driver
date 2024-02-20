/**
  ******************************************************************************
  * @file    TIM_PWM.c
  * @author  Lightcone
  * @version V1.0.1
  * @date    2024-02-15
  * @brief   定时器输出PWM信号
  ******************************************************************************
  */
#include "STM32Device.h"

#include "TIM_PWM.h"
#include "STM32Device.h"

void Simple_PWM_ParamUpdate(Simple_PWM_TypeDef* Simple_PWM_Structure){
	
	Simple_PWM_Structure->PWM_ARR = (uint16_t)(1.0/Simple_PWM_Structure->precision);
	Simple_PWM_Structure->PWM_PSC = (uint16_t)(System_Clock_Freq*1.0/Simple_PWM_Structure->freq/Simple_PWM_Structure->PWM_ARR);
	Simple_PWM_Structure->PWM_CCR = (uint16_t)Simple_PWM_Structure->PWM_ARR*Simple_PWM_Structure->duty;
}

/**
  * @brief  单通道PWM的简单应用
  * @param  &Simple_PWM_Structure
  * @retval void
  */
void Simple_PWM_Init(Simple_PWM_TypeDef* Simple_PWM_Structure){
	
	get_RCC_APBxPeriphClockCmd_Handler(TIM_to_RCC_APBxPeriph(Simple_PWM_Structure->TIMx))(TIM_to_RCC_APBxPeriph(Simple_PWM_Structure->TIMx),ENABLE);
	
	TIM_InternalClockConfig(Simple_PWM_Structure->TIMx);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;//Filter Config
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInitStruct.TIM_Period = Simple_PWM_Structure->PWM_ARR -1;//ARR 16bit
	
	TIM_TimeBaseInitStruct.TIM_Prescaler = Simple_PWM_Structure->PWM_PSC -1;//PSC 16bit
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0x00;
	TIM_TimeBaseInit(Simple_PWM_Structure->TIMx,&TIM_TimeBaseInitStruct);
	// TIM_TimeBaseInit为使PSC和ARR即刻生效，手动产生更新事件
	// 此时已置更新中断标志位
	TIM_ClearFlag(Simple_PWM_Structure->TIMx,TIM_FLAG_Update);// 防止刚开启中断就进中断
	
	// 配置定时器输出比较
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	
	TIM_OCInitStruct.TIM_Pulse = Simple_PWM_Structure->PWM_CCR;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM_OC1Init(Simple_PWM_Structure->TIMx,&TIM_OCInitStruct);
	
	// 输出至GPIO
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(Simple_PWM_Structure->GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = Simple_PWM_Structure->Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Simple_PWM_Structure->GPIO,&GPIO_InitStruct);
	
	// 开始计时
	TIM_Cmd(Simple_PWM_Structure->TIMx,ENABLE);
	
}


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
