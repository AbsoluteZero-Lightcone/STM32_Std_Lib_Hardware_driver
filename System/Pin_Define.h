/**
  ******************************************************************************
  * @file    Pin_Define.h
  * @author  Lightcone
  * @version V1.2.0
  * @date    2024-2-14
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

/** @defgroup STM32F103C_TIM_Pin
  * @{
  */ 

#define TIM1_ETR_AF_GPIO GPIOA
#define TIM1_ETR_AF_Pin  GPIO_Pin_12
#define TIM1_CH1_AF_GPIO GPIOA
#define TIM1_CH1_AF_Pin  GPIO_Pin_8
#define TIM1_CH2_AF_GPIO GPIOA
#define TIM1_CH2_AF_Pin  GPIO_Pin_9
#define TIM1_CH3_AF_GPIO GPIOA
#define TIM1_CH3_AF_Pin  GPIO_Pin_10
#define TIM1_CH4_AF_GPIO GPIOA
#define TIM1_CH4_AF_Pin  GPIO_Pin_11
#define TIM1_CH1N_AF_GPIO GPIOB
#define TIM1_CH1N_AF_Pin  GPIO_Pin_13
#define TIM1_CH2N_AF_GPIO GPIOB
#define TIM1_CH2N_AF_Pin  GPIO_Pin_14
#define TIM1_CH3N_AF_GPIO GPIOB
#define TIM1_CH3N_AF_Pin  GPIO_Pin_15
#define TIM1_BKIN_AF_GPIO GPIOB
#define TIM1_BKIN_AF_Pin  GPIO_Pin_12
#define TIM1_CH1N_Remap_GPIO GPIOA
#define TIM1_CH1N_Remap_Pin  GPIO_Pin_7
#define TIM1_CH2N_Remap_GPIO GPIOB
#define TIM1_CH2N_Remap_Pin  GPIO_Pin_10
#define TIM1_CH3N_Remap_GPIO GPIOB
#define TIM1_CH3N_Remap_Pin  GPIO_Pin_11
#define TIM1_BKIN_Remap_GPIO GPIOA
#define TIM1_BKIN_Remap_Pin  GPIO_Pin_6

#define TIM2_CH1_ETR_AF_GPIO GPIOA
#define TIM2_CH1_ETR_AF_Pin  GPIO_Pin_0
#define TIM2_CH2_AF_GPIO GPIOA
#define TIM2_CH2_AF_Pin  GPIO_Pin_1
#define TIM2_CH3_AF_GPIO GPIOA
#define TIM2_CH3_AF_Pin  GPIO_Pin_2
#define TIM2_CH4_AF_GPIO GPIOA
#define TIM2_CH4_AF_Pin  GPIO_Pin_3
#define TIM2_CH1_ETR_Remap_GPIO JTAG_JTDI_GPIO
#define TIM2_CH1_ETR_Remap_Pin  JTAG_JTDI_Pin
#define TIM2_CH2_Remap_GPIO JTAG_JTDO_GPIO
#define TIM2_CH2_Remap_Pin  JTAG_JTDO_Pin
#define TIM2_CH3_Remap_GPIO GPIOB
#define TIM2_CH3_Remap_Pin  GPIO_Pin_10
#define TIM2_CH4_Remap_GPIO GPIOB
#define TIM2_CH4_Remap_Pin  GPIO_Pin_11

#define TIM3_CH1_AF_GPIO GPIOA
#define TIM3_CH1_AF_Pin  GPIO_Pin_6
#define TIM3_CH2_AF_GPIO GPIOA
#define TIM3_CH2_AF_Pin  GPIO_Pin_7
#define TIM3_CH3_AF_GPIO GPIOB
#define TIM3_CH3_AF_Pin  GPIO_Pin_0
#define TIM3_CH4_AF_GPIO GPIOB
#define TIM3_CH4_AF_Pin  GPIO_Pin_1
#define TIM3_CH1_Remap_GPIO JTAG_NJTRST_GPIO
#define TIM3_CH1_Remap_Pin  JTAG_NJTRST_Pin
#define TIM3_CH2_Remap_GPIO GPIOB
#define TIM3_CH2_Remap_Pin  GPIO_Pin_5

#define TIM4_CH1_AF_GPIO GPIOB
#define TIM4_CH1_AF_Pin  GPIO_Pin_6
#define TIM4_CH2_AF_GPIO GPIOB
#define TIM4_CH2_AF_Pin  GPIO_Pin_7
#define TIM4_CH3_AF_GPIO GPIOB
#define TIM4_CH3_AF_Pin  GPIO_Pin_8
#define TIM4_CH4_AF_GPIO GPIOB
#define TIM4_CH4_AF_Pin  GPIO_Pin_9

/**
  * @}
  */

/** @defgroup STM32F103C_TIM_Pin
  * @{
  */ 
#define ADC12_IN0_AF_GPIO GPIOA
#define ADC12_IN0_AF_Pin  GPIO_Pin_0
#define ADC12_IN1_AF_GPIO GPIOA
#define ADC12_IN1_AF_Pin  GPIO_Pin_1
#define ADC12_IN2_AF_GPIO GPIOA
#define ADC12_IN2_AF_Pin  GPIO_Pin_2
#define ADC12_IN3_AF_GPIO GPIOA
#define ADC12_IN3_AF_Pin  GPIO_Pin_3
#define ADC12_IN4_AF_GPIO GPIOA
#define ADC12_IN4_AF_Pin  GPIO_Pin_4
#define ADC12_IN5_AF_GPIO GPIOA
#define ADC12_IN5_AF_Pin  GPIO_Pin_5
#define ADC12_IN6_AF_GPIO GPIOA
#define ADC12_IN6_AF_Pin  GPIO_Pin_6
#define ADC12_IN7_AF_GPIO GPIOA
#define ADC12_IN7_AF_Pin  GPIO_Pin_7
#define ADC12_IN8_AF_GPIO GPIOB
#define ADC12_IN8_AF_Pin  GPIO_Pin_0
#define ADC12_IN9_AF_GPIO GPIOB
#define ADC12_IN9_AF_Pin  GPIO_Pin_1
/**
  * @}
  */

#endif /* MCU_STM32F103C */

#endif /* __PIN_CONFIG_H */
