/**
  ******************************************************************************
  * @file    UART.c
  * @author  Lightcone
  * @version V1.0.6
  * @date    2024-03-20
  * @brief   STM32F10x 
  ******************************************************************************
  */
#include "STM32Device.h"
#include "UART.h"

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
//void Serial_SendString(char s[]){
//	uint16_t i = 0;
//	while(s[i]!='\0'){
//		Serial_SendData(s[i]);
//		//if(s[i+1]=='\0')break;
//		i++;
//	}
//}

void Serial_SendString(char s[]){
	while(*s!='\0'){
		Serial_SendData(*s);
		s++;
	}
}
void Serial_SendNum(__SERIAL_NUM_DATA_SIZE n){
	__SERIAL_NUM_DATA_SIZE reverse_n = 0;
	uint8_t length = 0;
	while(n!=0){
		reverse_n *= 10;
		reverse_n += n%10;
		length++;
		n /= 10;
	}
	while(length!=0){
		Serial_SendData(reverse_n%10+'0');
		reverse_n/=10;
		length--;
	}
}
void Serial_SendHexNum(__SERIAL_NUM_DATA_SIZE n){
	__SERIAL_NUM_DATA_SIZE reverse_n = 0;
	uint8_t length = 0;
	while(n!=0){
		reverse_n <<= 4;
		reverse_n += n&0xF;
		length++;
		n >>= 4;
	}
	Serial_SendData('0');
	Serial_SendData('x');
	while(length!=0){
		Serial_SendData((reverse_n&0xF)>=10?(reverse_n&0xF)-10+'A':(reverse_n&0xF)+'0');
		reverse_n>>=4;
		length--;
	}
}
void Serial_SendBinNum(__SERIAL_NUM_DATA_SIZE n){
	__SERIAL_NUM_DATA_SIZE reverse_n = 0;
	uint8_t length = 0;
	while(n!=0){
		reverse_n <<= 1;
		reverse_n += n&0x1;
		length++;
		n >>= 1;
	}
	while(length%4!=0){
		reverse_n <<= 1;
		length++;
	}
	//Serial_SendData('0');
	//Serial_SendData('b');
	uint8_t flag=0;
	while(length!=0){
		if(length%4==0&&flag)Serial_SendData(' ');
		flag=1;
		Serial_SendData((reverse_n&0x1)+'0');
		reverse_n>>=1;
		length--;
	}
}
void Serial_EndLine(){
	Serial_SendData('\n');
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
