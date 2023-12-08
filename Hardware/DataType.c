#include "stm32f10x.h"                  // Device header

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
