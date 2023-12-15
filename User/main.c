#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "74HC595.h"
#include "MatrixLED.h"
#include "Encoder.h"
#include "EXTI_Trigger.h"
#include "PowerPin.h"

uint8_t arr1[32] = {
0x01,0x00,0xF9,0x08,0x09,0x08,0x09,0x10,0x09,0x20,0x79,0x40,0x41,0x00,0x47,0xFE,
0x41,0x40,0x79,0x20,0x09,0x20,0x09,0x10,0x09,0x08,0x09,0x44,0x51,0x82,0x21,0x00
};
uint8_t arr2[32] = {
0x02,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x04,0x40,0x04,0x40,0x24,0x50,0x24,0x48,
0x24,0x48,0x44,0x44,0x44,0x44,0x88,0x44,0x08,0x40,0x10,0x40,0x21,0x40,0x40,0x80
};
uint8_t arr3[32] = {
0x00,0x40,0x20,0x40,0x10,0x40,0x10,0x40,0x87,0xFC,0x40,0x40,0x40,0x40,0x10,0x40,
0x1F,0xFE,0x20,0x40,0xE0,0x80,0x21,0x00,0x22,0x10,0x24,0x08,0x2F,0xFC,0x04,0x04
};

Encoder_TypeDef Encoder_1;
Encoder_TypeDef Encoder_2;

EXTI_Trigger_TypeDef EXTI_Trigger_1;
	
uint8_t cnt = 0;

int main(){

	EXTI_Trigger_1.GPIO = GPIOA;
	EXTI_Trigger_1.Pin = GPIO_Pin_0;
	EXTI_Trigger_1.EXTIMode = EXTI_Mode_Interrupt;
	EXTI_Trigger_1.EXTITrigger = EXTI_Trigger_Rising_Falling;
	EXTI_Trigger_1.NVIC_IRQChannelPreemptionPriority = 0;
	EXTI_Trigger_1.NVIC_IRQChannelSubPriority = 0; 

	EXTI_Trigger_Init(&EXTI_Trigger_1,NVIC_PriorityGroup_2);
	
	
	
	Encoder_1.OutputA_GPIO	= GPIOA;
	Encoder_1.OutputA_Pin	= GPIO_Pin_3;
	setPowerPin(GPIOA,GPIO_Pin_2,0);
	Encoder_1.OutputB_GPIO	= GPIOA;
	Encoder_1.OutputB_Pin	= GPIO_Pin_1;
	Encoder_1.Button_GPIO	= GPIOG;
	Encoder_1.Button_Pin	= GPIO_Pin_0;
	
	Encoder_Init(&Encoder_1,NVIC_PriorityGroup_2);	
	
	
	
	Encoder_2.OutputA_GPIO	= GPIOC;
	Encoder_2.OutputA_Pin	= GPIO_Pin_15;
	setPowerPin(GPIOC,GPIO_Pin_14,0);
	Encoder_2.OutputB_GPIO	= GPIOC;
	Encoder_2.OutputB_Pin	= GPIO_Pin_13;
	Encoder_2.Button_GPIO	= GPIOG;
	Encoder_2.Button_Pin	= GPIO_Pin_0;
	
	Encoder_Init(&Encoder_2,NVIC_PriorityGroup_2);
	
	
	
		MatrixLED_TypeDef MatrixLED_1;
	setPowerPin(GPIOB,GPIO_Pin_11,1);
	MatrixLED_1.ROW.SER_GPIO	= GPIOB;
	MatrixLED_1.ROW.SER_Pin		= GPIO_Pin_10;
	MatrixLED_1.ROW.SCK_GPIO	= GPIOB;
	MatrixLED_1.ROW.SCK_Pin		= GPIO_Pin_1;
	MatrixLED_1.ROW.RCK_GPIO	= GPIOB;
	MatrixLED_1.ROW.RCK_Pin		= GPIO_Pin_0;
	setPowerPin(GPIOA,GPIO_Pin_7,0);
	MatrixLED_1.COL.SER_GPIO	= GPIOA;
	MatrixLED_1.COL.SER_Pin		= GPIO_Pin_6;
	MatrixLED_1.COL.SCK_GPIO	= GPIOA;
	MatrixLED_1.COL.SCK_Pin		= GPIO_Pin_5;
	MatrixLED_1.COL.RCK_GPIO	= GPIOA;
	MatrixLED_1.COL.RCK_Pin		= GPIO_Pin_4;
	
	MatrixLED_Init(&MatrixLED_1);



		OLED_SPI OLED1;
	OLED1.RES_GPIO	= GPIOG;
	OLED1.RES_Pin	= GPIO_Pin_0;
	// 排线顺序引脚 灰紫蓝绿
	OLED1.D1_GPIO	= GPIOB;
	OLED1.D1_Pin	= GPIO_Pin_12;
	OLED1.D0_GPIO	= GPIOB;
	OLED1.D0_Pin	= GPIO_Pin_13;
	OLED1.DC_GPIO	= GPIOB;
	OLED1.DC_Pin	= GPIO_Pin_14;
	OLED1.CS_GPIO	= GPIOB;
	OLED1.CS_Pin	= GPIO_Pin_15;
	setPowerPin(GPIOA,GPIO_Pin_8,1);
	setPowerPin(GPIOA,GPIO_Pin_9,0);
	OLED_Init(&OLED1);
	
			OLED_SPI OLED2;
	OLED2.RES_GPIO	= GPIOG;
	OLED2.RES_Pin	= GPIO_Pin_0;
	// 排线顺序引脚 灰紫蓝绿
	OLED2.D1_GPIO	= GPIOB;
	OLED2.D1_Pin	= GPIO_Pin_5;
	OLED2.D0_GPIO	= GPIOB;
	OLED2.D0_Pin	= GPIO_Pin_6;
	OLED2.DC_GPIO	= GPIOB;
	OLED2.DC_Pin	= GPIO_Pin_7;
	OLED2.CS_GPIO	= GPIOB;
	OLED2.CS_Pin	= GPIO_Pin_8;
	setPowerPin(GPIOB,GPIO_Pin_9,1);
	//setPowerPin(GPIOB,GPIO_Pin_4,0);
	OLED_Init(&OLED2);
	
	OLED_ShowString(&OLED1,1,1,"HELLO WORLD!!!");
	OLED_ShowString(&OLED2,1,1,"HELLO WORLD!!!");


	while(1){
		OLED_ShowNum(&OLED1,2,1,cnt,4);
		OLED_ShowNum(&OLED2,3,1,cnt,4);
		cnt += getIncrement(&Encoder_1);
		cnt += getIncrement(&Encoder_2);
		switch(cnt%3){
			case 0:
				ShowByteArray(&MatrixLED_1,arr1,2,0);
				break;
			case 1:
				ShowByteArray(&MatrixLED_1,arr2,2,0);
				break;
			case 2:
				ShowByteArray(&MatrixLED_1,arr3,2,0);
				break;
		}
		
	}
	
	
}

void func(void){cnt++;}
void EXTI0_IRQHandler(void){EXTI_Trigger_Detect_Handler(&EXTI_Trigger_1,func);}
void EXTI15_10_IRQHandler(void){Interrupt_Output_A_Detect_Handler(&Encoder_2);Interrupt_Output_B_Detect_Handler(&Encoder_2);}
void EXTI3_IRQHandler(void){Interrupt_Output_A_Detect_Handler(&Encoder_1);}
void EXTI1_IRQHandler(void){Interrupt_Output_B_Detect_Handler(&Encoder_1);}
