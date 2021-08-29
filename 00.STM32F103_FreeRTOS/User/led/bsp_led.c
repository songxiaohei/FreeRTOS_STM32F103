#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/*LED�ܽų�ʼ��*/
	
	//PB3��PB4��PA13��PA14��PA15 Ҫ�뵱����ͨIO��ʹ�ã��ͱ���ʹ�������ù����е���ӳ�䡣��˾���Ҫ����������������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);//��ʱ�������д򿪸���ʱ��
	/*
	������õ����е�������ŵ�����ͨIO�ڣ���ô����������е���ӳ������ӦдΪGPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE); 
	�������PB3��PB4��PA15����ͨIO��PA13&14����SWD���ԣ�����ӳ������ӦдΪGPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	ͬ�������ֻ��PB4��Ϊ��ͨIO�ڵ������
	*/
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//��PB3��PB4��PA15����ͨIO��PA13&14����SWD����
	
	
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
