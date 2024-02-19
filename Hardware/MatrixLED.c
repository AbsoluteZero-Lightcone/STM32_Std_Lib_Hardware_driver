#include "STM32Device.h"
#include "74HC595.h"
#include "Delay.h"
#include "MatrixLED.h"





void MatrixLED_Init(MatrixLED_TypeDef *MatrixLED_t)
{
//	
//	ROW.SER_GPIO = ROW_SER_GPIO_t;
//	ROW.SER_Pin = ROW_SER_Pin_t;
//	ROW.SCK_GPIO = ROW_SCK_GPIO_t;
//	ROW.SCK_Pin = ROW_SCK_Pin_t;
//	ROW.RCK_GPIO  = ROW_RCK_GPIO_t;
//	ROW.RCK_Pin = ROW_RCK_Pin_t;
//	
//	COL.SER_GPIO = COL_SER_GPIO_t;
//	COL.SER_Pin = COL_SER_Pin_t;
//	COL.SCK_GPIO = COL_SCK_GPIO_t;
//	COL.SCK_Pin = COL_SCK_Pin_t;
//	COL.RCK_GPIO  = COL_RCK_GPIO_t;
//	COL.RCK_Pin = COL_RCK_Pin_t;
//	
	
	_74HC595_Init(&MatrixLED_t->ROW);
	_74HC595_Init(&MatrixLED_t->COL);
	
}

void MatrixLED_cls(MatrixLED_TypeDef *MatrixLED_t){
	_74HC595_WriteWORD(&MatrixLED_t->ROW,0x0000);
	_74HC595_WriteWORD(&MatrixLED_t->COL,0x0000);
}


void MatrixLED_ShowRow(MatrixLED_TypeDef *MatrixLED_t,uint8_t r,uint16_t Data){
	_74HC595_WriteWORD(&MatrixLED_t->ROW,0x8000>>(r-1));
	_74HC595_WriteWORD(&MatrixLED_t->COL,~Data);

}
void ShowByteArray(MatrixLED_TypeDef *MatrixLED_t,uint8_t *arr,uint8_t BytePerRow,uint8_t position){//从零开始
	uint8_t i;
	for(i = 0 ; i<16;i++){//扫描行
		uint16_t cur = arr[BytePerRow*i+position/8]<<(8-position%8) | arr[BytePerRow*i+position/8 + 1]>>(position%8);
		_74HC595_WriteWORD(&MatrixLED_t->ROW,0x8000>>(i));
		_74HC595_WriteWORD(&MatrixLED_t->COL,~cur);
		Delay_ms(1);
		_74HC595_WriteWORD(&MatrixLED_t->COL,~0x0000);
	}
}

void ShowArray(MatrixLED_TypeDef *MatrixLED_t,uint16_t *arr){
/*逐行扫描*/
	uint8_t i;
	for(i = 0 ; i<16;i++){
		_74HC595_WriteWORD(&MatrixLED_t->ROW,0x8000>>(i));
		_74HC595_WriteWORD(&MatrixLED_t->COL,~arr[i]);
		Delay_ms(1);
		_74HC595_WriteWORD(&MatrixLED_t->COL,~0x0000);
	}
}

void Show2DArray(MatrixLED_TypeDef *MatrixLED_t,uint8_t **arr){
/*逐行扫描*/
	uint8_t i,j;
	static uint16_t time = 0;
	time++;
	for(i = 0 ; i<16;i++){
		unsigned int line = 0;
		for(j = 0;j<16;j++){
			line = line*2 + *((uint8_t*)arr+i*16+j);
		}
		_74HC595_WriteWORD(&MatrixLED_t->ROW,0x8000>>(i));
		_74HC595_WriteWORD(&MatrixLED_t->COL,~line);
		if(time==999){
		time = 0;
		}
		Delay_ms(1);
		_74HC595_WriteWORD(&MatrixLED_t->COL,~0x0000);
		
	}
}
