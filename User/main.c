#include "stm32f10x.h"
#include "STM32F103C_Dev_Board_V1.h"
#include "Delay.h"
#include "Pin_Config.h"

#include "TIM_PWM.h"
#include "TIM_Time.h"
#include "TIM_InputCapture.h"

int main(){
	STM32F103C_Dev_Board_Init();
	
	SimpleEnableGPIO(GPIOC,GPIO_Pin_13,GPIO_Mode_IN_FLOATING);
	DisableJTAG();
	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	SimpleEnableGPIO(GPIOB,GPIO_Pin_8,GPIO_Mode_IPU);
	
	Simple_PWM_TypeDef Simple_PWM_InitStruct;
	Simple_PWM_InitStruct.duty = 0.0;
	Simple_PWM_InitStruct.freq = 1000;
	Simple_PWM_InitStruct.GPIO = GPIOA;
	Simple_PWM_InitStruct.Pin = GPIO_Pin_15;
	Simple_PWM_InitStruct.precision = 0.01;
	Simple_PWM_InitStruct.TIMx = TIM2;
	Simple_PWM_ParamUpdate(&Simple_PWM_InitStruct);
	Simple_PWM_Init(&Simple_PWM_InitStruct);
	
	Simple_TIM_PWMI_Init();
	
	OLED_ShowString(&OLED1,1,1,"OLED1:PWM Output");
		OLED_ShowString(&OLED1,2,1,"Freq:");
		OLED_ShowString(&OLED1,3,1,"Duty:");
	OLED_ShowString(&OLED2,1,1,"OLED2:OutputRAW");
		OLED_ShowString(&OLED2,2,1,"CCR:");
		OLED_ShowString(&OLED2,3,1,"CNT:");
		OLED_ShowString(&OLED2,4,1,"PSC:");OLED_ShowNum(&OLED2,4,5,Simple_PWM_InitStruct.PWM_PSC,4);
		OLED_ShowString(&OLED2,4,9,"ARR:");OLED_ShowNum(&OLED2,4,13,Simple_PWM_InitStruct.PWM_ARR,4);
	OLED_ShowString(&OLED3,1,1,"OLED3:PWMI");
		OLED_ShowString(&OLED3,2,1,"Freq:");
		OLED_ShowString(&OLED3,3,1,"Duty:");
	OLED_ShowString(&OLED4,1,1,"OLED4:CaptureRAW");
		OLED_ShowString(&OLED4,2,1,"IC1CCR:");
		OLED_ShowString(&OLED4,3,1,"IC2CCR:");
		OLED_ShowString(&OLED4,4,1,"CNT:");
	uint16_t i= 0;
	uint8_t direction = 1;
	while(1){
		OLED_ShowNum(&OLED1,2,6,Simple_PWM_InitStruct.freq,7);
		OLED_ShowNum(&OLED1,3,6,(uint32_t)(TIM_GetCapture1(TIM2)*1.0/Simple_PWM_InitStruct.PWM_ARR*100),2);
		OLED_ShowNum(&OLED2,2,5,TIM_GetCapture1(TIM2),7);
		OLED_ShowNum(&OLED2,3,5,TIM_GetCounter(TIM2),7);
		OLED_ShowNum(&OLED3,2,6,(uint32_t)(Simple_TIM_PWMI_getFreq()+0.5),7);
		OLED_ShowNum(&OLED3,3,6,(uint32_t)((Simple_TIM_PWMI_getDuty()*100+0.5)),2);
		OLED_ShowNum(&OLED4,2,8,TIM_GetCapture1(TIM3),7);
		OLED_ShowNum(&OLED4,3,8,TIM_GetCapture2(TIM3),7);
		OLED_ShowNum(&OLED4,4,8,TIM_GetCounter(TIM3),7);
		TIM_SetCompare1(TIM2,i);
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0){
			if(direction){
				i+=1;
				if(i >= Simple_PWM_InitStruct.PWM_ARR){
					direction = 0;
				}
			}else{
				i-=1;
				if(i == 0){
					direction  = 1;
				}
			}
			//Delay_ms(1);
			OLED_ShowString(&OLED1,4,1,			"TIM2CCR Updating");
		}else OLED_ShowString(&OLED1,4,1,	" TIM2CCR Frozen ");
	}
}
