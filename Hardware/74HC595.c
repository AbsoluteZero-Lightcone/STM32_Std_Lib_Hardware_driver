#include "STM32Device.h"
#include "74HC595.h"
#include "DataType.h"
void _74HC595_Init(_74HC595_TypeDef* _74HC595_Struct){

//	if(
//	_74HC595_Struct->SER_GPIO == GPIOA || 
//	_74HC595_Struct->SCK_GPIO == GPIOA || 
//	_74HC595_Struct->RCK_GPIO == GPIOA
//	)
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//	if(
//	_74HC595_Struct->SER_GPIO == GPIOB || 
//	_74HC595_Struct->SCK_GPIO == GPIOB || 
//	_74HC595_Struct->RCK_GPIO == GPIOB
//	)
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//	if(
//	_74HC595_Struct->SER_GPIO == GPIOC || 
//	_74HC595_Struct->SCK_GPIO == GPIOC || 
//	_74HC595_Struct->RCK_GPIO == GPIOC
//	)
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(_74HC595_Struct->SER_GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(_74HC595_Struct->SCK_GPIO),ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(_74HC595_Struct->RCK_GPIO),ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP ;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStruct.GPIO_Pin = _74HC595_Struct->SER_Pin;
	GPIO_Init(_74HC595_Struct->SER_GPIO,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = _74HC595_Struct->SCK_Pin;
	GPIO_Init(_74HC595_Struct->SCK_GPIO,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = _74HC595_Struct->RCK_Pin;
	GPIO_Init(_74HC595_Struct->RCK_GPIO,&GPIO_InitStruct);

	GPIO_ResetBits( _74HC595_Struct->SER_GPIO, _74HC595_Struct->SER_Pin);
	GPIO_ResetBits( _74HC595_Struct->SCK_GPIO, _74HC595_Struct->SCK_Pin);
	GPIO_ResetBits( _74HC595_Struct->RCK_GPIO, _74HC595_Struct->RCK_Pin);

}

void _74HC595_WriteByte(_74HC595_TypeDef* _74HC595_Struct,uint8_t Data){
	int8_t i;
	for(i = 7 ;i>=0;i--){
		if(Data&(0x01<<i))GPIO_SetBits( _74HC595_Struct->SER_GPIO, _74HC595_Struct->SER_Pin);
		else GPIO_ResetBits( _74HC595_Struct->SER_GPIO, _74HC595_Struct->SER_Pin);
		GPIO_SetBits( _74HC595_Struct->SCK_GPIO, _74HC595_Struct->SCK_Pin);
		GPIO_ResetBits( _74HC595_Struct->SCK_GPIO, _74HC595_Struct->SCK_Pin);
	}
	GPIO_SetBits( _74HC595_Struct->RCK_GPIO, _74HC595_Struct->RCK_Pin);
	GPIO_ResetBits( _74HC595_Struct->RCK_GPIO, _74HC595_Struct->RCK_Pin);
}

void _74HC595_WriteWORD(_74HC595_TypeDef* _74HC595_Struct,uint16_t Data){
	int8_t i;
	for(i = 15 ;i>=0;i--){
		if(Data&(0x0001<<i))GPIO_SetBits( _74HC595_Struct->SER_GPIO, _74HC595_Struct->SER_Pin);
		else GPIO_ResetBits( _74HC595_Struct->SER_GPIO, _74HC595_Struct->SER_Pin);
		GPIO_SetBits( _74HC595_Struct->SCK_GPIO, _74HC595_Struct->SCK_Pin);
		GPIO_ResetBits( _74HC595_Struct->SCK_GPIO, _74HC595_Struct->SCK_Pin);
	}
	GPIO_SetBits( _74HC595_Struct->RCK_GPIO, _74HC595_Struct->RCK_Pin);
	GPIO_ResetBits( _74HC595_Struct->RCK_GPIO, _74HC595_Struct->RCK_Pin);
}

void _74HC595_WriteData(_74HC595_TypeDef* _74HC595_Struct,uint64_t Data,uint8_t len){//数据位数1~64
	int8_t i;
	for(i = len - 1 ;i>=0;i--){
		if(Data&(1<<i))GPIO_SetBits( _74HC595_Struct->SER_GPIO, _74HC595_Struct->SER_Pin);
		else GPIO_ResetBits( _74HC595_Struct->SER_GPIO, _74HC595_Struct->SER_Pin);
		GPIO_SetBits( _74HC595_Struct->SCK_GPIO, _74HC595_Struct->SCK_Pin);
		GPIO_ResetBits( _74HC595_Struct->SCK_GPIO, _74HC595_Struct->SCK_Pin);
	}
	GPIO_SetBits( _74HC595_Struct->RCK_GPIO, _74HC595_Struct->RCK_Pin);
	GPIO_ResetBits( _74HC595_Struct->RCK_GPIO, _74HC595_Struct->RCK_Pin);
}
