#ifndef __BSP_USART2_H
#define __BSP_USART2_H

#include "stm32f10x.h"
#include <stdio.h>
#include "bsp_usart.h"



//串口2-USART2
//    USART2
#define  USART2_CLK                RCC_APB1Periph_USART2
#define  USART2_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  USART2_BAUDRATE           9600

// USART GPIO 引脚宏定义
#define  USART2_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  USART2_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  USART2_TX_GPIO_PORT       GPIOA  
#define  USART2_TX_GPIO_PIN        GPIO_Pin_2
#define  USART2_RX_GPIO_PORT       GPIOA
#define  USART2_RX_GPIO_PIN        GPIO_Pin_3

#define  USART2_IRQ                USART2_IRQn
#define  USART2_IRQHandler         USART2_IRQHandler

extern void USART2_Config(void);

#endif  /* __BSP_USART2_H */

