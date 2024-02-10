/**
  ******************************************************************************
  * @file    TIM_PWM.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-11
  * @brief   定时器输出PWM信号
  ******************************************************************************
  */
#include "stm32f10x.h"                  // Device header
#include "DataType.h"

/** 
  * @brief  Simple_PWM structure definition  
  */
typedef struct
{
	TIM_TypeDef* TIMx;
	float precision;// 大于0.00001525879
	uint32_t freq;
	float duty;
	GPIO_TypeDef* GPIO;
	uint16_t Pin;
}Simple_PWM_TypeDef;


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
	uint16_t PWM_ARR = (uint16_t)(1.0/Simple_PWM_Structure->precision);
	TIM_TimeBaseInitStruct.TIM_Period = PWM_ARR -1;//ARR 16bit
	uint16_t PWM_PSC = (uint16_t)(72000000.0/Simple_PWM_Structure->freq/PWM_ARR);
	TIM_TimeBaseInitStruct.TIM_Prescaler = PWM_PSC -1;//PSC 16bit
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0x00;
	TIM_TimeBaseInit(Simple_PWM_Structure->TIMx,&TIM_TimeBaseInitStruct);
	// TIM_TimeBaseInit为使PSC和ARR即刻生效，手动产生更新事件
	// 此时已置更新中断标志位
	TIM_ClearFlag(Simple_PWM_Structure->TIMx,TIM_FLAG_Update);// 防止刚开启中断就进中断
	
	// 配置定时器输出比较
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	uint16_t PWM_CCR = (uint16_t)PWM_ARR*Simple_PWM_Structure->duty;
	TIM_OCInitStruct.TIM_Pulse = PWM_CCR;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM_OC1Init(Simple_PWM_Structure->TIMx,&TIM_OCInitStruct);
	
	// 输出至GPIO
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(Simple_PWM_Structure->GPIO),ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = Simple_PWM_Structure->Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Simple_PWM_Structure->GPIO,&GPIO_InitStruct);
	
	// 开始计时
	TIM_Cmd(Simple_PWM_Structure->TIMx,ENABLE);
	
}


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
