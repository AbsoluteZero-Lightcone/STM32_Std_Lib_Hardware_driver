/**
  ******************************************************************************
  * @file    TIM_EncoderInterface.c
  * @author  Lightcone
  * @version V1.0.1
  * @date    2024-02-16
  * @brief   STM32F10x 定时器编码器接口
  ******************************************************************************
  */
#include "STM32Device.h"

#include "STM32Device.h"

void Simple_TIM3_EncoderInterface_Init(){
	SimpleEnableGPIO(TIM3_CH1_AF_GPIO,TIM3_CH1_AF_Pin|TIM3_CH2_AF_Pin,GPIO_Mode_IN_FLOATING);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	TIM_InternalClockConfig(TIM3);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 1 - 1;
	TIM_TimeBaseInitStruct.TIM_Period = 65536 - 1;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);

	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV4;

	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInit(TIM3, &TIM_ICInitStructure);

	TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInit(TIM3, &TIM_ICInitStructure);

	TIM_EncoderInterfaceConfig(TIM3,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
	TIM_Cmd(TIM3,ENABLE);
}

uint16_t get_Simple_TIM3_EncoderInterface_Increment(){
	uint16_t temp = TIM_GetCounter(TIM3);
	TIM_SetCounter(TIM3,0);
	return temp;
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
