/**
  ******************************************************************************
  * @file    UART.h
  * @author  Lightcone
  * @version V1.0.6
  * @date    2024-03-20
  * @brief   STM32F10x 
  ******************************************************************************
  */
#ifndef __UART_H
#define __UART_H
#include "STM32Device.h"

#define __SERIAL_NUM_DATA_SIZE uint64_t

void Serial_Init(uint32_t USART_BaudRate);
void Serial_SendData(uint16_t Data);
void Serial_SendString(char s[]);
void Serial_SendNum(__SERIAL_NUM_DATA_SIZE n);
void Serial_SendHexNum(__SERIAL_NUM_DATA_SIZE n);
void Serial_SendBinNum(__SERIAL_NUM_DATA_SIZE n);
void Serial_EndLine(void);
#endif /* __UART_H */

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
