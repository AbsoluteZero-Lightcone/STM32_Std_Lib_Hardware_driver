/**
  ******************************************************************************
  * @file    ADC.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-20
  * @brief   STM32F10x ADC
  ******************************************************************************
  */
#include "STM32Device.h"

void Simple_ADC_Init(){
	ADC_TempSensorVrefintCmd(ENABLE);
	SimpleEnableGPIO(ADC12_IN0_AF_GPIO,ADC12_IN0_AF_Pin,GPIO_Mode_AIN);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);

}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
