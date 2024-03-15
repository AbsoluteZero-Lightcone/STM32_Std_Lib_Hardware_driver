/**
  ******************************************************************************
  * @file    UART.h
  * @author  Lightcone
  * @version V1.0.1
  * @date    2024-03-15
  * @brief   STM32F10x 
  ******************************************************************************
  */
#ifndef __UART_H
#define __UART_H
#include "STM32Device.h"
void Serial_Init();
void Serial_SendData(uint16_t Data);
#endif /* __UART_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
