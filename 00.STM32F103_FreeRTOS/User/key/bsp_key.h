#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f10x.h"


#define  KEY_ON      0
#define  KEY_OFF     1
//1���⴫����
#define KEY1_GPIO_PORT GPIOA
#define KEY1_GPIO_CLK  RCC_APB2Periph_GPIOA
#define KEY1_GPIO_PIN GPIO_Pin_15
//2���⴫����
#define KEY2_GPIO_PORT GPIOB
#define KEY2_GPIO_CLK  RCC_APB2Periph_GPIOB
#define KEY2_GPIO_PIN GPIO_Pin_12
//3���⴫����
#define KEY3_GPIO_PORT GPIOB
#define KEY3_GPIO_CLK  RCC_APB2Periph_GPIOB
#define KEY3_GPIO_PIN GPIO_Pin_13

//��������ʱ����͵�ƽ����������ʱ����ߵ�ƽ
#define Left_HY_GPIO_PORT GPIOB
#define Left_HY_GPIO_CLK  RCC_APB2Periph_GPIOB
#define Left_HY_GPIO_PIN GPIO_Pin_14


#define Right_HY_GPIO_PORT GPIOB
#define Right_HY_GPIO_CLK  RCC_APB2Periph_GPIOB
#define Right_HY_GPIO_PIN GPIO_Pin_15


#define  Get_Left_HY_Value()    GPIO_ReadInputDataBit(Left_HY_GPIO_PORT, Left_HY_GPIO_PIN)
#define  Get_Right_HY_Value()   GPIO_ReadInputDataBit(Right_HY_GPIO_PORT, Right_HY_GPIO_PIN)


#define  Get_Key1_Value()   GPIO_ReadInputDataBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN)
#define  Get_Key2_Value()   GPIO_ReadInputDataBit(KEY2_GPIO_PORT, KEY2_GPIO_PIN)
#define  Get_Key3_Value()   GPIO_ReadInputDataBit(KEY3_GPIO_PORT, KEY3_GPIO_PIN)



extern void KEY_GPIO_Config(void);
extern uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
#endif
