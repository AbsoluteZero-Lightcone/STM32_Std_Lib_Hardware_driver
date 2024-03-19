/**
  ******************************************************************************
  * @file    UART.h
  * @author  Lightcone
  * @version V1.0.3
  * @date    2024-03-20
  * @brief   STM32F10x 
  ******************************************************************************
  */
#ifndef __UART_H
#define __UART_H
#include "STM32Device.h"
void Serial_Init(uint32_t USART_BaudRate);
void Serial_SendData(uint16_t Data);
void Serial_SendString(char s[]);
#endif /* __UART_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
