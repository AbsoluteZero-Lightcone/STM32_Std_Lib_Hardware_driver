/**
  ******************************************************************************
  * @file    STM32F103C_Dev_Board_V1.c
  * @author  Lightcone
  * @version V1.2.1
  * @date    2024-02-22
  * @brief   STM32F103C开发板驱动库
  ******************************************************************************
  */
#include "STM32Device.h"
#include "OLED.h"
#include "74HC138.h"
#include "STM32F103C_Dev_Board_V1.h"
#include "ADC.h"
// STM32F103C_Dev_Board_V1

uint16_t (*readPotentiometer)(uint8_t ADC_Channel_x) = get_Simple_ADC1_Single_Channel_Value;

// OLED*4
_74HC138_TypeDef CS_74HC138;
void OLED1_CS_Callback(){_74HC138_Write(&CS_74HC138,1);}
void OLED2_CS_Callback(){_74HC138_Write(&CS_74HC138,2);}
void OLED3_CS_Callback(){_74HC138_Write(&CS_74HC138,3);}
void OLED4_CS_Callback(){_74HC138_Write(&CS_74HC138,4);}
OLED_SPI OLED1;
OLED_SPI OLED2;
OLED_SPI OLED3;
OLED_SPI OLED4;

void STM32F103C_Dev_Board_Init(){
	//74HC138 Init
	CS_74HC138.A_GPIO=GPIOB;CS_74HC138.A_Pin=GPIO_Pin_11;
	CS_74HC138.B_GPIO=GPIOB;CS_74HC138.B_Pin=GPIO_Pin_12;
	CS_74HC138.C_GPIO=GPIOB;CS_74HC138.C_Pin=GPIO_Pin_13;
	_74HC138_Init(&CS_74HC138);

	//OLED1 Init
	OLED1.D0_GPIO = Board_SPI_SCK_GPIO;	OLED1.D0_Pin= Board_SPI_SCK_Pin;//SCK
	OLED1.D1_GPIO = Board_SPI_SDA_GPIO;	OLED1.D1_Pin= Board_SPI_SDA_Pin;//SDA
	OLED1.DC_GPIO = Board_SPI_DC_GPIO;	OLED1.DC_Pin= Board_SPI_DC_Pin;//DC
	OLED1.RES_GPIO = GPIOG;OLED1.RES_Pin= GPIO_Pin_0;//NC
	OLED1.CS_Handler= OLED1_CS_Callback;
	OLED_Init(&OLED1);
	//OLED2 Init
	OLED2.D0_GPIO = Board_SPI_SCK_GPIO;	OLED2.D0_Pin= Board_SPI_SCK_Pin;//SCK
	OLED2.D1_GPIO = Board_SPI_SDA_GPIO;	OLED2.D1_Pin= Board_SPI_SDA_Pin;//SDA
	OLED2.DC_GPIO = Board_SPI_DC_GPIO;	OLED2.DC_Pin= Board_SPI_DC_Pin;//DC
	OLED2.RES_GPIO = GPIOG;OLED2.RES_Pin= GPIO_Pin_0;//NC
	OLED2.CS_Handler= OLED2_CS_Callback;
	OLED_Init(&OLED2);
	//OLED3 Init
	OLED3.D0_GPIO = Board_SPI_SCK_GPIO;	OLED3.D0_Pin= Board_SPI_SCK_Pin;//SCK
	OLED3.D1_GPIO = Board_SPI_SDA_GPIO;	OLED3.D1_Pin= Board_SPI_SDA_Pin;//SDA
	OLED3.DC_GPIO = Board_SPI_DC_GPIO;	OLED3.DC_Pin= Board_SPI_DC_Pin;//DC
	OLED3.RES_GPIO = GPIOG;OLED3.RES_Pin= GPIO_Pin_0;//NC
	OLED3.CS_Handler= OLED3_CS_Callback;
	OLED_Init(&OLED3);
	//OLED4 Init
	OLED4.D0_GPIO = Board_SPI_SCK_GPIO;	OLED4.D0_Pin= Board_SPI_SCK_Pin;//SCK
	OLED4.D1_GPIO = Board_SPI_SDA_GPIO;	OLED4.D1_Pin= Board_SPI_SDA_Pin;//SDA
	OLED4.DC_GPIO = Board_SPI_DC_GPIO;	OLED4.DC_Pin= Board_SPI_DC_Pin;//DC
	OLED4.RES_GPIO = GPIOG;OLED4.RES_Pin= GPIO_Pin_0;//NC
	OLED4.CS_Handler= OLED4_CS_Callback;
	OLED_Init(&OLED4);
	
	//ADC1 Init
	Simple_ADC1_Single_Channel_Init();
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
