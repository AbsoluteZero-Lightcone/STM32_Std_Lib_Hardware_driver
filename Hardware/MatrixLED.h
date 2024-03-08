#ifndef __MATRIX_LED_H
#define __MATRIX_LED_H
#include "STM32Device.h"
#include "74HC595.h"
typedef struct{
	_74HC595_TypeDef ROW,COL;
} MatrixLED_TypeDef;


void MatrixLED_Init(MatrixLED_TypeDef *MatrixLED_t);

void MatrixLED_cls(MatrixLED_TypeDef *MatrixLED_t);

void MatrixLED_ShowRow(MatrixLED_TypeDef *MatrixLED_t,uint8_t r,uint16_t Data);
void ShowByteArray(MatrixLED_TypeDef *MatrixLED_t,uint8_t *arr,uint8_t BytePerRow,uint8_t position);
void ShowArray(MatrixLED_TypeDef *MatrixLED_t,uint16_t *arr);

void Show2DArray(MatrixLED_TypeDef *MatrixLED_t,uint8_t **arr);
/*
		MatrixLED_TypeDef MatrixLED_1;
	setPowerPin(GPIOB,GPIO_Pin_11,1);
	MatrixLED_1.ROW.SER_GPIO	= GPIOB;
	MatrixLED_1.ROW.SER_Pin		= GPIO_Pin_10;
	MatrixLED_1.ROW.SCK_GPIO	= GPIOB;
	MatrixLED_1.ROW.SCK_Pin		= GPIO_Pin_1;
	MatrixLED_1.ROW.RCK_GPIO	= GPIOB;
	MatrixLED_1.ROW.RCK_Pin		= GPIO_Pin_0;
	setPowerPin(GPIOA,GPIO_Pin_7,0);
	MatrixLED_1.COL.SER_GPIO	= GPIOA;
	MatrixLED_1.COL.SER_Pin		= GPIO_Pin_6;
	MatrixLED_1.COL.SCK_GPIO	= GPIOA;
	MatrixLED_1.COL.SCK_Pin		= GPIO_Pin_5;
	MatrixLED_1.COL.RCK_GPIO	= GPIOA;
	MatrixLED_1.COL.RCK_Pin		= GPIO_Pin_4;
	
	MatrixLED_Init(&MatrixLED_1);
*/

#endif
