/**
  ******************************************************************************
  * @file    Sensor_DHT11.h
  * @author  Lightcone
  * @version V1.0.2
  * @date    2024-03-08
  * @brief   DHT11 温湿度传感器驱动
  ******************************************************************************
  */

#ifndef __SENSOR_DHT11_H
#define __SENSOR_DHT11_H
#include "STM32Device.h"

typedef struct{
	GPIO_TypeDef* GPIO;
	uint16_t Pin;
	uint8_t Humidity_H;
	uint8_t Humidity_L;
	uint8_t Temperature_H;
	uint8_t Temperature_L;
}DHT11_TypeDef;

void DHT11_Init(DHT11_TypeDef* DHT11_x);
void DHT11_updateData(DHT11_TypeDef* DHT11_x);

void DHT11_Demo(void);
#endif /* __SENSOR_DHT11_H */
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
