#ifndef __MATRIX_LED_H
#define __MATRIX_LED_H

void MatrixLED_Init(
	GPIO_TypeDef* IC1_SER_GPIO_t,
	uint16_t IC1_SER_Pin_t,
	GPIO_TypeDef* IC1_SCK_GPIO_t,
	uint16_t IC1_SCK_Pin_t,
	GPIO_TypeDef* IC1_RCK_GPIO_t,
	uint16_t IC1_RCK_Pin_t,

	GPIO_TypeDef* IC2_SER_GPIO_t,
	uint16_t IC2_SER_Pin_t,
	GPIO_TypeDef* IC2_SCK_GPIO_t,
	uint16_t IC2_SCK_Pin_t,
	GPIO_TypeDef* IC2_RCK_GPIO_t,
	uint16_t IC2_RCK_Pin_t);

void MatrixLED_cls(void);

void MatrixLED_ShowRow(uint8_t r,uint16_t Data);
void ShowByteArray(uint8_t *arr,uint8_t BytePerRow,uint8_t position);
void ShowArray(uint16_t *arr);

void Show2DArray(uint8_t **arr);


#endif
