/**
  ******************************************************************************
  * @file    STM32F103C_Dev_Board_V1.h
  * @author  Lightcone
  * @version V1.3.2
  * @date    2024-03-02
  * @brief   STM32F103C开发板驱动库
  ******************************************************************************
  */
#ifndef __STM32F103C_DEV_BOARD_V1
#define __STM32F103C_DEV_BOARD_V1
#include "STM32Device.h"
#include "OLED.h"

//STM32F103C_Dev_Board_V1.h
#define Board_SPI_SCK_GPIO	GPIOA
#define Board_SPI_SCK_Pin	GPIO_Pin_7
#define Board_SPI_SDA_GPIO	GPIOA
#define Board_SPI_SDA_Pin	GPIO_Pin_5
#define Board_SPI_DC_GPIO	GPIOB
#define Board_SPI_DC_Pin	GPIO_Pin_10

extern OLED_SPI OLED1;
extern OLED_SPI OLED2;
extern OLED_SPI OLED3;
extern OLED_SPI OLED4;
extern OLED_SPI OLED5;

extern uint16_t (*readPotentiometer)(uint8_t ADC_Channel_x);
// 本库是为开发板板载资源编写，电位器是固定的资源但是可以通过多种不同的ADC模式进行读取
// 因为ADC资源较少，ADC库中的函数是分别给每个ADC写的
// 这个Handler提供了一个选择ADC的方法，需要哪种ADC模式回调哪种函数即可

void STM32F103C_Dev_Board_Init(void);

// Hardware config
void LED_PC13(FunctionalState x);

// DEMOs
void displayPotentiometer(void);
void displayPWMIO(void);


#endif

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
