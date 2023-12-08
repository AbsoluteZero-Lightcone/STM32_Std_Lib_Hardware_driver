#ifndef __DATA_TYPE_H
#define __DATA_TYPE_H

uint32_t to_RCC_APB2Periph(GPIO_TypeDef* GPIO);
uint8_t to_GPIO_PortSource(GPIO_TypeDef* GPIO);
uint8_t to_GPIO_PinSource(uint16_t Pin);
uint32_t to_EXTI_Line(uint16_t Pin);
uint8_t to_IRQn_Type(uint16_t Pin);
#endif
