/**
  ******************************************************************************
  * @file    UART.c
  * @author  Lightcone
  * @version V1.0.3
  * @date    2024-03-20
  * @brief   STM32F10x 
  ******************************************************************************
  */
#include "STM32Device.h"
void Serial_Init(uint32_t USART_BaudRate){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	SimpleConfigGPIO(USART1_TX_AF_GPIO,USART1_TX_AF_Pin,GPIO_Mode_AF_PP);
	USART_InitTypeDef USART_InitStruct = {
		.USART_BaudRate            = USART_BaudRate,
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
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TC));
}
void Serial_SendString(char s[]){
	uint16_t i = 0;
	while(s[i]!='\0'){
		Serial_SendData(s[i]);
		//if(s[i+1]=='\0')break;
		i++;
	}
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
