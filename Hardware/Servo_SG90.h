/**
  ******************************************************************************
  * @file    Servo_SG90.h
  * @author  Lightcone
  * @version V1.0.3
  * @date    2024-03-11
  * @brief   STM32F10x SG90伺服电机驱动
  ******************************************************************************
  */

#ifndef __SERVO_SG90_H
#define __SERVO_SG90_H
#include "STM32Device.h"

typedef struct{
	GPIO_TypeDef* GPIO;
	uint16_t Pin;
	uint16_t degree_MAX;
	
	TIM_TypeDef* TIMx;//不用初始化
	void (*TIM_SetCompare_Callback)(TIM_TypeDef* TIMx, uint16_t Compare1);//不用初始化
	uint16_t degree;//不用初始化
}Servo_SG90;

void Servo_SG90_Init(Servo_SG90* Servo_x);
void Servo_SG90_Set_Degree(Servo_SG90* Servo_x,uint16_t degree);

void Servo_SG90_Demo(){
	Servo_SG90 Servo_1;
	Servo_1.degree_MAX = 180;
	Servo_1.GPIO = GPIOB;
	Servo_1.Pin = GPIO_Pin_6;
	Servo_SG90_Init(&Servo_1);
	
	Servo_SG90 Servo_2;
	Servo_2.degree_MAX = 180;
	Servo_2.GPIO = GPIOB;
	Servo_2.Pin = GPIO_Pin_7;
	Servo_SG90_Init(&Servo_2);
	uint16_t degree = 0;
	uint8_t direction = 1;
	
	while(1){
		Servo_SG90_Set_Degree(&Servo_1,degree);
		Servo_SG90_Set_Degree(&Servo_2,degree);
		Delay_ms(100);
		if(direction)degree++;else degree--;
		if(degree == 180 || degree == 0)direction = !direction;
	}
}
#endif /* __SERVO_SG90_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
