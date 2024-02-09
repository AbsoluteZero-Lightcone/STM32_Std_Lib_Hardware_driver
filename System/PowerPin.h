#ifndef __POWER_PIN
#define __POWER_PIN
#include "stm32f10x.h"                  // Device header

void setPowerPin(GPIO_TypeDef* GPIO,uint16_t Pin,uint8_t val);



#endif
