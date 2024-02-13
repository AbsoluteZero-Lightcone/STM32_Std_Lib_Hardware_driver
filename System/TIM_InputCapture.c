/**
  ******************************************************************************
  * @file    TIM_InputCapture.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-14
  * @brief   STM32F10x 定时器输入捕获测频率 PWMI 测频率占空比
  ******************************************************************************
  */
#include "stm32f10x.h"                  // Device header

void Simple_TIM_IC_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
