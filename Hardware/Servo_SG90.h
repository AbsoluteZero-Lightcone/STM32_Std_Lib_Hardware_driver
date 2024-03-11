/**
  ******************************************************************************
  * @file    Servo_SG90.h
  * @author  Lightcone
  * @version V1.0.1
  * @date    2024-03-11
  * @brief   STM32F10x SG90伺服电机驱动
  ******************************************************************************
  */

#ifndef __SERVO_SG90_H
#define __SERVO_SG90_H
#include "STM32Device.h"

typedef struct{
	TIM_TypeDef* TIMx;
	uint8_t TIM_Channel;
	GPIO_TypeDef* GPIO;
	uint16_t Pin;
	uint8_t degree;
	uint8_t degree_MAX;
}Servo_SG90;



#endif /* __SERVO_SG90_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
