#ifndef _SYS_H
#define _SYS_H
#include "stm32f10x.h" 
#include <string.h>
#include <stdlib.h>
#define ON  1
#define OFF 0
extern void delay_ms(uint32_t count);
extern void delay_us(uint32_t nus);
#endif
