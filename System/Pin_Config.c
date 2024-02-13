/**
  ******************************************************************************
  * @file    Pin_Config.c
  * @author  Lightcone
  * @version V1.1.1
  * @date    2024-02-14
  * @brief   用于STM32F10x标准库的引脚可用性和引脚功能的快速配置
  ******************************************************************************
  */

#include "stm32f10x.h"     // Device header
#include "DataType.h"
#include "Pin_Config.h"

/**
  * @brief  禁用JTAG的JTRST，使之可被用作GPIO
  *         Full SWJ Enabled (JTAG-DP + SW-DP) but without JTRST
  * @retval void
  */
void DisableJTRST(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST,ENABLE);
}

/**
  * @brief  禁用JTAG调试方式，使JTAG调试口可被用作GPIO
  *         JTAG-DP Disabled and SW-DP Enabled
  * @retval void
  */
void DisableJTAG(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
}

/**
  * @brief  禁用JTAG和SWD调试方式，使JTAG和SWD调试口均可被用作GPIO，慎用
  *         Full SWJ Disabled (JTAG-DP + SW-DP)
  * @retval void
  */
void DisableFullSWJ(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
}



/**
  * @brief  快速配置电源引脚
  * @param  GPIOx      x = A~G
  * @param  一个或多个 GPIO_Pin_x x = 0~15
  * @param  val        1 for Set / 0 for Reset
  * @retval void
  */
void setPowerPin(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x,uint8_t val){
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(GPIOx),ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_x;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx,&GPIO_InitStruct);
	GPIO_WriteBit(GPIOx,GPIO_Pin_x,(BitAction)val);
}

/**
  * @brief  快捷使能GPIO时钟并完成配置
  * @param  GPIOx:  x = A ~ G
  * @param  GPIO_Pin: GPIO_Pin_x
  * @param  GPIO_Mode:
  *   This parameter can be one of the following values:
				typedef enum
				{ GPIO_Mode_AIN = 0x0,
					GPIO_Mode_IN_FLOATING = 0x04,
					GPIO_Mode_IPD = 0x28,
					GPIO_Mode_IPU = 0x48,
					GPIO_Mode_Out_OD = 0x14,
					GPIO_Mode_Out_PP = 0x10,
					GPIO_Mode_AF_OD = 0x1C,
					GPIO_Mode_AF_PP = 0x18
				}GPIOMode_TypeDef;
  * @retval 
  */
void SimpleEnableGPIO(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode){
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(GPIOx),ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin;
	GPIO_Init(GPIOx,&GPIO_InitStruct);
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
