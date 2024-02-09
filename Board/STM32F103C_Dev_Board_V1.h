#ifndef __STM32F103C_DEV_BOARD_V1
#define __STM32F103C_DEV_BOARD_V1
#include "stm32f10x.h"
#include "OLED.h"

//STM32F103C_Dev_Board_V1.h

extern OLED_SPI OLED1;
extern OLED_SPI OLED2;
extern OLED_SPI OLED3;
extern OLED_SPI OLED4;

void STM32F103C_Dev_Board_Init(void);

#endif
