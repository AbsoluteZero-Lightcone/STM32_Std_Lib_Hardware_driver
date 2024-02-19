/**
  ******************************************************************************
  * @file    TIM_PWM.h
  * @version V1.0.0
  * @date    2024-02-11
  * @brief   定时器输出PWM信号
  ******************************************************************************
  */


#ifndef __TIM_PWM_H
#define __TIM_PWM_H

#include "STM32Device.h"


/** 
  * @brief  Simple_PWM structure definition  
  */
typedef struct
{
	TIM_TypeDef* TIMx;
	float precision;// 大于0.00001525879
	uint32_t freq;
	float duty;
	GPIO_TypeDef* GPIO;
	uint16_t Pin;
	
	uint16_t PWM_ARR;
	uint16_t PWM_PSC;
	uint16_t PWM_CCR;
}Simple_PWM_TypeDef;


void Simple_PWM_ParamUpdate(Simple_PWM_TypeDef* Simple_PWM_Structure);
void Simple_PWM_Init(Simple_PWM_TypeDef* Simple_PWM_Structure);




#endif /* __TIM_PWM_H */


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
