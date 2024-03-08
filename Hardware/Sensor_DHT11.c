/**
  ******************************************************************************
  * @file    Sensor_DHT11.c
  * @author  Lightcone
  * @version V1.0.1
  * @date    2024-03-08
  * @brief   DHT11 温湿度传感器驱动
  ******************************************************************************
  */
#include "STM32Device.h"
#include "Sensor_DHT11.h"

/**
  * @brief  初始化一个DHT11设备
  * @param  DHT11_x:DHT11结构体指针
  * @retval void
  */
void DHT11_Init(DHT11_TypeDef* DHT11_x){
	SimpleEnableGPIO(DHT11_x->GPIO,DHT11_x->Pin,GPIO_Mode_Out_OD);
	GPIO_WriteBit(DHT11_x->GPIO,DHT11_x->Pin,(BitAction)1);
}

/**
  * @brief  开始通讯
  * @param  DHT11_x:DHT11结构体指针
  * @retval void
  */
void DHT11_Begin(DHT11_TypeDef* DHT11_x){
//起始信号 微处理器把数据总线（SDA）拉低一段时间至少 18ms（最大不得超过 30ms），通知传感器准备数据。
	GPIO_WriteBit(DHT11_x->GPIO,DHT11_x->Pin,(BitAction)0);
	Delay_ms(20);
	GPIO_WriteBit(DHT11_x->GPIO,DHT11_x->Pin,(BitAction)1);
//响应信号 传感器把数据总线（SDA）拉低 83µs，再接高 87µs 以响应主机的起始信号。
	while(GPIO_ReadOutputDataBit(DHT11_x->GPIO,DHT11_x->Pin));//等待拉低
}

/**
  * @brief  获取8位数据
  * @param  DHT11_x:DHT11结构体指针
  * @retval 8位数据
  */
uint8_t DHT11_ReadByte(DHT11_TypeDef* DHT11_x){
	uint8_t Val = 0;
	for(uint8_t i = 0 ; i < 8; i++){
		while(GPIO_ReadOutputDataBit(DHT11_x->GPIO,DHT11_x->Pin));//等待拉低
		Delay_us(90);//85~118
		Val += (Val<<1) + GPIO_ReadOutputDataBit(DHT11_x->GPIO,DHT11_x->Pin);
	}
	return Val;
}

/**
  * @brief  更新结构体数据
  * @param  DHT11_x:DHT11结构体指针
  * @retval void
  */
void DHT11_updateData(DHT11_TypeDef* DHT11_x){
	DHT11_Begin(DHT11_x);
	// 再接高 87µs 以响应主机的起始信号。
	while(GPIO_ReadOutputDataBit(DHT11_x->GPIO,DHT11_x->Pin));//等待高电平
	//Delay_us(87);
	uint8_t Humidity_H = DHT11_ReadByte(DHT11_x);
	uint8_t Humidity_L = DHT11_ReadByte(DHT11_x);
	uint8_t Temperature_H = DHT11_ReadByte(DHT11_x); 
	uint8_t Temperature_L = DHT11_ReadByte(DHT11_x); 
	uint8_t Verification = DHT11_ReadByte(DHT11_x);
	if(Verification == 
			Humidity_H +
			Humidity_L +
			Temperature_H +
			Temperature_L
	){
		DHT11_x->Humidity_H = Humidity_H;
		DHT11_x->Humidity_L = Humidity_L;
		DHT11_x->Temperature_H = Temperature_H;
		DHT11_x->Temperature_L = Temperature_L;
	}
}


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
