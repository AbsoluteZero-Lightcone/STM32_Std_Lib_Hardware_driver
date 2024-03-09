/**
  ******************************************************************************
  * @file    GPIO.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-03-09
  * @brief   STM32F10x 实用GPIO配置函数
  ******************************************************************************
  */
#include "STM32Device.h"

void Waiting_Low(GPIO_TypeDef* GPIO,uint16_t Pin){
	while(GPIO_ReadInputDataBit(GPIO,Pin));//等待拉低
}
void Waiting_High(GPIO_TypeDef* GPIO,uint16_t Pin){
	while(!GPIO_ReadInputDataBit(GPIO,Pin));//等待总线释放
}
void PullLow_ms(GPIO_TypeDef* GPIO,uint16_t Pin,uint32_t xms){
	GPIO_WriteBit(GPIO,Pin,(BitAction)0);
	Delay_ms(xms);
	GPIO_WriteBit(GPIO,Pin,(BitAction)1);
}
void PullLow_us(GPIO_TypeDef* GPIO,uint16_t Pin,uint32_t xus){
	GPIO_WriteBit(GPIO,Pin,(BitAction)0);
	Delay_ms(xus);
	GPIO_WriteBit(GPIO,Pin,(BitAction)1);
}



/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
