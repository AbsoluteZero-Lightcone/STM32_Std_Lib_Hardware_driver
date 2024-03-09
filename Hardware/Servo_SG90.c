/**
  ******************************************************************************
  * @file    Servo_SG90.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-03-09
  * @brief   STM32F10x SG90伺服电机驱动
  ******************************************************************************
  */
#include "Servo_SG90.h"

typedef struct{
	TIM_TypeDef* TIMx;
	GPIO_TypeDef* GPIO;
	uint16_t Pin;
	
}Servo_SG90;

/**
  * @brief  Servo_SG90舵机PWM驱动
  * @param  &Servo_x
  * @retval void
  */
void Servo_SG90_Init(Servo_SG90* Servo_x){
	
	get_RCC_APBxPeriphClockCmd_Handler(TIM_to_RCC_APBxPeriph(Servo_x->TIMx))(TIM_to_RCC_APBxPeriph(Servo_x->TIMx),ENABLE);
	
	TIM_InternalClockConfig(Servo_x->TIMx);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;//Filter Config
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	uint16_t PWM_ARR = ;
	uint16_t PWM_PSC = ;
	uint16_t PWM_CCR = ;
	TIM_TimeBaseInitStruct.TIM_Period = PWM_ARR -1;//ARR 16bit
	TIM_TimeBaseInitStruct.TIM_Prescaler = PWM_PSC -1;//PSC 16bit
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0x00;
	TIM_TimeBaseInit(Servo_x->TIMx,&TIM_TimeBaseInitStruct);
	// TIM_TimeBaseInit为使PSC和ARR即刻生效，手动产生更新事件
	// 此时已置更新中断标志位
	TIM_ClearFlag(Servo_x->TIMx,TIM_FLAG_Update);// 防止刚开启中断就进中断
	
	// 配置定时器输出比较
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	
	TIM_OCInitStruct.TIM_Pulse = PWM_CCR;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM_OC1Init(Servo_x->TIMx,&TIM_OCInitStruct);
	
	// 输出至GPIO
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(Servo_x->GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = Servo_x->Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Servo_x->GPIO,&GPIO_InitStruct);
	
	// 开始计时
	TIM_Cmd(Servo_x->TIMx,ENABLE);
	
}
void Servo_SG90_Set_Degree(float degree){
	
}


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
