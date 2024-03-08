/**
  ******************************************************************************
  * @file    main.c
  * @author  Lightcone
  * @date    2024-02-23
  * @brief   STM32F10x 入口函数
  ******************************************************************************
  */

// Includes
#include "STM32F103C_Dev_Board_V1.h"
#include "Sensor_DHT11.h"


int main(){
	STM32F103C_Dev_Board_Init();
	DHT11_Demo();
	LED_PC13(ENABLE);
	OLED_ShowString(&OLED5,1,1,"Hello World!");
	OLED_ShowString(&OLED5,2,1,"123");
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
