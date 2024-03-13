/**
  ******************************************************************************
  * @file    Sensor_DHT11.c
  * @author  Lightcone
  * @version V1.0.2
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
	SimpleConfigGPIO(DHT11_x->GPIO,DHT11_x->Pin,GPIO_Mode_Out_OD);
	GPIO_WriteBit(DHT11_x->GPIO,DHT11_x->Pin,(BitAction)1);
}

/**
  * @brief  开始通讯
  * @param  DHT11_x:DHT11结构体指针
  * @retval void
  */
void DHT11_Begin(DHT11_TypeDef* DHT11_x){
	PullLow_ms(DHT11_x->GPIO,DHT11_x->Pin,20);
//起始信号 微处理器把数据总线（SDA）拉低一段时间至少 18ms（最大不得超过 30ms），通知传感器准备数据。

//响应信号 传感器把数据总线（SDA）拉低 83µs，再接高 87µs 以响应主机的起始信号。
	Waiting_Low(DHT11_x->GPIO,DHT11_x->Pin);
}

/**
  * @brief  获取8位数据
  * @param  DHT11_x:DHT11结构体指针
  * @retval 8位数据
  */
uint8_t DHT11_ReadByte(DHT11_TypeDef* DHT11_x){
	uint8_t Val = 0;
	for(uint8_t i = 0 ; i < 8; i++){
		//Waiting_Low(DHT11_x->GPIO,DHT11_x->Pin);
		Delay_us(90);//85~118
		Val += (Val<<1) + GPIO_ReadInputDataBit(DHT11_x->GPIO,DHT11_x->Pin);
	}
	return Val;
}

/**
  * @brief  更新结构体数据
  * @param  DHT11_x:DHT11结构体指针
  * @retval void
  */
void DHT11_updateData(DHT11_TypeDef* DHT11_x){
	//DHT11_Begin(DHT11_x);
	//Waiting_High(DHT11_x->GPIO,DHT11_x->Pin);// 再接高 87µs 以响应主机的起始信号。
	PullLow_ms(DHT11_x->GPIO,DHT11_x->Pin,20);
	Delay_us(170);
	
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


#include "STM32F103C_Dev_Board_V1.h"
void DHT11_Demo(){
	STM32F103C_Dev_Board_Init();
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],1,1,"Humidity:");
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],2,1,"  .  %RH");
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],3,1,"Temperature:");
	OLED_ShowString(&Onboard_OLED[Enum_OLED1],4,1,"   .  ");
	DHT11_TypeDef DHT11_1;
	DHT11_1.GPIO = GPIOA;
	DHT11_1.Pin = GPIO_Pin_1;
	DHT11_Init(&DHT11_1);
	while(1){
		DHT11_updateData(&DHT11_1);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],2,1,DHT11_1.Humidity_H,2);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],2,4,DHT11_1.Humidity_L,2);
		//且温度低位 Bit8 为 1 则表示负温度，否则为正温度
		if(DHT11_1.Temperature_L&0x10000000)OLED_ShowString(&Onboard_OLED[Enum_OLED1],4,1,"-");
		else OLED_ShowString(&Onboard_OLED[Enum_OLED1],4,1,"+");
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],4,2,DHT11_1.Temperature_H,2);
		OLED_ShowNum(&Onboard_OLED[Enum_OLED1],4,5,DHT11_1.Temperature_L&0x01111111,2);
	}
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
