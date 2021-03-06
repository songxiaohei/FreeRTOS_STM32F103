#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"
/*定义核心板LED*/
#define BOARD_GPIO_PORT GPIOC
#define BOARD_GPIO_CLK  RCC_APB2Periph_GPIOC
#define BOARD_GPIO_PIN GPIO_Pin_13

#define BLUE_GPIO_PORT GPIOC
#define BLUE_GPIO_CLK  RCC_APB2Periph_GPIOC
#define BLUE_GPIO_PIN GPIO_Pin_13


#define RED_GPIO_PORT GPIOC
#define RED_GPIO_CLK  RCC_APB2Periph_GPIOC
#define RED_GPIO_PIN GPIO_Pin_13


#define YELLOW_GPIO_PORT GPIOC
#define YELLOW_GPIO_CLK  RCC_APB2Periph_GPIOC
#define YELLOW_GPIO_PIN GPIO_Pin_13


#define LED1_GPIO_PORT GPIOC
#define LED1_GPIO_CLK  RCC_APB2Periph_GPIOC
#define LED1_GPIO_PIN GPIO_Pin_13

#define LED2_GPIO_PORT GPIOC
#define LED2_GPIO_CLK  RCC_APB2Periph_GPIOC
#define LED2_GPIO_PIN GPIO_Pin_13

#define LED3_GPIO_PORT GPIOC
#define LED3_GPIO_CLK  RCC_APB2Periph_GPIOC
#define LED3_GPIO_PIN GPIO_Pin_13

#define    BOARD_ON()   GPIO_ResetBits(BOARD_GPIO_PORT,BOARD_GPIO_PIN)
#define    BOARD_OFF()  GPIO_SetBits(BOARD_GPIO_PORT,BOARD_GPIO_PIN)

#define    RED_ON()   GPIO_ResetBits(RED_GPIO_PORT,RED_GPIO_PIN)
#define    RED_OFF()  GPIO_SetBits(RED_GPIO_PORT,RED_GPIO_PIN)

#define    BLUE_ON()   GPIO_ResetBits(BOARD_GPIO_PORT,BLUE_GPIO_PIN)
#define    BLUE_OFF()  GPIO_SetBits(BOARD_GPIO_PORT,BLUE_GPIO_PIN)


#define    YELLOW_ON()   GPIO_ResetBits(YELLOW_GPIO_PORT,YELLOW_GPIO_PIN)
#define    YELLOW_OFF()  GPIO_SetBits  (YELLOW_GPIO_PORT,YELLOW_GPIO_PIN)


#define    LED1_ON()  GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define    LED1_OFF() GPIO_SetBits  (LED1_GPIO_PORT,LED1_GPIO_PIN)

#define    LED2_ON()  GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define    LED2_OFF() GPIO_SetBits  (LED2_GPIO_PORT,LED2_GPIO_PIN)

#define    LED3_ON()  GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define    LED3_OFF() GPIO_SetBits  (LED3_GPIO_PORT,LED3_GPIO_PIN)


#define DigitalToggle(p,i) {p->ODR ^=i;} //输出反转状态
#define BOARD_TOGGLE() DigitalToggle(BOARD_GPIO_PORT,BOARD_GPIO_PIN)
extern void LED_GPIO_Config(void);
#endif
