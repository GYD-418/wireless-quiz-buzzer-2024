#include "stm32f10x.h"                  // Device header
#include "usart.h"

static uint16_t j=0;
static uint16_t k=0;

void TIM4_Configure(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Prescaler=720-1;
	TIM_TimeBaseInitStructure.TIM_Period=10000-1;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,ENABLE);

	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStructure);

	TIM_Cmd(TIM4,ENABLE);
	j=0;
	k=00;
}	
	
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)!=RESET)
	{
		j++;
		if(j==10){j=0;k++;}
		if(k==30)
		{
			printf("Õý¼ÆÊ±Í£Ö¹");
			TIM_Cmd(TIM4,DISABLE);
			TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);
		}
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
}

uint16_t second3_Get(void)
{
	if(k==30)
	{
		k=30;
		j=0;
	}
	return k;
}

uint16_t second4_Get(void)
{
	if(j==10)
	{
		j=0;
	}
	return j;
}
