/**
  ******************************************************************************
  * @file    Pin_Define.h
  * @author  Lightcone
  * @version V1.0.0
  * @date    2024-2-11
  * @brief   STM32 MCU 的引脚定义
  ******************************************************************************
  */
#ifndef __PIN_CONFIG_H
#define __PIN_CONFIG_H

//#define MCU_STM32F103C
#ifdef MCU_STM32F103C
/**
  * @defgroup STM32F103C_Debug_Pin
  * @{
  */  
// JTAG_JTDI
#define JTAG_JTDI_GPIO GPIOA
#define JTAG_JTDI_Pin  GPIO_Pin_15
// JTAG_JTDO
#define JTAG_JTDO_GPIO GPIOB
#define JTAG_JTDO_Pin  GPIO_Pin_3
// JTAG_NJTRST
#define JTAG_NJTRST_GPIO GPIOB
#define JTAG_NJTRST_Pin  GPIO_Pin_4
// JTAG_JTMS
#define JTAG_JTMS_GPIO GPIOA
#define JTAG_JTMS_Pin  GPIO_Pin_13
// JTAG_JTCK
#define JTAG_JTCK_GPIO GPIOA
#define JTAG_JTCK_Pin  GPIO_Pin_14

// SW_SWDIO
#define SW_SWDIO_GPIO GPIOA
#define SW_SWDIO_Pin  GPIO_Pin_13
// SW_SWCLK
#define SW_SWCLK_GPIO GPIOA
#define SW_SWCLK_Pin  GPIO_Pin_14
/**
  * @}
  */

#endif /* MCU_STM32F103C */

#endif /* __PIN_CONFIG_H */
