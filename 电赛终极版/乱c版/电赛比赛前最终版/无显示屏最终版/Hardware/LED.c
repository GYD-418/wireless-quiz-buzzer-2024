#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_1 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_15 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
	GPIO_SetBits(GPIOC,GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_1 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_8 | GPIO_Pin_7);
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}


void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
}

void LED3_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void LED3_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

void LED4_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
}

void LED4_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
}

void LED5_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_6);
}

void LED5_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
}

void LED6_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
}

void LED6_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_7);
}

void LED7_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_9);
}

void LED7_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_9);
}

void LED8_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_11);
}

void LED8_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_11);
}

void LED9_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_12);
}

void LED9_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_12);
}

void LED10_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_8);
}

void LED10_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_8);
}

void LED11_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_7);
}

void LED11_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_7);
}

void LED12_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_5);
}

void LED12_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_5);
}

void LED13_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_4);
}

void LED13_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_4);
}

void LED14_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_1);
}

void LED14_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_1);
}

void LED15_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_11);
}

void LED15_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_11);
}

void LED16_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_12);
}

void LED16_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_12);
}
