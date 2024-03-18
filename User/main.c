/**
  ******************************************************************************
  * @file    main.c
  * @author  Lightcone
  * @date    2024-02-23
  * @brief   STM32F10x 入口函数
  ******************************************************************************
  */

// Includes
//#include "STM32F103C_Dev_Board_V1.h"
//#include "Sensor_DHT11.h"
//#include "Servo_SG90.h"
//#include "math.h"

//int main(){
//	STM32F103C_Dev_Board_Init();
//	//Servo_SG90_Demo();
//	//DHT11_Demo();
//	LED_PC13(ENABLE);
//	uint64_t i = 0;
//	while(1){
//		i++;
//		OLED_ShowNum(&Onboard_OLED[Enum_OLED5],1,1,i,16);
//		OLED_ShowNum(&Onboard_OLED[Enum_OLED5],2,1,log(i),16);
//		OLED_ShowNum(&Onboard_OLED[Enum_OLED5],3,1,exp(i),16);
//		OLED_ShowNum(&Onboard_OLED[Enum_OLED5],4,1,pow(i,i),16);
//	}
//}
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin =GPIO_Pin_13 ;
	GPIO_InitStruct.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	while(1){
		Delay_ms(100);
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
	}
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
