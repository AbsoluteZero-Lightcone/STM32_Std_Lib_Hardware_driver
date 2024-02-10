/**
  ******************************************************************************
  * @file    TIM_Time.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-11
  * @brief   STM32F10x 定时器
  ******************************************************************************
  */

#include "stm32f10x.h"                  // Device header

/**
  * @brief  使用返回函数指针的方式条件性回调RCC_APBxPeriphClockCmd函数
  * @param  RCC_APBxPeriph:
  *   This parameter can be one of the following values:
  *     @arg 
  * @retval RCC_APBxPeriphClockCmd_Handler 函数指针
  * @todo   使用宏函数取代
  */

/*
void (*(get_RCC_APBxPeriphClockCmd_Handler()))(uint32_t RCC_APB2Periph, FunctionalState NewState){
}
*/
typedef void (*RCC_APBxPeriphClockCmd_Handler)(uint32_t RCC_APB2Periph, FunctionalState NewState);
RCC_APBxPeriphClockCmd_Handler get_RCC_APBxPeriphClockCmd_Handler(uint32_t RCC_APBxPeriph){
	if(
		RCC_APBxPeriph == RCC_APB2Periph_TIM1||
		RCC_APBxPeriph == RCC_APB2Periph_TIM8||
		RCC_APBxPeriph == RCC_APB2Periph_TIM9||
		RCC_APBxPeriph == RCC_APB2Periph_TIM10||
		RCC_APBxPeriph == RCC_APB2Periph_TIM11||
		RCC_APBxPeriph == RCC_APB2Periph_TIM15||
		RCC_APBxPeriph == RCC_APB2Periph_TIM16||
		RCC_APBxPeriph == RCC_APB2Periph_TIM17

/**     @arg RCC_APB2Periph_AFIO, RCC_APB2Periph_GPIOA, RCC_APB2Periph_GPIOB,
  *          RCC_APB2Periph_GPIOC, RCC_APB2Periph_GPIOD, RCC_APB2Periph_GPIOE,
  *          RCC_APB2Periph_GPIOF, RCC_APB2Periph_GPIOG, RCC_APB2Periph_ADC1,
  *          RCC_APB2Periph_ADC2, RCC_APB2Periph_TIM1, RCC_APB2Periph_SPI1,
  *          RCC_APB2Periph_TIM8, RCC_APB2Periph_USART1, RCC_APB2Periph_ADC3,
  *          RCC_APB2Periph_TIM15, RCC_APB2Periph_TIM16, RCC_APB2Periph_TIM17,
  *          RCC_APB2Periph_TIM9, RCC_APB2Periph_TIM10, RCC_APB2Periph_TIM11  
  */
	){
		return RCC_APB2PeriphClockCmd;
	}
	else if(
		RCC_APBxPeriph == RCC_APB1Periph_TIM2||
		RCC_APBxPeriph == RCC_APB1Periph_TIM3||
		RCC_APBxPeriph == RCC_APB1Periph_TIM4||
		RCC_APBxPeriph == RCC_APB1Periph_TIM5||
		RCC_APBxPeriph == RCC_APB1Periph_TIM6||
		RCC_APBxPeriph == RCC_APB1Periph_TIM7||
		RCC_APBxPeriph == RCC_APB1Periph_TIM12||
		RCC_APBxPeriph == RCC_APB1Periph_TIM13||
		RCC_APBxPeriph == RCC_APB1Periph_TIM14
/**
  *     @arg RCC_APB1Periph_TIM2, RCC_APB1Periph_TIM3, RCC_APB1Periph_TIM4,
  *          RCC_APB1Periph_TIM5, RCC_APB1Periph_TIM6, RCC_APB1Periph_TIM7,
  *          RCC_APB1Periph_WWDG, RCC_APB1Periph_SPI2, RCC_APB1Periph_SPI3,
  *          RCC_APB1Periph_USART2, RCC_APB1Periph_USART3, RCC_APB1Periph_USART4, 
  *          RCC_APB1Periph_USART5, RCC_APB1Periph_I2C1, RCC_APB1Periph_I2C2,
  *          RCC_APB1Periph_USB, RCC_APB1Periph_CAN1, RCC_APB1Periph_BKP,
  *          RCC_APB1Periph_PWR, RCC_APB1Periph_DAC, RCC_APB1Periph_CEC,
  *          RCC_APB1Periph_TIM12, RCC_APB1Periph_TIM13, RCC_APB1Periph_TIM14  
  */
	){
		return RCC_APB1PeriphClockCmd;
	}
	return 0;
}


/**
  * @brief  将TIMx结构体指针转换为RCC_APBxPeriph
  * @param  TIMx
  * @retval RCC_APBxPeriphClockCmd
  * @todo   没写全，只写了STM32F103C中具有的定时器，并且本函数将被使用宏函数取代
  */
uint32_t TIM_to_RCC_APBxPeriph(TIM_TypeDef* TIMx){
	if(TIMx == TIM1)return RCC_APB2Periph_TIM1;
	if(TIMx == TIM8)return RCC_APB2Periph_TIM8;
	if(TIMx == TIM2)return RCC_APB1Periph_TIM2;
	if(TIMx == TIM3)return RCC_APB1Periph_TIM3;
	if(TIMx == TIM4)return RCC_APB1Periph_TIM4;
	if(TIMx == TIM5)return RCC_APB1Periph_TIM5;
	if(TIMx == TIM6)return RCC_APB1Periph_TIM6;
	if(TIMx == TIM7)return RCC_APB1Periph_TIM7;
	return 0;
}

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
