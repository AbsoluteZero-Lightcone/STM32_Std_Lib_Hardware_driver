#ifndef __MATRIX_LED_H
#define __MATRIX_LED_H

typedef struct{
	_74HC595_TypeDef ROW,COL;
} MatrixLED_TypeDef;


void MatrixLED_Init(MatrixLED_TypeDef *MatrixLED_t);

void MatrixLED_cls(MatrixLED_TypeDef *MatrixLED_t);

void MatrixLED_ShowRow(MatrixLED_TypeDef *MatrixLED_t,uint8_t r,uint16_t Data);
void ShowByteArray(MatrixLED_TypeDef *MatrixLED_t,uint8_t *arr,uint8_t BytePerRow,uint8_t position);
void ShowArray(MatrixLED_TypeDef *MatrixLED_t,uint16_t *arr);

void Show2DArray(MatrixLED_TypeDef *MatrixLED_t,uint8_t **arr);


#endif
