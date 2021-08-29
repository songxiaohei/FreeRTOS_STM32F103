#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "stm32f10x_it.h"
#include "sys.h"
#include "bsp_usart.h"
#include "bsp_led.h"
#include "bsp_exti.h"
#include "bsp_key.h"

int main(void)
{
		uint32_t cnt = 0;
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	USART_Config();//��ʼ������
	LED_GPIO_Config();//��ʼ��LED
//	EXTI_Config();//�ⲿ�жϳ�ʼ��
	KEY_GPIO_Config();//������ʼ��
	while(1)
	{
//		
//			delay_ms(500);
//		 
//			delay_ms(500);
		if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN))
		{
			BOARD_ON(); 
			printf("cnt = %d\r\n",cnt++);
		}
		else
		{
		 BOARD_OFF(); 
		}
			
	}
}


