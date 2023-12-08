#include "stm32f10x.h"                  // Device header
#include "74HC595.h"
#include "Delay.h"

_74HC595_TypeDef IC1,IC2;

void MatrixLED_Init(
	GPIO_TypeDef* IC1_SER_GPIO_t,
	uint16_t IC1_SER_Pin_t,
	GPIO_TypeDef* IC1_SCK_GPIO_t,
	uint16_t IC1_SCK_Pin_t,
	GPIO_TypeDef* IC1_RCK_GPIO_t,
	uint16_t IC1_RCK_Pin_t,

	GPIO_TypeDef* IC2_SER_GPIO_t,
	uint16_t IC2_SER_Pin_t,
	GPIO_TypeDef* IC2_SCK_GPIO_t,
	uint16_t IC2_SCK_Pin_t,
	GPIO_TypeDef* IC2_RCK_GPIO_t,
	uint16_t IC2_RCK_Pin_t)
{
	
	IC1.SER_GPIO = IC1_SER_GPIO_t;
	IC1.SER_Pin = IC1_SER_Pin_t;
	IC1.SCK_GPIO = IC1_SCK_GPIO_t;
	IC1.SCK_Pin = IC1_SCK_Pin_t;
	IC1.RCK_GPIO  = IC1_RCK_GPIO_t;
	IC1.RCK_Pin = IC1_RCK_Pin_t;
	
	IC2.SER_GPIO = IC2_SER_GPIO_t;
	IC2.SER_Pin = IC2_SER_Pin_t;
	IC2.SCK_GPIO = IC2_SCK_GPIO_t;
	IC2.SCK_Pin = IC2_SCK_Pin_t;
	IC2.RCK_GPIO  = IC2_RCK_GPIO_t;
	IC2.RCK_Pin = IC2_RCK_Pin_t;
	
	_74HC595_Init(&IC1);
	_74HC595_Init(&IC2);
	
}

void MatrixLED_cls(){
	_74HC595_WriteWORD(&IC1,0x0000);
	_74HC595_WriteWORD(&IC2,0x0000);
}


void MatrixLED_ShowRow(uint8_t r,uint16_t Data){
	_74HC595_WriteWORD(&IC1,0x8000>>(r-1));
	_74HC595_WriteWORD(&IC2,~Data);

}
void ShowByteArray(uint8_t *arr,uint8_t BytePerRow,uint8_t position){//从零开始
	uint8_t i;
	for(i = 0 ; i<16;i++){//扫描行
		uint16_t cur = arr[BytePerRow*i+position/8]<<(8-position%8) | arr[BytePerRow*i+position/8 + 1]>>(position%8);
		_74HC595_WriteWORD(&IC1,0x8000>>(i));
		_74HC595_WriteWORD(&IC2,~cur);
		Delay_ms(1);
		_74HC595_WriteWORD(&IC2,~0x0000);
	}
}

void ShowArray(uint16_t *arr){
/*逐行扫描*/
	uint8_t i;
	for(i = 0 ; i<16;i++){
		_74HC595_WriteWORD(&IC1,0x8000>>(i));
		_74HC595_WriteWORD(&IC2,~arr[i]);
		Delay_ms(1);
		_74HC595_WriteWORD(&IC2,~0x0000);
	}
}

void Show2DArray(uint8_t **arr){
/*逐行扫描*/
	uint8_t i,j;
	static uint16_t time = 0;
	time++;
	for(i = 0 ; i<16;i++){
		unsigned int line = 0;
		for(j = 0;j<16;j++){
			line = line*2 + *((uint8_t*)arr+i*16+j);
		}
		_74HC595_WriteWORD(&IC1,0x8000>>(i));
		_74HC595_WriteWORD(&IC2,~line);
		if(time==999){
		time = 0;
		}
		Delay_ms(1);
		_74HC595_WriteWORD(&IC2,~0x0000);
		
	}
}
