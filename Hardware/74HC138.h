#ifndef __74HC138_H
#define __74HC138_H
#include "stm32f10x.h"                  // Device header
#include "DataType.h"

typedef struct{
	GPIO_TypeDef* A_GPIO;uint16_t A_Pin;
	GPIO_TypeDef* B_GPIO;uint16_t B_Pin;
	GPIO_TypeDef* C_GPIO;uint16_t C_Pin;
} _74HC138_TypeDef;

void _74HC138_Write(_74HC138_TypeDef* _74HC138,uint8_t n);
void _74HC138_Init(_74HC138_TypeDef* _74HC138_Struct);


#endif
