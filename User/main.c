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
void DHT11_Demo(){
	STM32F103C_Dev_Board_Init();
	OLED_ShowString(&OLED5,1,1,"Humidity:");
	OLED_ShowString(&OLED5,2,1,"  .  %RH");
	OLED_ShowString(&OLED5,3,1,"Temperature:");
	OLED_ShowString(&OLED5,4,1,"   .  ");
	DHT11_TypeDef DHT11_1;
	DHT11_1.GPIO = GPIOC;
	DHT11_1.Pin = GPIO_Pin_13;
	DHT11_Init(&DHT11_1);
	while(1){
		DHT11_updateData(&DHT11_1);
		OLED_ShowNum(&OLED5,2,1,DHT11_1.Humidity_H,2);
		OLED_ShowNum(&OLED5,2,4,DHT11_1.Humidity_L,2);
		//且温度低位 Bit8 为 1 则表示负温度，否则为正温度
		if(DHT11_1.Temperature_L&0x10000000)OLED_ShowString(&OLED5,4,1,"-");
		else OLED_ShowString(&OLED5,4,1,"+");
		OLED_ShowNum(&OLED5,4,2,DHT11_1.Temperature_H,2);
		OLED_ShowNum(&OLED5,4,5,DHT11_1.Temperature_L&0x01111111,2);
	}
}


int main(){
	STM32F103C_Dev_Board_Init();
	DHT11_Demo();
	LED_PC13(ENABLE);
	OLED_ShowString(&OLED5,1,1,"Hello World!");
	OLED_ShowString(&OLED5,2,1,"123");
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
