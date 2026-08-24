#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "LED.h"
#include "IC.h"
#include "fuwei.h"
uint8_t i;
uint8_t KeyNum=0;
uint8_t Address;
uint8_t Command;
int main(void)
{
 
	OLED_Init();
	LED_Init();
	Key_Init();
	IC_Init();
//	PWM_ON();
		LED1_ON();
		LED2_ON();
		LED3_ON();
		LED4_ON();
		LED5_ON();
		LED6_ON();
		LED7_ON();
		LED8_ON();
		LED9_ON();
		LED10_ON();
		LED11_ON();
		LED12_ON();
		LED13_ON();
		LED14_ON();
		LED15_ON();
		LED16_ON();
		int bibi;
	while (1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码
			}
	
		if(Command==0x41)
		 {						
			 KeyNum=Key_GetNum();
			 if(KeyNum!=0){bibi=KeyNum;}
		 }
				if(bibi==1)
			{	
				
				if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码
			}
			PWM_Init();
			while(bibi==1)
			{
			IR_SendNEC(0xFF, 0x01);
			LED1_OFF();	
			if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码
				
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
			
			}
					
			}
		
			
			
				if(KeyNum==2)
			{	
				PWM_Init();
				while(KeyNum==2)
			{
					IR_SendNEC(0xFF, 0x02);
					LED2_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
			}
				
			}
			
				if(KeyNum==3)
			{	

				PWM_Init();
				while(KeyNum==3)
				{
					IR_SendNEC(0xFF, 0x03);
					LED3_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}

			if(KeyNum==4)
			{	
				PWM_Init();
				while(KeyNum==4)
				{
					IR_SendNEC(0xFF, 0x04);
					LED4_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==5)
			{	
				PWM_Init();
				while(KeyNum==5)
				{
					IR_SendNEC(0xFF, 0x05);
					LED5_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==6)
			{	
				PWM_Init();
				while(KeyNum==6)
				{
					IR_SendNEC(0xFF, 0x06);
					LED6_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==7)
			{	
				PWM_Init();
				while(KeyNum==7)
				{
					IR_SendNEC(0xFF, 0x07);
					LED7_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==8)
			{	
				PWM_Init();
				while(KeyNum==8)
				{
					IR_SendNEC(0xFF, 0x08);
					LED8_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==9)
			{	
				PWM_Init();
				while(KeyNum==9)
				{
					IR_SendNEC(0xFF, 0x09);
					LED9_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==10)
			{	
				PWM_Init();
				while(KeyNum==10)
				{
					IR_SendNEC(0xFF, 0x10);
					LED10_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==11)
			{	
				PWM_Init();
				while(KeyNum==11)
				{
					IR_SendNEC(0xFF, 0x11);
					LED11_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==12)
			{	
				PWM_Init();
				while(KeyNum==12)
				{
					IR_SendNEC(0xFF, 0x12);
					LED12_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==13)
			{	
				PWM_Init();
				while(KeyNum==13)
				{
					IR_SendNEC(0xFF, 0x13);
					LED13_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==14)
			{	
				PWM_Init();
				while(KeyNum==14)
				{
					IR_SendNEC(0xFF, 0x14);
					LED14_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==15)
			{	
				PWM_Init();
				while(KeyNum==15)
				{
					IR_SendNEC(0xFF, 0x15);
					LED15_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
			
			if(KeyNum==16)
			{	
				PWM_Init();
				while(KeyNum==16)
				{
					IR_SendNEC(0xFF, 0x16);
					LED16_OFF();
					if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Address=IR_GetAddress();		//获取地址码
				Command=IR_GetCommand();		//获取命令码

					
			}
			if(Command ==0x44)
			{
			soft_reset_do();
			}
				}
				
			}
		
	}	
}
