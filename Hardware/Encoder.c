#include "stm32f10x.h"                  // Device header
#include "DataType.h"
#include "Encoder.h"

/**
  * @brief  
  * @param  NVIC_PriorityGroup: specifies the priority grouping bits length. 
  *   This parameter can be one of the following values:
  *     @arg NVIC_PriorityGroup_0: 0 bits for pre-emption priority
  *                                4 bits for subpriority
  *     @arg NVIC_PriorityGroup_1: 1 bits for pre-emption priority
  *                                3 bits for subpriority
  *     @arg NVIC_PriorityGroup_2: 2 bits for pre-emption priority
  *                                2 bits for subpriority
  *     @arg NVIC_PriorityGroup_3: 3 bits for pre-emption priority
  *                                1 bits for subpriority
  *     @arg NVIC_PriorityGroup_4: 4 bits for pre-emption priority
  *                                0 bits for subpriority
  * @retval None
  */
void Encoder_Init(Encoder_TypeDef* Encoder_InitStruct,uint32_t NVIC_PriorityGroup){


	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(Encoder_InitStruct->OutputA_GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(Encoder_InitStruct->OutputB_GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(Encoder_InitStruct->Button_GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_InitStruct.GPIO_Pin = Encoder_InitStruct->OutputA_Pin;
	GPIO_Init(Encoder_InitStruct->OutputA_GPIO,&GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin = Encoder_InitStruct->OutputB_Pin;
	GPIO_Init(Encoder_InitStruct->OutputB_GPIO,&GPIO_InitStruct);
//	GPIO_InitStruct.GPIO_Pin = Encoder_InitStruct->Button_Pin;
//	GPIO_Init(Encoder_InitStruct->Button_GPIO,&GPIO_InitStruct);
	
	// Choose which GPIO to connect to the EXTI line
	GPIO_EXTILineConfig(to_GPIO_PortSource(Encoder_InitStruct->OutputA_GPIO),to_GPIO_PinSource(Encoder_InitStruct->OutputA_Pin));
	GPIO_EXTILineConfig(to_GPIO_PortSource(Encoder_InitStruct->OutputB_GPIO),to_GPIO_PinSource(Encoder_InitStruct->OutputB_Pin));
	// Should Use Timer interrupt to drive  GPIO_EXTILineConfig(to_GPIO_PortSource(Encoder_InitStruct->Button_GPIO),Encoder_InitStruct->Button_Pin);
	
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStruct.EXTI_Line = to_EXTI_Line(Encoder_InitStruct->OutputA_Pin);
	EXTI_Init(&EXTI_InitStruct);
	EXTI_InitStruct.EXTI_Line = to_EXTI_Line(Encoder_InitStruct->OutputB_Pin);
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE ;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannel = to_IRQn_Type(Encoder_InitStruct->OutputA_Pin);
	NVIC_Init(&NVIC_InitStruct);
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannel = to_IRQn_Type(Encoder_InitStruct->OutputB_Pin);
	NVIC_Init(&NVIC_InitStruct);
}



void Interrupt_Output_A(Encoder_TypeDef* Encoder_InitStruct){
	if(EXTI_GetITStatus(to_EXTI_Line(Encoder_InitStruct->OutputA_Pin))==SET){
		if(GPIO_ReadInputDataBit(Encoder_InitStruct->OutputB_GPIO, Encoder_InitStruct->OutputB_Pin) == 0){
			Encoder_InitStruct->cnt--;
		}
		EXTI_ClearITPendingBit(to_EXTI_Line(Encoder_InitStruct->OutputA_Pin));
	}
}

void Interrupt_Output_B(Encoder_TypeDef* Encoder_InitStruct){
	if(EXTI_GetITStatus(to_EXTI_Line(Encoder_InitStruct->OutputB_Pin))==SET){
		if(GPIO_ReadInputDataBit(Encoder_InitStruct->OutputA_GPIO, Encoder_InitStruct->OutputA_Pin) == 0){
			Encoder_InitStruct->cnt++;
		}
		EXTI_ClearITPendingBit(to_EXTI_Line(Encoder_InitStruct->OutputB_Pin));
	}
}

int8_t getIncrement(Encoder_TypeDef* Encoder_InitStruct){
	int8_t temp = Encoder_InitStruct->cnt;
	Encoder_InitStruct->cnt = 0;
	return temp;
}

