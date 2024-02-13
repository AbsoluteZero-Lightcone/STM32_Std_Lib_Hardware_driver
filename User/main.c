#include "stm32f10x.h"
#include "STM32F103C_Dev_Board_V1.h"
#include "Delay.h"
#include "Pin_Config.h"

#include "TIM_PWM.h"
#include "TIM_Time.h"

int main(){
	STM32F103C_Dev_Board_Init();
	//OLED_ShowString(&OLED1,2,1,"Hello World!");
	OLED_ShowString(&OLED1,1,1,"OLED1");
	OLED_ShowString(&OLED2,1,1,"OLED2");
	OLED_ShowString(&OLED3,1,1,"OLED3");
	OLED_ShowString(&OLED4,1,1,"OLED4");
	
	setFloatingPin(GPIOC,GPIO_Pin_13);
	
	DisableJTAG();
	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	
	setInputPullUpPin(GPIOB,GPIO_Pin_8);
	
	Simple_PWM_TypeDef Simple_PWM_InitStruct;
	Simple_PWM_InitStruct.duty = 0.5;
	Simple_PWM_InitStruct.freq = 10000;
	Simple_PWM_InitStruct.GPIO = GPIOA;
	Simple_PWM_InitStruct.Pin = GPIO_Pin_15;
	Simple_PWM_InitStruct.precision = 0.001;
	Simple_PWM_InitStruct.TIMx = TIM2;
	Simple_PWM_ParamUpdate(&Simple_PWM_InitStruct);
	Simple_PWM_Init(&Simple_PWM_InitStruct);
	
	
	
	uint16_t i= 0;
	uint8_t direction = 1;
	while(1){
		OLED_ShowNum(&OLED1,3,1,i,10);
		OLED_ShowNum(&OLED2,2,1,i,10);
		OLED_ShowNum(&OLED3,3,1,i,10);
		OLED_ShowNum(&OLED4,4,1,i,10);
		TIM_SetCompare1(TIM2,i);
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0){
			if(direction){
				i+=100;
				if(i >= Simple_PWM_InitStruct.PWM_ARR){
					direction = 0;
				}
			}else{
				i-=100;
				if(i == 0){
					direction  = 1;
				}
			}
			//Delay_ms(1);
			OLED_ShowNum(&OLED4,3,1,1111111111,10);
		}else OLED_ShowNum(&OLED4,3,1,0,10);
	}
}
