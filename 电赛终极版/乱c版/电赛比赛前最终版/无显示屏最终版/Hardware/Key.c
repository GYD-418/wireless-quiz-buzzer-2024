#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1|GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_0 | GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0);
		Delay_ms(20);
		KeyNum = 1;
	}
	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
		Delay_ms(20);
		KeyNum = 2;
	}
	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0);
		Delay_ms(20);
		KeyNum = 3;
	}
	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == 0);
		Delay_ms(20);
		KeyNum = 4;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 0);
		Delay_ms(20);
		KeyNum = 5;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 0);
		Delay_ms(20);
		KeyNum = 6;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0);
		Delay_ms(20);
		KeyNum = 7;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0);
		Delay_ms(20);
		KeyNum = 8;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0);
		Delay_ms(20);
		KeyNum = 9;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0);
		Delay_ms(20);
		KeyNum = 10;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0);
		Delay_ms(20);
		KeyNum = 11;
	}
	
	
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_10) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_10) == 0);
		Delay_ms(20);
		KeyNum = 12;
	}	
	
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3) == 0);
		Delay_ms(20);
		KeyNum = 13;
	}	
	
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2) == 0);
		Delay_ms(20);
		KeyNum = 14;
	}	
	
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0) == 0);
		Delay_ms(20);
		KeyNum = 15;
	}	
	
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0);
		Delay_ms(20);
		KeyNum = 16;
	}	
	return KeyNum;
}


//#include "stm32f10x.h"                  // Device header
//#include "delay.h"
//#include "key.h"


//extern uint32_t flag_auto_manu;//选择自动模式或者手动模式的标志位
//extern uint32_t flag_in_system;
//extern uint32_t flag_break_mode;
//extern uint32_t flag_led_on_off;

//void key_mode_option_init(void)//PA2引脚初始化
//{
//	GPIO_InitTypeDef    GPIO_InitStructure;
//	EXTI_InitTypeDef      EXTI_InitStructure;
//	NVIC_InitTypeDef     NVIC_InitStructure;
//	
//	//开启时钟
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	
//	//配置GPIO
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	
//	//配置AFIO
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2);

//	
//	//配置EXIT
//	EXTI_InitStructure.EXTI_Line=EXTI_Line2;
//	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
//	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;	
//	EXTI_Init(&EXTI_InitStructure);
//	
//	
//	//配置NVIC
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
//	 NVIC_Init(&NVIC_InitStructure);
//}


//void key_mode_in_init(void)//PA3引脚初始化
//{
//	GPIO_InitTypeDef    GPIO_InitStructure;
//	EXTI_InitTypeDef      EXTI_InitStructure;
//	NVIC_InitTypeDef     NVIC_InitStructure;
//	
//	//开启时钟
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	
//	//配置GPIO
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	
//	//配置AFIO
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);
//	
//	
//	//配置EXIT
//	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
//	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
//	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;	
//	EXTI_Init(&EXTI_InitStructure);
//	
//	
//	//配置NVIC
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	NVIC_InitStructure.NVIC_IRQChannel=EXTI3_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
//	NVIC_Init(&NVIC_InitStructure);
//}


//void EXTI2_IRQHandler(void)//PA2引脚中断
//{
//	delay_ms(10);
//	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2) == 0)
//	{
//		flag_auto_manu=!flag_auto_manu;//触发中断以后，手动模式和自动模式相互切换
//		flag_break_mode=1;//如果已经进入模式以后，按下这个键可以退出，重新进入模式选择界面
//	}
//		
//	
//	EXTI_ClearITPendingBit(EXTI_Line2);//清除中断标志位
//}


//void EXTI3_IRQHandler(void)//PA3引脚中断
//{
//	delay_ms(10);
//	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3) == 0)
//	{
//		flag_in_system=1;//按下这个键后，可以进入这个模式
//		flag_led_on_off=!flag_led_on_off;//当进入手动模式以后，按下这个键，可以切换LED灯的亮灭
//	}
//		
//	EXTI_ClearITPendingBit(EXTI_Line3);
//}




