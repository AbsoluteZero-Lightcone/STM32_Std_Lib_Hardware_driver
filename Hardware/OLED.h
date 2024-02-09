#ifndef __OLED_H
#define __OLED_H
#include "stm32f10x.h"                  // Device header



typedef struct{
	GPIO_TypeDef* D0_GPIO;	uint16_t D0_Pin;
	GPIO_TypeDef* D1_GPIO;	uint16_t D1_Pin;
	GPIO_TypeDef* RES_GPIO;	uint16_t RES_Pin;
	GPIO_TypeDef* DC_GPIO;	uint16_t DC_Pin;
	GPIO_TypeDef* CS_GPIO;	uint16_t CS_Pin;
	void (*CS_Handler)(void);
} OLED_SPI;

/*
		OLED_SPI OLED1;
	// 标准顺序引脚89
	setPowerPin(GPIOB,GPIO_Pin_12,0);
	setPowerPin(GPIOB,GPIO_Pin_13,1);
	OLED1.D0_GPIO	= GPIOB;
	OLED1.D0_Pin	= GPIO_Pin_14;
	OLED1.D1_GPIO	= GPIOB;
	OLED1.D1_Pin	= GPIO_Pin_15;
	OLED1.RES_GPIO	= GPIOA;
	OLED1.RES_Pin	= GPIO_Pin_8;
	OLED1.DC_GPIO	= GPIOA;
	OLED1.DC_Pin	= GPIO_Pin_9;
	OLED1.CS_GPIO	= GPIOA;
	OLED1.CS_Pin	= GPIO_Pin_10;
	OLED_Init(&OLED1);
	OLED_ShowString(&OLED1,1,1,"HELLO WORLD!");


		OLED_SPI OLED2;
	OLED2.RES_GPIO	= GPIOG;
	OLED2.RES_Pin	= GPIO_Pin_0;
	// 排线顺序引脚 灰紫蓝绿
	OLED2.D1_GPIO	= GPIOB;
	OLED2.D1_Pin	= GPIO_Pin_12;
	OLED2.D0_GPIO	= GPIOB;
	OLED2.D0_Pin	= GPIO_Pin_13;
	OLED2.DC_GPIO	= GPIOB;
	OLED2.DC_Pin	= GPIO_Pin_14;
	OLED2.CS_GPIO	= GPIOB;
	OLED2.CS_Pin	= GPIO_Pin_15;
	setPowerPin(GPIOA,GPIO_Pin_8,1);
	setPowerPin(GPIOA,GPIO_Pin_9,0);
	OLED_Init(&OLED2);
	
	OLED_ShowString(&OLED2,1,1,"HELLO WORLD!!!");
	
		OLED_SPI OLED3;
	
	// 排线顺序引脚 绿蓝紫灰
	OLED3.RES_GPIO	= GPIOG;
	OLED3.RES_Pin	= GPIO_Pin_0;

	OLED3.CS_GPIO	= GPIOA;
	OLED3.CS_Pin	= GPIO_Pin_11;
	OLED3.DC_GPIO	= GPIOA;
	OLED3.DC_Pin	= GPIO_Pin_10;
	OLED3.D0_GPIO	= GPIOA;
	OLED3.D0_Pin	= GPIO_Pin_9;
	OLED3.D1_GPIO	= GPIOA;
	OLED3.D1_Pin	= GPIO_Pin_8;
	OLED_Init(&OLED3);
	OLED_ShowString(&OLED3,1,1,"HELLO WORLD!!!");
	
	
	// Absolute Zero Studio 开发板
		OLED_SPI OLED1;
	//总线部分：
	OLED1.D0_GPIO	= GPIOA;		//SCK
	OLED1.D0_Pin	= GPIO_Pin_5;
	OLED1.D1_GPIO	= GPIOA;		//SDA
	OLED1.D1_Pin	= GPIO_Pin_7;
	OLED1.RES_GPIO	= GPIOG;		//不存在
	OLED1.RES_Pin	= GPIO_Pin_0;
	OLED1.DC_GPIO	= GPIOB;
	OLED1.DC_Pin	= GPIO_Pin_10;
	//片选部分：
	OLED1.CS_GPIO	= GPIOB;
	OLED1.CS_Pin	= GPIO_Pin_11;
	//初始化：
	OLED_Init(&OLED1);
	OLED_ShowString(&OLED1,1,1,"OLED1");
	OLED_ShowString(&OLED1,2,1,"HELLO WORLD!");
	
		OLED_SPI OLED2;
	//总线部分：
	OLED1.D0_GPIO	= GPIOA;		//SCK
	OLED1.D0_Pin	= GPIO_Pin_5;
	OLED1.D1_GPIO	= GPIOA;		//SDA
	OLED1.D1_Pin	= GPIO_Pin_7;
	OLED1.RES_GPIO	= GPIOG;		//不存在
	OLED1.RES_Pin	= GPIO_Pin_0;
	OLED1.DC_GPIO	= GPIOB;
	OLED1.DC_Pin	= GPIO_Pin_10;
	//片选部分：
	OLED1.CS_GPIO	= GPIOB;
	OLED1.CS_Pin	= GPIO_Pin_12;
	//初始化：
	OLED_Init(&OLED2);
	OLED_ShowString(&OLED2,1,1,"OLED2");
	OLED_ShowString(&OLED2,2,1,"HELLO WORLD!");
	
		OLED_SPI OLED3;
	//总线部分：
	OLED1.D0_GPIO	= GPIOA;		//SCK
	OLED1.D0_Pin	= GPIO_Pin_5;
	OLED1.D1_GPIO	= GPIOA;		//SDA
	OLED1.D1_Pin	= GPIO_Pin_7;
	OLED1.RES_GPIO	= GPIOG;		//不存在
	OLED1.RES_Pin	= GPIO_Pin_0;
	OLED1.DC_GPIO	= GPIOB;
	OLED1.DC_Pin	= GPIO_Pin_10;
	//片选部分：
	OLED1.CS_GPIO	= GPIOB;
	OLED1.CS_Pin	= GPIO_Pin_13;
	//初始化：
	OLED_Init(&OLED3);
	OLED_ShowString(&OLED3,1,1,"OLED3");
	OLED_ShowString(&OLED3,2,1,"HELLO WORLD!");
	
		OLED_SPI OLED4;
	//总线部分：
	OLED1.D0_GPIO	= GPIOA;		//SCK
	OLED1.D0_Pin	= GPIO_Pin_5;
	OLED1.D1_GPIO	= GPIOA;		//SDA
	OLED1.D1_Pin	= GPIO_Pin_7;
	OLED1.RES_GPIO	= GPIOG;		//不存在
	OLED1.RES_Pin	= GPIO_Pin_0;
	OLED1.DC_GPIO	= GPIOB;
	OLED1.DC_Pin	= GPIO_Pin_10;
	//片选部分：
	OLED1.CS_GPIO	= GPIOB;
	OLED1.CS_Pin	= GPIO_Pin_14;
	//初始化：
	OLED_Init(&OLED4);
	OLED_ShowString(&OLED4,1,1,"OLED4");
	OLED_ShowString(&OLED4,2,1,"HELLO WORLD!");
	
	
	*/


void OLED_Init(OLED_SPI* OLED_SPI_Struct);
void OLED_Clear(OLED_SPI* OLED_SPI_Struct);
void OLED_ShowChar(OLED_SPI* OLED_SPI_Struct,uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(OLED_SPI* OLED_SPI_Struct,uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(OLED_SPI* OLED_SPI_Struct,uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(OLED_SPI* OLED_SPI_Struct,uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(OLED_SPI* OLED_SPI_Struct,uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(OLED_SPI* OLED_SPI_Struct,uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
