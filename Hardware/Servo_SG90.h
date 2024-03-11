/**
  ******************************************************************************
  * @file    Servo_SG90.h
  * @author  Lightcone
  * @version V1.0.2
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
	uint8_t degree_MAX;
	
	TIM_TypeDef* TIMx;//不用初始化
	void (*TIM_SetCompare_Callback)(TIM_TypeDef* TIMx, uint16_t Compare1);//不用初始化
	uint8_t degree;//不用初始化
}Servo_SG90;



#endif /* __SERVO_SG90_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
