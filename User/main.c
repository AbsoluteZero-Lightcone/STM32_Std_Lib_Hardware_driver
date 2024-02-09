#include "stm32f10x.h"
#include "STM32F103C_Dev_Board_V1.h"
#include "Delay.h"

int main(){
	STM32F103C_Dev_Board_Init();
	OLED_ShowString(&OLED1,2,1,"Hello World!");
	OLED_ShowString(&OLED1,1,1,"OLED1");
	OLED_ShowString(&OLED2,1,1,"OLED2");
	OLED_ShowString(&OLED3,1,1,"OLED3");
	OLED_ShowString(&OLED4,1,1,"OLED4");
	
	uint64_t i= 0;
	while(1){
		OLED_ShowNum(&OLED2,2,1,i++,10);
		OLED_ShowNum(&OLED3,2,1,i++,10);
		OLED_ShowNum(&OLED4,2,1,i++,10);
	}
}
