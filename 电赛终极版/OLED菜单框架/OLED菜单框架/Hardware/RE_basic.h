#ifndef _RE_BASIC_H
#define _RE_BAISC_H

#include "stdint.h"

#define key1 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)
#define key2 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)

#define LED_OPEN GPIO_ResetBits(GPIOC, GPIO_Pin_14);
#define LED_OFF  GPIO_SetBits(GPIOC, GPIO_Pin_14);

#define BEEP_OPRN GPIO_SetBits(GPIOC, GPIO_Pin_13);
#define BEEP_OFF  GPIO_ResetBits(GPIOC, GPIO_Pin_13);

void led_Init(void);
void beep_Init(void);
void key_Init(void);
void independent_dog(void);
void windows_dog(void);
uint8_t read_key(void);


#endif
