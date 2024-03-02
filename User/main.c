/**
  ******************************************************************************
  * @file    main.c
  * @author  Lightcone
  * @date    2024-02-23
  * @brief   STM32F10x 入口函数
  ******************************************************************************
  */

// Includes
#include "STM32Device.h"
#include "STM32F103C_Dev_Board_V1.h"
int main(){
	OLED_ShowString(&OLED5,1,1,"123");
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
