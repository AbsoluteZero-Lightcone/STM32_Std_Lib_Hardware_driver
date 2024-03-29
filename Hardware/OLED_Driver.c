/**
  ******************************************************************************
  * @file    OLED_Driver.c
  * @author  Lightcone
  * @version V1.2.0
  * @date    2024-03-20
  * @brief   OLED OLED_SPI硬件驱动层
  ******************************************************************************
  */
#include "STM32Device.h"
//#include "OLED_Font.h"
#include "OLED.h"

#define OLED_W_D0(x)		GPIO_WriteBit(OLED_SPI_Struct_ptr->D0_GPIO, OLED_SPI_Struct_ptr->D0_Pin, (BitAction)(x))
#define OLED_W_D1(x)		GPIO_WriteBit(OLED_SPI_Struct_ptr->D1_GPIO, OLED_SPI_Struct_ptr->D1_Pin, (BitAction)(x))
#define OLED_W_RES(x)		GPIO_WriteBit(OLED_SPI_Struct_ptr->RES_GPIO, OLED_SPI_Struct_ptr->RES_Pin, (BitAction)(x))
#define OLED_W_DC(x)		GPIO_WriteBit(OLED_SPI_Struct_ptr->DC_GPIO, OLED_SPI_Struct_ptr->DC_Pin, (BitAction)(x))
//#define OLED_W_CS(x)		GPIO_WriteBit(OLED_SPI_Struct_ptr->CS_GPIO, OLED_SPI_Struct_ptr->CS_Pin, (BitAction)(x))

void OLED_W_CS(OLED_SPI* OLED_SPI_Struct_ptr,BitAction x){
	//GPIO_WriteBit(OLED_SPI_Struct_ptr->CS_GPIO, OLED_SPI_Struct_ptr->CS_Pin,x);
	OLED_SPI_Struct_ptr->CS_Handler();
}


/*引脚初始化*/
void OLED_SPI_Init(OLED_SPI* OLED_SPI_Struct_ptr)
{
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(OLED_SPI_Struct_ptr->D0_GPIO), ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(OLED_SPI_Struct_ptr->D1_GPIO), ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(OLED_SPI_Struct_ptr->RES_GPIO), ENABLE);
	RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(OLED_SPI_Struct_ptr->DC_GPIO), ENABLE);
	//RCC_APB2PeriphClockCmd(to_RCC_APB2Periph(OLED_SPI_Struct_ptr->CS_GPIO), ENABLE);

	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = OLED_SPI_Struct_ptr->D0_Pin;
 	GPIO_Init(OLED_SPI_Struct_ptr->D0_GPIO, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = OLED_SPI_Struct_ptr->D1_Pin;
 	GPIO_Init(OLED_SPI_Struct_ptr->D1_GPIO, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = OLED_SPI_Struct_ptr->DC_Pin;
 	GPIO_Init(OLED_SPI_Struct_ptr->DC_GPIO, &GPIO_InitStructure);
	/*
	GPIO_InitStructure.GPIO_Pin = OLED_SPI_Struct_ptr->CS_Pin;
 	GPIO_Init(OLED_SPI_Struct_ptr->CS_GPIO, &GPIO_InitStructure);
	*/
	GPIO_InitStructure.GPIO_Pin = OLED_SPI_Struct_ptr->RES_Pin;
 	GPIO_Init(OLED_SPI_Struct_ptr->RES_GPIO, &GPIO_InitStructure);
	
	OLED_W_D0(1);
	
	OLED_W_D1(1);
	OLED_W_RES(0);
	OLED_W_RES(1);
	OLED_W_DC(1);
	//OLED_W_CS(OLED_SPI_Struct_ptr,(BitAction)1);
}

/**
  * @brief  SPI发送一个字节
  * @param  Byte 要发送的一个字节
  * @retval 无
  */
void OLED_SPI_SendByte(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i++)
	{
		OLED_W_D0(0);
		OLED_W_D1(Byte & (0x80 >> i));
		OLED_W_D0(1);
	}
}

/**
  * @brief  OLED写命令
  * @param  Command 要写入的命令
  * @retval 无
  */
void OLED_WriteCommand(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Command)
{
	OLED_W_CS(OLED_SPI_Struct_ptr,(BitAction)0);
	OLED_W_DC(0);
	OLED_SPI_SendByte(OLED_SPI_Struct_ptr,Command);
	//OLED_W_CS(OLED_SPI_Struct_ptr,(BitAction)1);
}

/**
  * @brief  OLED写数据
  * @param  Data 要写入的数据
  * @retval 无
  */
void OLED_WriteData(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Data)
{
	OLED_W_CS(OLED_SPI_Struct_ptr,(BitAction)0);
	OLED_W_DC(1);
	OLED_SPI_SendByte(OLED_SPI_Struct_ptr,Data);
	//OLED_W_CS(OLED_SPI_Struct_ptr,(BitAction)1);
}

/**
  * @brief  OLED设置光标位置
  * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
  * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
  * @retval 无
  */
void OLED_SetCursor(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xB0 | Y);					//设置Y位置
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x00 | (X & 0x0F));			//设置X位置低4位
}

/**
  * @brief  OLED清屏
  * @param  无
  * @retval 无
  */
void OLED_Clear(OLED_SPI* OLED_SPI_Struct_ptr)
{  
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		OLED_SetCursor(OLED_SPI_Struct_ptr,j, 0);
		for(i = 0; i < 128; i++)
		{
			OLED_WriteData(OLED_SPI_Struct_ptr,0x00);
		}
	}
}

/**
  * @brief  OLED初始化
  * @param  无
  * @retval 无
  */
void OLED_Init(OLED_SPI* OLED_SPI_Struct_ptr)
{
	uint32_t i, j;
	
	for (i = 0; i < 1000; i++)			//上电延时
	{
		for (j = 0; j < 1000; j++);
	}
	
	OLED_SPI_Init(OLED_SPI_Struct_ptr);			//端口初始化
	
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xAE);	//关闭显示
	
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xD5);	//设置显示时钟分频比/振荡器频率
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x80);
	
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xA8);	//设置多路复用率
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x3F);
	
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xD3);	//设置显示偏移
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x00);
	
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x40);	//设置显示开始行
	
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xDA);	//设置COM引脚硬件配置
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x12);
	
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x81);	//设置对比度控制
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xCF);

	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xD9);	//设置预充电周期
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xF1);

	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xDB);	//设置VCOMH取消选择级别
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x30);

	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xA4);	//设置整个显示打开/关闭

	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xA6);	//设置正常/倒转显示

	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x8D);	//设置充电泵
	OLED_WriteCommand(OLED_SPI_Struct_ptr,0x14);

	OLED_WriteCommand(OLED_SPI_Struct_ptr,0xAF);	//开启显示
		
	OLED_Clear(OLED_SPI_Struct_ptr);				//OLED清屏
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
