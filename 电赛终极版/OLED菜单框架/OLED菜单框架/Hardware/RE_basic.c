#include <stm32f10x.h>
#include "RE_basic.h"
#include "delay.h"

void led_Init(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); 
		
		GPIO_InitTypeDef LED_Init; 
		LED_Init.GPIO_Mode = GPIO_Mode_Out_PP;
		LED_Init.GPIO_Pin = GPIO_Pin_14;
		LED_Init.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(GPIOC,&LED_Init);
		GPIO_SetBits(GPIOC, GPIO_Pin_14);
}

void beep_Init(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); 
		
		GPIO_InitTypeDef beep_Init; 
		beep_Init.GPIO_Mode = GPIO_Mode_Out_PP;
		beep_Init.GPIO_Pin = GPIO_Pin_13;
		beep_Init.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(GPIOC,&beep_Init);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
}

void key_Init(void)
{ 
		 GPIO_InitTypeDef key_Init; 
	
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE); 
		 key_Init.GPIO_Pin=GPIO_Pin_13|GPIO_Pin_14;
		 key_Init.GPIO_Mode=GPIO_Mode_IPU;
		 key_Init.GPIO_Speed= GPIO_Speed_50MHz; 
	
		 GPIO_Init(GPIOB, &key_Init);
}

uint8_t read_key(void)
{
    if(key1 == 0) 
	{	
		delay_ms(140);
		while(key1 == 0)
		{
		return 1; // 按键1按下，返回1
		}
	}
    if(key2 == 0) 
	{	
		delay_ms(140);
		while(key2 == 0)
		{
		return 2;// 按键2按下，返回2 
		}
	} 
    return 0; // 如果没有任何按键被按下，则返回0
}

void independent_dog(void)
{
		IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);	//独立看门狗写使能
		IWDG_SetPrescaler(IWDG_Prescaler_16);			//设置预分频为16
		IWDG_SetReload(2499);							//设置重装值为2499，独立看门狗的超时时间为1000ms
		IWDG_ReloadCounter();							//重装计数器，喂狗
		IWDG_Enable();									//独立看门狗使能
}
	
void windows_dog(void)
{
		/*开启时钟*/
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);	//开启WWDG的时钟
		/*WWDG初始化*/
		WWDG_SetPrescaler(WWDG_Prescaler_8);			//设置预分频为8
		WWDG_SetWindowValue(0x40 | 21);					//设置窗口值，窗口时间为30ms
		WWDG_Enable(0x40 | 54);							//使能并第一次喂狗，超时时间为50ms
}
