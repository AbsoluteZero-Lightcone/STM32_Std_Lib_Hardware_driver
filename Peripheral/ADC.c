/**
  ******************************************************************************
  * @file    ADC.c
  * @author  Lightcone
  * @version V1.1.1
  * @date    2024-02-22
  * @brief   STM32F10x ADC
  *********;*********************************************************************
  */
#include "STM32Device.h"

void Simple_ADC1_Single_Channel_Init(){
	// 来源
	ADC_TempSensorVrefintCmd(ENABLE);
	SimpleEnableGPIO(ADC12_IN0_AF_GPIO,ADC12_IN0_AF_Pin,GPIO_Mode_AIN);
	// 时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);

	// 初始化ADC：
	//输入配置：ADC转换触发源选择
	//功能配置：双ADC模式选择ADC_Mode
	//					连续模式ADC_ContinuousConvMode
	//					扫描模式ADC_ScanConvMode 扫描通道数ADC_NbrOfChannel
	//输出配置：12bit数据在16bit的对齐方式ADC_DataAlign
	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;// 是否使用双ADC模式
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;// 来自主模式的信号（外部触发源）控制从模式ADC被触发，选择None只使用软件触发
	ADC_InitStruct.ADC_ContinuousConvMode = DISABLE;// 单次/连续
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;// 扫描/非扫描
	ADC_InitStruct.ADC_NbrOfChannel = 1;//扫描通道数 Number（Nbr） of channel
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_Init(ADC1,&ADC_InitStruct);
	// 配置中断、看门狗 等附加功能
	
	// ADC启动
	ADC_Cmd(ADC1,ENABLE); 
	// ADC校准 
	ADC_ResetCalibration(ADC1);// 软件置1
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);// 硬件清零
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1) == SET);
}

uint16_t get_Simple_ADC1_Single_Channel_Value(uint8_t ADC_Channel_x){
		// 加入规则组
	ADC_RegularChannelConfig(ADC1,ADC_Channel_x,1,ADC_SampleTime_239Cycles5);
	// 软件触发转换
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);
	// 转换结束EOC（end of convert）置1
	// 读取ADC_DR时EOC硬件自动清除
	return ADC_GetConversionValue(ADC1);
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
