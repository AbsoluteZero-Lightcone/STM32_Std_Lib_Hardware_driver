#include "STM32Device.h"

#include "74HC138.h"

void _74HC138_Write(_74HC138_TypeDef* _74HC138,uint8_t n){
	GPIO_WriteBit(_74HC138->A_GPIO,_74HC138->A_Pin,(BitAction)(n&1));
	GPIO_WriteBit(_74HC138->B_GPIO,_74HC138->B_Pin,(BitAction)(n&2));
	GPIO_WriteBit(_74HC138->C_GPIO,_74HC138->C_Pin,(BitAction)(n&4));
}

void _74HC138_Init(_74HC138_TypeDef* _74HC138_Struct){
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(_74HC138_Struct->A_GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(_74HC138_Struct->B_GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(_74HC138_Struct->C_GPIO),ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP ;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStruct.GPIO_Pin = _74HC138_Struct->A_Pin;GPIO_Init(_74HC138_Struct->A_GPIO,&GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin = _74HC138_Struct->B_Pin;GPIO_Init(_74HC138_Struct->B_GPIO,&GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin = _74HC138_Struct->C_Pin;GPIO_Init(_74HC138_Struct->C_GPIO,&GPIO_InitStruct);

	GPIO_ResetBits( _74HC138_Struct->A_GPIO, _74HC138_Struct->A_Pin);
	GPIO_ResetBits( _74HC138_Struct->B_GPIO, _74HC138_Struct->B_Pin);
	GPIO_ResetBits( _74HC138_Struct->C_GPIO, _74HC138_Struct->C_Pin);
}

