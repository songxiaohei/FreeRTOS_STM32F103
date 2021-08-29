#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	
	//PB3��PB4��PA13��PA14��PA15 Ҫ�뵱����ͨIO��ʹ�ã��ͱ���ʹ�������ù����е���ӳ�䡣��˾���Ҫ����������������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);//��ʱ�������д򿪸���ʱ��
	/*
	������õ����е�������ŵ�����ͨIO�ڣ���ô����������е���ӳ������ӦдΪGPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE); 
	�������PB3��PB4��PA15����ͨIO��PA13&14����SWD���ԣ�����ӳ������ӦдΪGPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	ͬ�������ֻ��PB4��Ϊ��ͨIO�ڵ������
	*/
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//��PB3��PB4��PA15����ͨIO��PA13&14����SWD����
	
	
		RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//����Ϊ��������ģʽ
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = KEY2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//����Ϊ��������ģʽ
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(KEY3_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = KEY3_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//����Ϊ��������ģʽ
	GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStruct);
	
	
	/*���ú���ѭ��ģ��ܽ�*/
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
		// ���ּ��
		while( (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON ) && (i == 2));
		return 1;
	}
	else return 0;
}

