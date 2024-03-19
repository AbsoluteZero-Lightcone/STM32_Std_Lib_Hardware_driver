/**
  ******************************************************************************
  * @file    UART.c
  * @author  Lightcone
  * @version V1.0.2
  * @date    2024-03-19
  * @brief   STM32F10x 
  ******************************************************************************
  */
#include "STM32Device.h"
void Serial_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	SimpleConfigGPIO(USART1_TX_AF_GPIO,USART1_TX_AF_Pin,GPIO_Mode_AF_PP);
	USART_InitTypeDef USART_InitStruct = {
		.USART_BaudRate            = 9600,
		.USART_WordLength          = USART_WordLength_8b,
		.USART_StopBits            = USART_StopBits_1,
		.USART_Parity              = USART_Parity_No,
		.USART_Mode                = USART_Mode_Tx,
		.USART_HardwareFlowControl = USART_HardwareFlowControl_None
	};
	USART_Init(USART1,&USART_InitStruct);
	USART_Cmd(USART1,ENABLE);
}

void Serial_SendData(uint16_t Data){
	USART_SendData(USART1,Data);
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
