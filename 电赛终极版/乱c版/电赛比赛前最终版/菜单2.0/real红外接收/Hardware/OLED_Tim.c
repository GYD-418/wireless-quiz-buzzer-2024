#include "stm32f10x.h"                  // Device header
#include "usart.h"

static float s=0;
static uint16_t x=30;

void TIM3_Configure(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Prescaler=720-1;
	TIM_TimeBaseInitStructure.TIM_Period=10000-1;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,DISABLE);

	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStructure);

	TIM_Cmd(TIM3,DISABLE);
	s=0.1;
	x=30;
}	
	
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
		s=s-1;
		if(s<0){x--;s=9;}
		if(x==0)
		{
			printf("µ¹¼ÆÊ±Í£Ö¹");
			TIM_Cmd(TIM3,DISABLE);
			TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,DISABLE);
		}
	}
	
}

uint16_t second1_Get(void)
{
	if(x==0)
	{
		x=0;
		s=0;
	}
	return x;
}

uint16_t second2_Get(void)
{
	if(s==0)
	{
		s=0;
	}
	return s;
}
