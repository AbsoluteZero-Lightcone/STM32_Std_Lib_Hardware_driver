/**
  ******************************************************************************
  * @file    TIM_InputCapture.c
  * @author  Lightcone
  * @version V1.0.3
  * @date    2024-02-15
  * @brief   STM32F10x 定时器输入捕获测频率 PWMI 测频率占空比
  ******************************************************************************
  */
#include "STM32Device.h"

#include "STM32Device.h"

uint16_t TIM_Prescaler = 72;// 小了精度高但被测频率不能过低

void Simple_TIM3_PWMI_Init(){
	SimpleConfigGPIO(TIM3_CH1_AF_GPIO,TIM3_CH1_AF_Pin,GPIO_Mode_IN_FLOATING);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	TIM_InternalClockConfig(TIM3);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_Prescaler = TIM_Prescaler - 1;
	TIM_TimeBaseInitStruct.TIM_Period = 65536 - 1;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);

	TIM_ICInitTypeDef TIM_ICInitStruct;
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICFilter = 0x1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_PWMIConfig(TIM3,&TIM_ICInitStruct);

	TIM_SelectInputTrigger(TIM3,TIM_TS_TI1FP1);
	TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_Reset);

	TIM_Cmd(TIM3,ENABLE);
}

float Simple_TIM_PWMI_getFreq(){
	return System_Clock_Freq*1.0 /TIM_Prescaler /TIM_GetCapture1(TIM3);
}
float Simple_TIM_PWMI_getDuty(){
	return TIM_GetCapture2(TIM3)*1.0/TIM_GetCapture1(TIM3);
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
