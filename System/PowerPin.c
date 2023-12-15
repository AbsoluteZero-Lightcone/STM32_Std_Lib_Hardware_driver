#include "stm32f10x.h"     // Device header
#include "DataType.h"

void setPowerPin(GPIO_TypeDef* GPIO,uint16_t Pin,uint8_t val){
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(GPIO),ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIO,&GPIO_InitStruct);
	GPIO_WriteBit(GPIO,Pin,(BitAction)val);
}
