/**
  ******************************************************************************
  * @file    main.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-22
  * @brief   STM32F10x 入口函数
  ******************************************************************************
  */

// from demo .c file
extern int main_PWMIO(void);

// Includes
#include "STM32Device.h"
#include "STM32F103C_Dev_Board_V1.h"

#include "OLED.h"
int main(){
	STM32F103C_Dev_Board_Init();
	
	OLED_ShowString(&OLED1,1,1,"ADC Convert");
	OLED_ShowString(&OLED1,2,1,"ADC_DR=");
	OLED_ShowString(&OLED1,3,1,"Voltage= .    V");
	OLED_ShowString(&OLED1,4,1,"Percent=  .   %");

	uint16_t ADC_DR;
	float Voltage;
	float Percentage;

	while(1){
		ADC_DR = readPotentiometer();
		Voltage = ADC_DR/4096.0*3.3;
		Percentage = ADC_DR/4095.0*100;
		OLED_ShowNum(&OLED1,2,8,ADC_DR,4);
		OLED_ShowNum(&OLED1,3,9,(uint16_t)(Voltage+0.5),1);
		OLED_ShowNum(&OLED1,3,11,(uint16_t)(Voltage*10000+0.5)%10000,4);
		OLED_ShowNum(&OLED1,4,9,(uint16_t)(Percentage+0.5),2);
		OLED_ShowNum(&OLED1,4,12,(uint16_t)(Percentage*1000+0.5)%1000,3);
	}
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
