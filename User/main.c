/**
  ******************************************************************************
  * @file    main.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-02-15
  * @brief   STM32F10x 入口函数
  ******************************************************************************
  */
#include "stm32f10x.h"                  // Device header

extern int main_PWMIO(void);

int main(){
	main_PWMIO();
	while(1){
		
	}
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
