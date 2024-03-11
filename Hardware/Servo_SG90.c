/**
  ******************************************************************************
  * @file    Servo_SG90.c
  * @author  Lightcone
  * @version V1.0.3
  * @date    2024-03-11
  * @brief   STM32F10x SG90伺服电机驱动
  ******************************************************************************
  */
#include "Servo_SG90.h"
#include "STM32Device.h"

uint16_t PWM_PSC;
uint16_t PWM_ARR;

/** @defgroup Runtime Flags
  * @{
  */ 
FunctionalState TIM1_Enable_Status = DISABLE;
FunctionalState TIM2_Enable_Status = DISABLE;
FunctionalState TIM3_Enable_Status = DISABLE;
FunctionalState TIM4_Enable_Status = DISABLE;

void Set_TIM_Servo_Enable_Status_Flag(TIM_TypeDef* TIMx,FunctionalState x){
	if(TIMx==TIM1)TIM1_Enable_Status=x;
	if(TIMx==TIM2)TIM2_Enable_Status=x;
	if(TIMx==TIM3)TIM3_Enable_Status=x;
	if(TIMx==TIM4)TIM4_Enable_Status=x;
}
FunctionalState Check_TIM_Servo_Enable_Status_Flag(TIM_TypeDef* TIMx){
	if(TIMx==TIM1)return TIM1_Enable_Status;
	if(TIMx==TIM2)return TIM2_Enable_Status;
	if(TIMx==TIM3)return TIM3_Enable_Status;
	if(TIMx==TIM4)return TIM4_Enable_Status;
	return DISABLE;
}
/**
  * @}
  */
void update_Servo_TIM_Info(Servo_SG90* Servo_x){
	if(Servo_x->GPIO == TIM1_CH1_AF_GPIO && Servo_x->Pin == TIM1_CH1_AF_Pin){Servo_x->TIMx = TIM1;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare1;}
	if(Servo_x->GPIO == TIM1_CH2_AF_GPIO && Servo_x->Pin == TIM1_CH2_AF_Pin){Servo_x->TIMx = TIM1;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare2;}
	if(Servo_x->GPIO == TIM1_CH3_AF_GPIO && Servo_x->Pin == TIM1_CH3_AF_Pin){Servo_x->TIMx = TIM1;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare3;}
	if(Servo_x->GPIO == TIM1_CH4_AF_GPIO && Servo_x->Pin == TIM1_CH4_AF_Pin){Servo_x->TIMx = TIM1;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare4;}
	if(Servo_x->GPIO == TIM2_CH1_AF_GPIO && Servo_x->Pin == TIM2_CH1_AF_Pin){Servo_x->TIMx = TIM2;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare1;}
	if(Servo_x->GPIO == TIM2_CH2_AF_GPIO && Servo_x->Pin == TIM2_CH2_AF_Pin){Servo_x->TIMx = TIM2;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare2;}
	if(Servo_x->GPIO == TIM2_CH3_AF_GPIO && Servo_x->Pin == TIM2_CH3_AF_Pin){Servo_x->TIMx = TIM2;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare3;}
	if(Servo_x->GPIO == TIM2_CH4_AF_GPIO && Servo_x->Pin == TIM2_CH4_AF_Pin){Servo_x->TIMx = TIM2;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare4;}
	if(Servo_x->GPIO == TIM3_CH1_AF_GPIO && Servo_x->Pin == TIM3_CH1_AF_Pin){Servo_x->TIMx = TIM3;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare1;}
	if(Servo_x->GPIO == TIM3_CH2_AF_GPIO && Servo_x->Pin == TIM3_CH2_AF_Pin){Servo_x->TIMx = TIM3;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare2;}
	if(Servo_x->GPIO == TIM3_CH3_AF_GPIO && Servo_x->Pin == TIM3_CH3_AF_Pin){Servo_x->TIMx = TIM3;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare3;}
	if(Servo_x->GPIO == TIM3_CH4_AF_GPIO && Servo_x->Pin == TIM3_CH4_AF_Pin){Servo_x->TIMx = TIM3;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare4;}
	if(Servo_x->GPIO == TIM4_CH1_AF_GPIO && Servo_x->Pin == TIM4_CH1_AF_Pin){Servo_x->TIMx = TIM4;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare1;}
	if(Servo_x->GPIO == TIM4_CH2_AF_GPIO && Servo_x->Pin == TIM4_CH2_AF_Pin){Servo_x->TIMx = TIM4;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare2;}
	if(Servo_x->GPIO == TIM4_CH3_AF_GPIO && Servo_x->Pin == TIM4_CH3_AF_Pin){Servo_x->TIMx = TIM4;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare3;}
	if(Servo_x->GPIO == TIM4_CH4_AF_GPIO && Servo_x->Pin == TIM4_CH4_AF_Pin){Servo_x->TIMx = TIM4;Servo_x->TIM_SetCompare_Callback = TIM_SetCompare4;}
}
/**
  * @brief  Servo_SG90舵机PWM驱动
  * @param  &Servo_x
  * @retval void
  */
void Servo_SG90_Init(Servo_SG90* Servo_x){
	// 输出至GPIO
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(Servo_x->GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = Servo_x->Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Servo_x->GPIO,&GPIO_InitStruct);
	
	update_Servo_TIM_Info(Servo_x);
	
	if(!Check_TIM_Servo_Enable_Status_Flag(Servo_x->TIMx)){
		Set_TIM_Servo_Enable_Status_Flag(Servo_x->TIMx,ENABLE);
		
		PWM_PSC = 100;
		PWM_ARR = System_Clock_Freq*0.020/PWM_PSC;
		
		get_RCC_APBxPeriphClockCmd_Handler(TIM_to_RCC_APBxPeriph(Servo_x->TIMx))(TIM_to_RCC_APBxPeriph(Servo_x->TIMx),ENABLE);
		
		TIM_InternalClockConfig(Servo_x->TIMx);
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
		TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;//Filter Config
		TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;

		TIM_TimeBaseInitStruct.TIM_Period = PWM_ARR -1;//ARR 16bit
		TIM_TimeBaseInitStruct.TIM_Prescaler = PWM_PSC -1;//PSC 16bit
		TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0x00;
		TIM_TimeBaseInit(Servo_x->TIMx,&TIM_TimeBaseInitStruct);
		// TIM_TimeBaseInit为使PSC和ARR即刻生效，手动产生更新事件
		// 此时已置更新中断标志位
		//TIM_ClearFlag(Servo_x->TIMx,TIM_FLAG_Update);// 防止刚开启中断就进中断
		
		// 配置定时器输出比较
		TIM_OCInitTypeDef TIM_OCInitStruct;
		TIM_OCStructInit(&TIM_OCInitStruct);
		TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
		TIM_OCInitStruct.TIM_Pulse = 0;
		TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStruct.TIM_OCPolarity =TIM_OCPolarity_High;
		TIM_OC1Init(Servo_x->TIMx,&TIM_OCInitStruct);

		// 开始计时
		TIM_Cmd(Servo_x->TIMx,ENABLE);
	}
}
void Servo_SG90_Set_Degree(Servo_SG90* Servo_x,uint16_t degree){
	Servo_x->degree = degree;
	Servo_x->TIM_SetCompare_Callback(Servo_x->TIMx,(uint16_t)(PWM_ARR*(0.025+0.1*(degree*1.0/Servo_x->degree_MAX))));
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
