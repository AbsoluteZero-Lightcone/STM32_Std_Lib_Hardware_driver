#ifndef __ENCODER_H
#define __ENCODER_H
/*
//Structure Init Template:

Encoder_TypeDef Encoder_1;

int main(){
	
	Encoder_1.OutputA_GPIO = GPIOB;
	Encoder_1.OutputA_Pin = GPIO_Pin_8;
	Encoder_1.OutputB_GPIO = GPIOB;
	Encoder_1.OutputB_Pin = GPIO_Pin_9;
	Encoder_1.Button_GPIO = GPIOB;
	Encoder_1.Button_Pin = GPIO_Pin_0;
	
	Encoder_Init(&Encoder_1,NVIC_PriorityGroup_2);	
}

*/
typedef struct{
	GPIO_TypeDef* OutputA_GPIO;
	uint16_t OutputA_Pin;
	GPIO_TypeDef* OutputB_GPIO;
	uint16_t OutputB_Pin;
	GPIO_TypeDef* Button_GPIO;
	uint16_t Button_Pin;
	int8_t cnt;
} Encoder_TypeDef;// whose instances need to create as a global variety.

void Encoder_Init(Encoder_TypeDef* Encoder_InitStruct,uint32_t NVIC_PriorityGroup);

int8_t getIncrement(Encoder_TypeDef* Encoder_InitStruct);

// 在对应中断函数void EXTIx_IRQHandler(void){}里调用：
/* ( x = 0 ~ 4 , 9_5 , 15_10 )
void EXTIx_IRQHandler(void){
	Interrupt_Output_A(&Encoder_InitStruct);
	Interrupt_Output_B(&Encoder_InitStruct);
}
*/
void Interrupt_Output_A_Detect_Handler(Encoder_TypeDef* Encoder_InitStruct);
void Interrupt_Output_B_Detect_Handler(Encoder_TypeDef* Encoder_InitStruct);

#endif
