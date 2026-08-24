#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"

uint8_t KeyNum = 0;
uint8_t count=0;

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1  | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

}

uint8_t Key_GetNum(void)
{
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0) 
	{	
		Delay_ms(140);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
		{
		return 1; // 按键1按下，返回1
		}
	}
	
    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0) 
	{	
		Delay_ms(140);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0)
		{
		return 2;// 按键2按下，返回2 
		}
	} 
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == 0) 
	{	
		Delay_ms(140);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == 0)
		{
		return 3;// 按键3按下，返回3
		}
	} 
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 0) 
	{	
		Delay_ms(140);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 0)
		{
		return 4;// 按键4按下，返回4
		}
	} 
		
    return 0; // 如果没有任何按键被按下，则返回0
	
}

uint8_t Key1_GetNum(void)
{
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0);
		Delay_ms(20);
		count = 5;
	}
	
	return count;
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

