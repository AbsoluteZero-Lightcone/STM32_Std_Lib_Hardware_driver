#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "74HC595.h"
#include "MatrixLED.h"
#include "Encoder.h"
#include "EXTI_Trigger.h"

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

	EXTI_Trigger_1.GPIO = GPIOB;
	EXTI_Trigger_1.Pin = GPIO_Pin_5;
	EXTI_Trigger_1.EXTIMode = EXTI_Mode_Interrupt;
	EXTI_Trigger_1.EXTITrigger = EXTI_Trigger_Rising_Falling;
	EXTI_Trigger_1.NVIC_IRQChannelPreemptionPriority = 0;
	EXTI_Trigger_1.NVIC_IRQChannelSubPriority = 0; 

	EXTI_Trigger_Init(&EXTI_Trigger_1,NVIC_PriorityGroup_2);
	
	
	
	Encoder_1.OutputA_GPIO = GPIOB;
	Encoder_1.OutputA_Pin = GPIO_Pin_8;
	Encoder_1.OutputB_GPIO = GPIOB;
	Encoder_1.OutputB_Pin = GPIO_Pin_9;
	Encoder_1.Button_GPIO = GPIOB;
	Encoder_1.Button_Pin = GPIO_Pin_0;
	
	Encoder_Init(&Encoder_1,NVIC_PriorityGroup_2);	
	
	
	
	Encoder_2.OutputA_GPIO = GPIOB;
	Encoder_2.OutputA_Pin = GPIO_Pin_6;
	Encoder_2.OutputB_GPIO = GPIOB;
	Encoder_2.OutputB_Pin = GPIO_Pin_7;
	Encoder_2.Button_GPIO = GPIOB;
	Encoder_2.Button_Pin = GPIO_Pin_0;
	
	Encoder_Init(&Encoder_2,NVIC_PriorityGroup_2);
	
	
	
	MatrixLED_TypeDef MatrixLED_1;
	
	MatrixLED_1.ROW.SER_GPIO = GPIOB;
	MatrixLED_1.ROW.SER_Pin = GPIO_Pin_11;
	MatrixLED_1.ROW.SCK_GPIO = GPIOB;
	MatrixLED_1.ROW.SCK_Pin = GPIO_Pin_10;
	MatrixLED_1.ROW.RCK_GPIO = GPIOB;
	MatrixLED_1.ROW.RCK_Pin = GPIO_Pin_1;
	MatrixLED_1.COL.SER_GPIO = GPIOA;
	MatrixLED_1.COL.SER_Pin = GPIO_Pin_7;
	MatrixLED_1.COL.SCK_GPIO = GPIOA;
	MatrixLED_1.COL.SCK_Pin = GPIO_Pin_6;
	MatrixLED_1.COL.RCK_GPIO = GPIOA;
	MatrixLED_1.COL.RCK_Pin = GPIO_Pin_5;
	
	MatrixLED_Init(&MatrixLED_1);


	
	while(1){
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
void func(void){
	cnt++;
}

void EXTI9_5_IRQHandler(void){
	Interrupt_Output_A_Detect_Handler(&Encoder_1);
	Interrupt_Output_B_Detect_Handler(&Encoder_1);
	Interrupt_Output_A_Detect_Handler(&Encoder_2);
	Interrupt_Output_B_Detect_Handler(&Encoder_2);
	EXTI_Trigger_Detect_Handler(&EXTI_Trigger_1,func);
}

