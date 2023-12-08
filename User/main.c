#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "74HC595.h"
#include "MatrixLED.h"
#include "Encoder.h"

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

int main(){
	
	Encoder_1.OutputA_GPIO = GPIOB;
	Encoder_1.OutputA_Pin = GPIO_Pin_8;
	Encoder_1.OutputB_GPIO = GPIOB;
	Encoder_1.OutputB_Pin = GPIO_Pin_9;
	Encoder_1.Button_GPIO = GPIOB;
	Encoder_1.Button_Pin = GPIO_Pin_0;
	
	Encoder_Init(&Encoder_1,NVIC_PriorityGroup_2);	
	
	Encoder_2.OutputA_GPIO = GPIOB;
	Encoder_2.OutputA_Pin = GPIO_Pin_8;
	Encoder_2.OutputB_GPIO = GPIOB;
	Encoder_2.OutputB_Pin = GPIO_Pin_9;
	Encoder_2.Button_GPIO = GPIOB;
	Encoder_2.Button_Pin = GPIO_Pin_0;
	
	Encoder_Init(&Encoder_2,NVIC_PriorityGroup_2);
	
	MatrixLED_Init(
		GPIOB, GPIO_Pin_11,	GPIOB, GPIO_Pin_10,	GPIOB, GPIO_Pin_1,
		GPIOA, GPIO_Pin_7,	GPIOA, GPIO_Pin_6,	GPIOA, GPIO_Pin_5);
	
	uint8_t cnt = 0;
	
	while(1){
		cnt += getIncrement(&Encoder_1);
		switch(cnt%3){
			case 0:
				ShowByteArray(arr1,2,0);
				break;
			case 1:
				ShowByteArray(arr2,2,0);
				break;
			case 2:
				ShowByteArray(arr3,2,0);
				break;
		}
//		for(int i = 0 ; i <100;i++)
//		ShowByteArray(arr1,2,0);
//		for(int i = 0 ; i <100;i++)
//		ShowByteArray(arr2,2,0);
//		for(int i = 0 ; i <100;i++)
//		ShowByteArray(arr3,2,0);
		
		
		
	}
	
	
}

void EXTI9_5_IRQHandler(void){
	Interrupt_Output_A(&Encoder_1);
	Interrupt_Output_B(&Encoder_1);
}

