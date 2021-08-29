#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	
	//PB3，PB4，PA13，PA14，PA15 要想当做普通IO口使用，就必须使用它复用功能中的重映射。因此就需要这样的两步操作：
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);//在时钟配置中打开复用时钟
	/*
	如果你用到所有的五个引脚当做普通IO口，那么上述步骤二中的重映射配置应写为GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE); 
	如果你用PB3，PB4，PA15做普通IO，PA13&14用于SWD调试，则重映射配置应写为GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	同理可配置只用PB4可为普通IO口的情况。
	*/
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//用PB3，PB4，PA15做普通IO，PA13&14用于SWD调试
	
	
		RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//设置为输入上拉模式
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = KEY2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//设置为输入上拉模式
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(KEY3_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = KEY3_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//设置为输入上拉模式
	GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStruct);
	
	
	/*配置红外循迹模块管脚*/
	RCC_APB2PeriphClockCmd(Left_HY_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = Left_HY_GPIO_PIN;
	GPIO_Init(Left_HY_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(Right_HY_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = Right_HY_GPIO_PIN;
	GPIO_Init(Right_HY_GPIO_PORT, &GPIO_InitStruct);
}

uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	uint8_t i =0;
	if( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON )
	{
		i++;
		// 松手检测
		while( (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON ) && (i == 2));
		return 1;
	}
	else return 0;
}

