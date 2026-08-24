#include "stm32f10x.h"                 
 
uint16_t IR_Time;
uint8_t IR_State=1;
uint8_t IR_Data[4];
uint8_t IR_pData;
uint8_t IR_DataFlag;
uint8_t IR_RepeatFlag;
uint8_t IR_Address;
uint8_t IR_Command;
 

void IC_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM1);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 65536 - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);

	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;  //通道1
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Falling; //下降沿捕获
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM1, &TIM_ICInitStructure);

	TIM_SelectInputTrigger(TIM1, TIM_TS_TI1FP1);
	TIM_SelectSlaveMode(TIM1, TIM_SlaveMode_Reset);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;  //TIM1中断
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);    	

	TIM_ITConfig(TIM1,TIM_IT_CC1,ENABLE);	
    
    TIM_Cmd(TIM1, ENABLE);
}

uint32_t IC_GetFreq(void)
{
	return (TIM_GetCapture1(TIM1) + 1);
}


void TIM1_CC_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM1,TIM_IT_CC1) == SET)
	{
		if(IR_State==1)		
		{
			IR_Time = IC_GetFreq();
			
			if(IR_Time>13500-500 && IR_Time<13500+500)
			{
				IR_State=2;			
			}
			
			else if(IR_Time>11250-500 && IR_Time<11250+500)
			{
				IR_RepeatFlag=1;	
				IR_State=1;			
			}
			else					
			{
				IR_State=1;			
			}
		}
		else if(IR_State==2)		
		{
			IR_Time = IC_GetFreq();
			
			if(IR_Time>1120-500 && IR_Time<1120+500)
			{
				IR_Data[IR_pData/8]&=~(0x01<<(IR_pData%8));	
				IR_pData++;			
			}
			
			else if(IR_Time>2240-500 && IR_Time<2240+500)
			{
				IR_Data[IR_pData/8]|=(0x01<<(IR_pData%8));	
				IR_pData++;			
			}
			else					
			{
				IR_pData=0;			
				IR_State=1;			
			}
			if(IR_pData>=32)		
			{
				IR_pData=0;			
                
				if((IR_Data[0] & IR_Data[1])==0 && (IR_Data[2] & IR_Data[3])==0)
				{
					IR_Address=IR_Data[0];	
					IR_Command=IR_Data[2];
					IR_DataFlag=1;	
				}
				IR_State=1;			
			}
		}
	}
	TIM_ClearITPendingBit(TIM1,TIM_IT_CC1);
}
 
// 红外遥控获取收到数据帧标志位
uint8_t IR_GetDataFlag(void)
{
	if(IR_DataFlag)
	{
		IR_DataFlag=0;
		return 1;
	}
	return 0;
}
 
// 红外遥控获取收到连发帧标志位
uint8_t IR_GetRepeatFlag(void)
{
	if(IR_RepeatFlag)
	{
		IR_RepeatFlag=0;
		return 1;
	}
	return 0;
}
 
// 红外遥控获取收到的地址数据
uint8_t IR_GetAddress(void)
{
	return IR_Address;
}
 
// 红外遥控获取收到的命令数据
uint8_t IR_GetCommand(void)
{
	return IR_Command;
}
