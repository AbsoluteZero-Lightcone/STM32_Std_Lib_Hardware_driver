/**
  ******************************************************************************
  * @file    OLED_Display.c
  * @author  Lightcone
  * @version V1.2.1
  * @date    2024-03-21
  * @brief   OLED应用层
  ******************************************************************************
  */
#include "STM32Device.h"
#include "OLED_Font.h"
#include "OLED.h"


void OLED_WriteData(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Data);
void OLED_SetCursor(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Y, uint8_t X);

/**
  * @brief  OLED显示一个字符
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的一个字符，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowChar(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Line, uint8_t Column, char Char)
{	  	
	uint8_t i;
	OLED_SetCursor(OLED_SPI_Struct_ptr,(Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_SPI_Struct_ptr,OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor(OLED_SPI_Struct_ptr,(Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_SPI_Struct_ptr,OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

/**
  * @brief  OLED显示字符串
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowString(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Line, uint8_t Column, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(OLED_SPI_Struct_ptr,Line, Column + i, String[i]);
	}
}


/**
  * @brief  OLED显示数字（十进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~4294967295
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowNum(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Line, uint8_t Column, OLED_NUM_DATA_SIZE Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(OLED_SPI_Struct_ptr,Line, Column + i, Number / IntPow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十进制，带符号数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：-2147483648~2147483647
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowSignedNum(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Line, uint8_t Column, OLED_SIGNED_NUM_DATA_SIZE Number, uint8_t Length)
{
	uint8_t i;
	uint32_t Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(OLED_SPI_Struct_ptr,Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(OLED_SPI_Struct_ptr,Line, Column, '-');
		Number1 = -Number;
	}
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(OLED_SPI_Struct_ptr,Line, Column + i + 1, Number1 / IntPow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十六进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~0xFFFFFFFF
  * @param  Length 要显示数字的长度，范围：1~8
  * @retval 无
  */
void OLED_ShowHexNum(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Line, uint8_t Column, OLED_NUM_DATA_SIZE Number, uint8_t Length)
{
	uint8_t i, SingleNumber;
	for (i = 0; i < Length; i++)							
	{
		SingleNumber = Number / IntPow(16, Length - i - 1) % 16;
		if (SingleNumber < 10)
		{
			OLED_ShowChar(OLED_SPI_Struct_ptr,Line, Column + i, SingleNumber + '0');
		}
		else
		{
			OLED_ShowChar(OLED_SPI_Struct_ptr,Line, Column + i, SingleNumber - 10 + 'A');
		}
	}
}

/**
  * @brief  OLED显示数字（二进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void OLED_ShowBinNum(OLED_SPI* OLED_SPI_Struct_ptr,uint8_t Line, uint8_t Column, OLED_NUM_DATA_SIZE Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(OLED_SPI_Struct_ptr,Line, Column + i, Number / IntPow(2, Length - i - 1) % 2 + '0');
	}
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
