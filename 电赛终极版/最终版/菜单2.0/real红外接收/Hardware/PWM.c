#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void PWM_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);  
	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //ÍÆÍìÊä³ö  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	
	TIM_TimeBaseStructure.TIM_Period = 99; 
	TIM_TimeBaseStructure.TIM_Prescaler =18; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); 
	
	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 30;	  
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  
 
	TIM_ARRPreloadConfig(TIM2, ENABLE);			 
  TIM_Cmd(TIM2, ENABLE);
}
void PWM_ON(void)
{
	TIM_Cmd(TIM2, ENABLE);
}
void PWM_OFF(void)
{
	TIM_Cmd(TIM2, DISABLE);
}
void IR_SendBit(uint8_t bit)
{
    if (bit==1) 
		{
			  PWM_ON();
        Delay_us (560);
			  PWM_OFF();
        Delay_us (1690);
    } 
		else 
		{
        PWM_ON();
        Delay_us(560);
        PWM_OFF();
        Delay_us(560);
    }
}
void IR_SendY(void)
{
	PWM_ON();
	Delay_us(9000);
	PWM_OFF();
	Delay_us(4500);
}
void IR_SendByte(uint8_t byte)
{
    for (int i = 0; i < 8; i++) 
	  {
        IR_SendBit((byte >> i) & 0x01);
    }
}
void IR_SendNEC(uint8_t address, uint8_t command)
{
	IR_SendY();
  IR_SendByte(address);
  IR_SendByte(~address);
  IR_SendByte(command);
  IR_SendByte(~command);
}
