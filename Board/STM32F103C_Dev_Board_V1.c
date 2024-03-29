/**
  ******************************************************************************
  * @file    STM32F103C_Dev_Board_V1.c
  * @author  Lightcone
  * @version V2.1.1
  * @date    2024-03-16
  * @brief   STM32F103C开发板驱动库
  ******************************************************************************
  */
#include "STM32Device.h"
#include "STM32F103C_Dev_Board_V1.h"
#include "OLED.h"
#include "74HC138.h"

#include "ADC.h"
// STM32F103C_Dev_Board_V1

uint16_t (*readPotentiometer)(uint8_t ADC_Channel_x) = get_Simple_ADC1_Single_Channel_Value;

/** @defgroup SPI_CS 74HC138 config
  * @{
  */ 
_74HC138_TypeDef CS_74HC138 = {
		.A_GPIO=GPIOB,.A_Pin=GPIO_Pin_11,
		.B_GPIO=GPIOB,.B_Pin=GPIO_Pin_12,
		.C_GPIO=GPIOB,.C_Pin=GPIO_Pin_13
	};
/**
  * @}
  */

/** @defgroup OLED Devices config
  * @{
  */ 
void OLED1_CS_Callback(){_74HC138_Write(&CS_74HC138,1);}
void OLED2_CS_Callback(){_74HC138_Write(&CS_74HC138,2);}
void OLED3_CS_Callback(){_74HC138_Write(&CS_74HC138,3);}
void OLED4_CS_Callback(){_74HC138_Write(&CS_74HC138,4);}
void OLED5_CS_Callback(){_74HC138_Write(&CS_74HC138,5);}
OLED_SPI Onboard_OLED[Enum_OLED_MAX] = {
	[Enum_OLED1] = {
		.D0_GPIO  = Board_SPI_SCK_GPIO,.D0_Pin = Board_SPI_SCK_Pin,
		.D1_GPIO  = Board_SPI_SDA_GPIO,.D1_Pin = Board_SPI_SDA_Pin,
		.DC_GPIO  = Board_SPI_DC_GPIO ,.DC_Pin = Board_SPI_DC_Pin,
		.RES_GPIO = GPIOG             ,.RES_Pin = GPIO_Pin_0,
		.CS_Handler = OLED1_CS_Callback
	},
	[Enum_OLED2] = {
		.D0_GPIO  = Board_SPI_SCK_GPIO,.D0_Pin = Board_SPI_SCK_Pin,
		.D1_GPIO  = Board_SPI_SDA_GPIO,.D1_Pin = Board_SPI_SDA_Pin,
		.DC_GPIO  = Board_SPI_DC_GPIO ,.DC_Pin = Board_SPI_DC_Pin,
		.RES_GPIO = GPIOG             ,.RES_Pin = GPIO_Pin_0,
		.CS_Handler = OLED2_CS_Callback
	},
	[Enum_OLED3] = {
		.D0_GPIO  = Board_SPI_SCK_GPIO,.D0_Pin = Board_SPI_SCK_Pin,
		.D1_GPIO  = Board_SPI_SDA_GPIO,.D1_Pin = Board_SPI_SDA_Pin,
		.DC_GPIO  = Board_SPI_DC_GPIO ,.DC_Pin = Board_SPI_DC_Pin,
		.RES_GPIO = GPIOG             ,.RES_Pin = GPIO_Pin_0,
		.CS_Handler = OLED3_CS_Callback
	},
	[Enum_OLED4] = {
		.D0_GPIO  = Board_SPI_SCK_GPIO,.D0_Pin = Board_SPI_SCK_Pin,
		.D1_GPIO  = Board_SPI_SDA_GPIO,.D1_Pin = Board_SPI_SDA_Pin,
		.DC_GPIO  = Board_SPI_DC_GPIO ,.DC_Pin = Board_SPI_DC_Pin,
		.RES_GPIO = GPIOG             ,.RES_Pin = GPIO_Pin_0,
		.CS_Handler = OLED4_CS_Callback
	},
	[Enum_OLED5] = {
		.D0_GPIO  = Board_SPI_SCK_GPIO,.D0_Pin = Board_SPI_SCK_Pin,
		.D1_GPIO  = Board_SPI_SDA_GPIO,.D1_Pin = Board_SPI_SDA_Pin,
		.DC_GPIO  = Board_SPI_DC_GPIO ,.DC_Pin = Board_SPI_DC_Pin,
		.RES_GPIO = GPIOB             ,.RES_Pin = GPIO_Pin_9,
		.CS_Handler = OLED5_CS_Callback
	},
};
/**
  * @}
  */

void STM32F103C_Dev_Board_Init(){
	//74HC138 Init
	_74HC138_Init(&CS_74HC138);
	//ADC1 Init
	Simple_ADC1_Single_Channel_Init();
	//Init all OLEDs
	for(int i = 0;i<Enum_OLED_MAX;i++){
		OLED_Init(&Onboard_OLED[i]);
	}
	
}

// DEMOs


void displayPotentiometer(){
	STM32F103C_Dev_Board_Init();
	
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],1,1,"ADC Convert");
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],2,1,"ADC_DR=");
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],3,1,"Voltage= .    V");
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],4,1,"Percent=  .   %");

	uint16_t ADC_DR;
	double Voltage;
	double Percentage;

	while(1){
		ADC_DR = readPotentiometer(ADC_Channel_0);
		Voltage = ADC_DR/4096.0*3.3;
		Percentage = ADC_DR/4095.0*100;
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],2,8,ADC_DR,4);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],3,9,(uint16_t)(Voltage),1);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],3,11,(uint16_t)(Voltage*10000+0.5)%10000,4);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],4,9,(uint16_t)(Percentage),2);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],4,12,(uint16_t)(Percentage*1000+0.5)%1000,3);
	}
}




#include "TIM_PWM.h"
#include "TIM_Time.h"
#include "TIM_InputCapture.h"
void displayPWMIO(){
	STM32F103C_Dev_Board_Init();
	
	SimpleConfigGPIO(GPIOC,GPIO_Pin_13,GPIO_Mode_IN_FLOATING);
	DisableJTAG();
	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	SimpleConfigGPIO(GPIOB,GPIO_Pin_8,GPIO_Mode_IPU);
	
	Simple_PWM_TypeDef Simple_PWM_InitStruct;
	Simple_PWM_InitStruct.duty = 0.0;
	Simple_PWM_InitStruct.freq = 1000;
	Simple_PWM_InitStruct.GPIO = GPIOA;
	Simple_PWM_InitStruct.Pin = GPIO_Pin_15;
	Simple_PWM_InitStruct.precision = 0.01;
	Simple_PWM_InitStruct.TIMx = TIM2;
	Simple_PWM_ParamUpdate(&Simple_PWM_InitStruct);
	Simple_PWM_Init(&Simple_PWM_InitStruct);
	
	Simple_TIM3_PWMI_Init();
	
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],1,1,"OLED1:PWM Output");
		OLED_ShowString(&Onboard_OLED[Enum_OLED1],2,1,"Freq:");
		OLED_ShowString(&Onboard_OLED[Enum_OLED1],3,1,"Duty:");
	OLED_ShowString(&Onboard_OLED[Enum_OLED2],1,1,"OLED2:OutputRAW");
		OLED_ShowString(&Onboard_OLED[Enum_OLED2],2,1,"CCR:");
		OLED_ShowString(&Onboard_OLED[Enum_OLED2],3,1,"CNT:");
		OLED_ShowString(&Onboard_OLED[Enum_OLED2],4,1,"PSC:");OLED_ShowNum(&Onboard_OLED[Enum_OLED2],4,5,Simple_PWM_InitStruct.PWM_PSC,4);
		OLED_ShowString(&Onboard_OLED[Enum_OLED2],4,9,"ARR:");OLED_ShowNum(&Onboard_OLED[Enum_OLED2],4,13,Simple_PWM_InitStruct.PWM_ARR,4);
	OLED_ShowString(&Onboard_OLED[Enum_OLED3],1,1,"OLED3:PWMI");
		OLED_ShowString(&Onboard_OLED[Enum_OLED3],2,1,"Freq:");
		OLED_ShowString(&Onboard_OLED[Enum_OLED3],3,1,"Duty:");
	OLED_ShowString(&Onboard_OLED[Enum_OLED4],1,1,"OLED4:CaptureRAW");
		OLED_ShowString(&Onboard_OLED[Enum_OLED4],2,1,"IC1CCR:");
		OLED_ShowString(&Onboard_OLED[Enum_OLED4],3,1,"IC2CCR:");
		OLED_ShowString(&Onboard_OLED[Enum_OLED4],4,1,"CNT:");
	uint16_t i= 0;
	uint8_t direction = 1;
	while(1){
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],2,6,Simple_PWM_InitStruct.freq,7);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],3,6,(uint32_t)(TIM_GetCapture1(TIM2)*1.0/Simple_PWM_InitStruct.PWM_ARR*100),2);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED2],2,5,TIM_GetCapture1(TIM2),7);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED2],3,5,TIM_GetCounter(TIM2),7);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED3],2,6,(uint32_t)(Simple_TIM_PWMI_getFreq()+0.5),7);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED3],3,6,(uint32_t)((Simple_TIM_PWMI_getDuty()*100+0.5)),2);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED4],2,8,TIM_GetCapture1(TIM3),7);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED4],3,8,TIM_GetCapture2(TIM3),7);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED4],4,8,TIM_GetCounter(TIM3),7);
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
			OLED_ShowString(&Onboard_OLED[Enum_OLED1],4,1,			"TIM2CCR Updating");
		}else OLED_ShowString(&Onboard_OLED[Enum_OLED1],4,1,	" TIM2CCR Frozen ");
	}
}


void LED_PC13(FunctionalState x){
	SimpleConfigGPIO(GPIOC,GPIO_Pin_13,GPIO_Mode_Out_PP);
	GPIO_WriteBit(GPIOC,GPIO_Pin_13,(BitAction)x);
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
