#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/*LED管脚初始化*/
	
	//PB3，PB4，PA13，PA14，PA15 要想当做普通IO口使用，就必须使用它复用功能中的重映射。因此就需要这样的两步操作：
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);//在时钟配置中打开复用时钟
	/*
	如果你用到所有的五个引脚当做普通IO口，那么上述步骤二中的重映射配置应写为GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE); 
	如果你用PB3，PB4，PA15做普通IO，PA13&14用于SWD调试，则重映射配置应写为GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	同理可配置只用PB4可为普通IO口的情况。
	*/
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//用PB3，PB4，PA15做普通IO，PA13&14用于SWD调试
	
	
	RCC_APB2PeriphClockCmd(BOARD_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = BOARD_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed =   GPIO_Speed_50MHz;
	GPIO_Init(BOARD_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(BLUE_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = BLUE_GPIO_PIN;
	GPIO_Init(BLUE_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(RED_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = RED_GPIO_PIN;
	GPIO_Init(RED_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(YELLOW_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = YELLOW_GPIO_PIN;
	GPIO_Init(YELLOW_GPIO_PORT, &GPIO_InitStruct);
	
	
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED1_GPIO_PIN;
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(LED2_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(LED3_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED3_GPIO_PIN;
	GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);
	 BOARD_OFF(); 
	 RED_OFF();BLUE_OFF();YELLOW_OFF();
	 LED1_OFF();LED2_OFF();LED3_OFF();
		
}
