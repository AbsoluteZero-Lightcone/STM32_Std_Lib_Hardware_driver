#ifndef __OLED_H
#define __OLED_H

/*引脚配置*/

/*
D0：串行输入时钟CLK 紫色
D1：串行输入数据 灰色
RES：复位 
DC：控制输入数据/命令（高电平1为数据、低电平0为命令） 蓝色
cs绿色
*/
void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
