#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "stm32f10x_it.h"
#include "sys.h"
#include "bsp_usart.h"
#include "bsp_led.h"
#include "bsp_exti.h"
#include "bsp_key.h"

int main(void)
{
		uint32_t cnt = 0;
	// 来到这里的时候，系统的时钟已经被配置成72M。
	USART_Config();//初始化串口
	LED_GPIO_Config();//初始化LED
//	EXTI_Config();//外部中断初始化
	KEY_GPIO_Config();//按键初始化
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


