#include "stm32f10x.h"                  // Device header

uint32_t to_RCC_APB2Periph(GPIO_TypeDef* GPIO);
uint8_t to_GPIO_PortSource(GPIO_TypeDef* GPIO);
uint8_t to_GPIO_PinSource(uint16_t Pin);
uint32_t to_EXTI_Line(uint16_t Pin);
uint8_t to_IRQn_Type(uint16_t Pin);

uint32_t to_RCC_APB2Periph(GPIO_TypeDef* GPIO){
	if(GPIO == GPIOA)return RCC_APB2Periph_GPIOA;
	if(GPIO == GPIOB)return RCC_APB2Periph_GPIOB;
	if(GPIO == GPIOC)return RCC_APB2Periph_GPIOC;
	if(GPIO == GPIOD)return RCC_APB2Periph_GPIOD;
	if(GPIO == GPIOE)return RCC_APB2Periph_GPIOE;
	if(GPIO == GPIOF)return RCC_APB2Periph_GPIOF;
	if(GPIO == GPIOG)return RCC_APB2Periph_GPIOG;
	return 0;
}

uint8_t to_GPIO_PortSource(GPIO_TypeDef* GPIO){
	if(GPIO == GPIOA)return GPIO_PortSourceGPIOA;
	if(GPIO == GPIOB)return GPIO_PortSourceGPIOB;
	if(GPIO == GPIOC)return GPIO_PortSourceGPIOC;
	if(GPIO == GPIOD)return GPIO_PortSourceGPIOD;
	if(GPIO == GPIOE)return GPIO_PortSourceGPIOE;
	if(GPIO == GPIOF)return GPIO_PortSourceGPIOF;
	if(GPIO == GPIOG)return GPIO_PortSourceGPIOG;
	return 0;
}

uint8_t to_GPIO_PinSource(uint16_t Pin){
	if(Pin==GPIO_Pin_0)return GPIO_PinSource0;
	if(Pin==GPIO_Pin_1)return GPIO_PinSource1;
	if(Pin==GPIO_Pin_2)return GPIO_PinSource2;
	if(Pin==GPIO_Pin_3)return GPIO_PinSource3;
	if(Pin==GPIO_Pin_4)return GPIO_PinSource4;
	if(Pin==GPIO_Pin_5)return GPIO_PinSource5;
	if(Pin==GPIO_Pin_6)return GPIO_PinSource6;
	if(Pin==GPIO_Pin_7)return GPIO_PinSource7;
	if(Pin==GPIO_Pin_8)return GPIO_PinSource8;
	if(Pin==GPIO_Pin_9)return GPIO_PinSource9;
	if(Pin==GPIO_Pin_10)return GPIO_PinSource10;
	if(Pin==GPIO_Pin_11)return GPIO_PinSource11;
	if(Pin==GPIO_Pin_12)return GPIO_PinSource12;
	if(Pin==GPIO_Pin_13)return GPIO_PinSource13;
	if(Pin==GPIO_Pin_14)return GPIO_PinSource14;
	if(Pin==GPIO_Pin_15)return GPIO_PinSource15;
	return 0;
}

uint32_t to_EXTI_Line(uint16_t Pin){
	if(Pin==GPIO_Pin_0)return EXTI_Line0;
	if(Pin==GPIO_Pin_1)return EXTI_Line1;
	if(Pin==GPIO_Pin_2)return EXTI_Line2;
	if(Pin==GPIO_Pin_3)return EXTI_Line3;
	if(Pin==GPIO_Pin_4)return EXTI_Line4;
	if(Pin==GPIO_Pin_5)return EXTI_Line5;
	if(Pin==GPIO_Pin_6)return EXTI_Line6;
	if(Pin==GPIO_Pin_7)return EXTI_Line7;
	if(Pin==GPIO_Pin_8)return EXTI_Line8;
	if(Pin==GPIO_Pin_9)return EXTI_Line9;
	if(Pin==GPIO_Pin_10)return EXTI_Line10;
	if(Pin==GPIO_Pin_11)return EXTI_Line11;
	if(Pin==GPIO_Pin_12)return EXTI_Line12;
	if(Pin==GPIO_Pin_13)return EXTI_Line13;
	if(Pin==GPIO_Pin_14)return EXTI_Line14;
	if(Pin==GPIO_Pin_15)return EXTI_Line15;
	return 0;
}

uint8_t to_IRQn_Type(uint16_t Pin){
	if(Pin==GPIO_Pin_0)return EXTI0_IRQn;
	if(Pin==GPIO_Pin_1)return EXTI1_IRQn;
	if(Pin==GPIO_Pin_2)return EXTI2_IRQn;
	if(Pin==GPIO_Pin_3)return EXTI3_IRQn;
	if(Pin==GPIO_Pin_4)return EXTI4_IRQn;
	
	if(Pin==GPIO_Pin_5)return EXTI9_5_IRQn;
	if(Pin==GPIO_Pin_6)return EXTI9_5_IRQn;
	if(Pin==GPIO_Pin_7)return EXTI9_5_IRQn;
	if(Pin==GPIO_Pin_8)return EXTI9_5_IRQn;
	if(Pin==GPIO_Pin_9)return EXTI9_5_IRQn;
	
	if(Pin==GPIO_Pin_10)return EXTI15_10_IRQn;
	if(Pin==GPIO_Pin_11)return EXTI15_10_IRQn;
	if(Pin==GPIO_Pin_12)return EXTI15_10_IRQn;
	if(Pin==GPIO_Pin_13)return EXTI15_10_IRQn;
	if(Pin==GPIO_Pin_14)return EXTI15_10_IRQn;
	if(Pin==GPIO_Pin_15)return EXTI15_10_IRQn;
	return 0;
}
/**
  * @brief  使用返回函数指针的方式条件性回调RCC_APBxPeriphClockCmd函数
  * @param  RCC_APBxPeriph:
  *   This parameter can be one of the following values:
  *     @arg 
  * @retval RCC_APBxPeriphClockCmd_Handler 函数指针
  * @todo   使用宏函数取代
  */


void (*(get_RCC_APBxPeriphClockCmd_Handler(uint32_t RCC_APBxPeriph)))(uint32_t RCC_APB2Periph, FunctionalState NewState){
/*
typedef void (*RCC_APBxPeriphClockCmd_Handler)(uint32_t RCC_APB2Periph, FunctionalState NewState);
RCC_APBxPeriphClockCmd_Handler get_RCC_APBxPeriphClockCmd_Handler(uint32_t RCC_APBxPeriph){
*/
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

