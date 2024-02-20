#ifndef __EXTI_TRIGGER_H
#define __EXTI_TRIGGER_H
/*
//Structure Init Template:

EXTI_Trigger_TypeDef EXTI_Trigger_1;

int main(){

	EXTI_Trigger_1.GPIO = GPIOB;
	EXTI_Trigger_1.Pin = GPIO_Pin_5;
	EXTI_Trigger_1.EXTIMode = EXTI_Mode_Interrupt;
	EXTI_Trigger_1.EXTITrigger = EXTI_Trigger_Rising_Falling;
	EXTI_Trigger_1.NVIC_IRQChannelPreemptionPriority = 0;
	EXTI_Trigger_1.NVIC_IRQChannelSubPriority = 0; 

	EXTI_Trigger_Init(&EXTI_Trigger_1,NVIC_PriorityGroup_2);
}

*/
typedef struct{
	GPIO_TypeDef* GPIO;
	uint16_t Pin;
	
	EXTIMode_TypeDef EXTIMode;
	/*
	EXTI_Mode_Interrupt = 0x00,
	EXTI_Mode_Event = 0x04
	*/
	
	EXTITrigger_TypeDef EXTITrigger;
	/*
	EXTI_Trigger_Rising = 0x08,
	EXTI_Trigger_Falling = 0x0C,
	EXTI_Trigger_Rising_Falling = 0x10
	*/
	
	uint8_t NVIC_IRQChannelPreemptionPriority;  /*!< Specifies the pre-emption priority for the IRQ channel
                                                   specified in NVIC_IRQChannel. This parameter can be a value
                                                   between 0 and 15 as described in the table @ref NVIC_Priority_Table */

    uint8_t NVIC_IRQChannelSubPriority;         /*!< Specifies the subpriority level for the IRQ channel specified
                                                   in NVIC_IRQChannel. This parameter can be a value
                                                   between 0 and 15 as described in the table @ref NVIC_Priority_Table */
												   
} EXTI_Trigger_TypeDef;


void EXTI_Trigger_Init(EXTI_Trigger_TypeDef *EXTI_t,uint32_t NVIC_PriorityGroup);

// 在对应中断函数void EXTIx_IRQHandler(void){}里调用：
/* ( x = 0 ~ 4 , 9_5 , 15_10 )
void EXTIx_IRQHandler(void){
	EXTI_Trigger_Detect_Handler(&EXTI_Trigger_1,func);
}
*/
void EXTI_Trigger_Detect_Handler(EXTI_Trigger_TypeDef *EXTI_t,void (*callback)(void));



#endif
