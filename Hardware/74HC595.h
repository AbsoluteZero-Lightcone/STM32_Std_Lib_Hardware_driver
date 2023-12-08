#ifndef __74HC595_H
#define __74HC595_H

typedef struct{
GPIO_TypeDef* SER_GPIO;
uint16_t SER_Pin;
GPIO_TypeDef* SCK_GPIO;
uint16_t SCK_Pin;
GPIO_TypeDef* RCK_GPIO;
uint16_t RCK_Pin;
} _74HC595_TypeDef;

void _74HC595_Init(_74HC595_TypeDef* _74HC595_Struct);
void _74HC595_WriteByte(_74HC595_TypeDef* _74HC595_Struct,uint8_t Data);
void _74HC595_WriteWORD(_74HC595_TypeDef* _74HC595_Struct,uint16_t Data);
void _74HC595_WriteData(_74HC595_TypeDef* _74HC595_Struct,uint64_t Data,uint8_t len);// len 数据位数1~64


#endif
