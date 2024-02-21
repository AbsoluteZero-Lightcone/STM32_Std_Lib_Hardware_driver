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

void STM32F103C_Dev_Board_Init(void);

#endif
