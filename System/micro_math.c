/**
  ******************************************************************************
  * @file    micro_math.c
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-03-21
  * @brief   常用数学操作实现函数库
  ******************************************************************************
  */
#include "STM32Device.h"
/**
  * @brief  整数次方函数
  * @retval 返回值等于X的Y次方
  */
uint64_t IntPow(uint32_t X, uint32_t Y)
{
	uint64_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
