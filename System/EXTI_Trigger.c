#include "STM32Device.h"
#include "DataType.h"
#include "EXTI_Trigger.h"

void EXTI_Trigger_Init(EXTI_Trigger_TypeDef *EXTI_t,uint32_t NVIC_PriorityGroup){

	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(EXTI_t->GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = EXTI_t->Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EXTI_t->GPIO,&GPIO_InitStruct);
	
	GPIO_EXTILineConfig(to_GPIO_PortSource(EXTI_t->GPIO), to_GPIO_PinSource(EXTI_t->Pin));
	
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line = to_EXTI_Line(EXTI_t->Pin);
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_t->EXTIMode;
	EXTI_InitStruct.EXTI_Trigger = EXTI_t->EXTITrigger;
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = to_IRQn_Type(EXTI_t->Pin);
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = EXTI_t->NVIC_IRQChannelPreemptionPriority;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = EXTI_t->NVIC_IRQChannelSubPriority;
	NVIC_Init(&NVIC_InitStruct);
}

void EXTI_Trigger_Detect_Handler(EXTI_Trigger_TypeDef *EXTI_t,void (*callback)(void)){
	if(EXTI_GetITStatus(to_EXTI_Line(EXTI_t->Pin))==SET)
		callback();
	EXTI_ClearITPendingBit(to_EXTI_Line(EXTI_t->Pin));
}
