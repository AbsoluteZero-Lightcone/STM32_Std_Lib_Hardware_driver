/**
  ******************************************************************************
  * @file    main.c
  * @author  Lightcone
  * @date    2024-03-19
  * @brief   STM32F10x 入口函数
  ******************************************************************************
  */

// Includes
#include "STM32F103C_Dev_Board_V1.h"
#include "Sensor_DHT11.h"
#include "Servo_SG90.h"
#include "math.h"
#include "UART.h"
#include <stdlib.h>

int main(){
	STM32F103C_Dev_Board_Init();
	Serial_Init(9600);
	//Servo_SG90_Demo();
	//DHT11_Demo();
	//LED_PC13(ENABLE);
	uint64_t i = 0;
	while(1){
		i++;
		Serial_SendString("Hello World!\n");
		Serial_SendNum(1234567890);Serial_EndLine();
		Serial_SendHexNum(0x1234567890ABCDEF);Serial_EndLine();
		Serial_SendBinNum(0x1234567890ABCDEF);Serial_EndLine();
		Serial_EndLine();
		Delay_ms(1000);
		//Serial_SendData(i);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],1,1,i,16);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED2],2,1,log(i),16);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED3],3,1,exp(i),16);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED4],4,1,pow(i,i),16);
	}
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
