#include "stm32f10x.h"                  // Device header
#include "menu.h"
#include "OLED.h"
#include "Key.h"
#include "Delay.h"
#include "PWM.h"
#include "IC.h"
#include "usart.h"
#include "OLED_Tim.h"
#include "TIM.h"

int sb1=0;int sb2; int sb3;int sb4; int sb5;int sb6; int sb7;int sb8; int sb9;int sb10; int sb11;int sb12; int sb13;int sb14; int sb15;int sb16;
int sb17;int sb18; int sb19;int sb20; int sb21;int sb22; int sb23;int sb24; int sb25;int sb26; int sb27;int sb28; int sb29;int sb30; int sb31;int sb32;

int count1=0; int count2=0; int count3=0; int count4=0; int count5=0; int count6=0; int count7=0; int count8=0;
int count9=0; int count10=0; int count11=0; int count12=0; int count13=0; int count14=0; int count15=0; int count16=0;
uint16_t x=30;
float s=0;
uint8_t j=0;
uint8_t k=0;

int menu_start()
{	
	uint8_t Command;
	int menu1_flag=1;         //选择
	uint8_t KeyNum;
	
	IC_Init();
	OLED_Init();
	Key_Init();
	USART2_Init(9600);
	OLED_ShowString(1,2,"time start:");
	OLED_ShowString(2,2,"Close Light:");
	OLED_ShowString(3,2,"grade menu1:");  
	OLED_ShowString(4,2,"grade menu2:"); 
	
		while(1)
		{
				if(IR_GetDataFlag() || IR_GetRepeatFlag())	
			{
				Command=IR_GetCommand();		//获取选手命令码
				OLED_ShowHexNum(2,8,(char)Command,2);	//显示选手		
			}	
			
			
			KeyNum=Key_GetNum();
			if(KeyNum==1||res==1)//控制键
		{
			menu1_flag++;
		Delay_ms(1000);
		}
		
			if(menu1_flag==6) menu1_flag=1;	
		
		if(KeyNum==2||res==2)//选择键
		{
			OLED_Clear();
			return menu1_flag;
		}
		
			switch(menu1_flag)
			{
				case 1:
				{
					OLED_ShowString(1,1,"*");
					OLED_ShowString(2,1," ");
					OLED_ShowString(3,1," ");
					OLED_ShowString(4,1," ");
					OLED_ShowString(5,1," ");
				}break;
				case 2:
				{
					OLED_ShowString(1,1," ");
					OLED_ShowString(2,1,"*");
					OLED_ShowString(3,1," ");
					OLED_ShowString(4,1," ");
					OLED_ShowString(5,1," ");
				}break;
				case 3:
				{
					OLED_ShowString(1,1," ");
					OLED_ShowString(2,1," ");
					OLED_ShowString(3,1,"*");
					OLED_ShowString(4,1," ");
					OLED_ShowString(5,1," ");
				}break;
				case 4:
				{
					OLED_ShowString(1,1," ");
					OLED_ShowString(2,1," ");
					OLED_ShowString(3,1," ");
					OLED_ShowString(4,1,"*");
					OLED_ShowString(5,1," ");
				}break;
				case 5:
				{
					OLED_ShowString(1,1," ");
					OLED_ShowString(2,1," ");
					OLED_ShowString(3,1," ");
					OLED_ShowString(4,1," ");
					OLED_ShowString(5,1,"*");
				}break;
			}
		}
}
int menu1()
{
	int fs1=0;int fs2=0;
	
	OLED_Init();
	IC_Init();
	Key_Init();
	uart_init(9600);	 //串口初始化为9600
	USART2_Init(9600);
	TIM3_Configure();
//	TIM4_Configure();
	PWM_Init();
	
	uint8_t Command;
	uint8_t KeyNum;

	OLED_ShowString(1,1,"Responder game!");
	OLED_ShowString(3,1,"time:");
	OLED_ShowString(2,1,"Player:");
	
	while(1)
	{					
			x=second1_Get();
			s=second2_Get();
			k=second3_Get();
			j=second4_Get();
		
		if(IR_GetDataFlag() || IR_GetRepeatFlag())	
		{
			Command=IR_GetCommand();		//获取选手命令码
			OLED_ShowHexNum(2,8,(char)Command,2);	//显示选手		
			OLED_ShowString(3,12,"FLASH");
		}
		
		KeyNum=Key_GetNum();
		
		if(KeyNum==2 || res==2)				//抢答开始
		{
			for(int i=0;i<10;i++)
{
			PWM_Init();
			IR_SendNEC(0xff,0x41);
			TIM4_Configure();
}

//			if(IR_SendNEC(0xff,0x41)){}

		}

		if(KeyNum==1||res==1)		//回到主菜单
		{			
			count1=0;count2=0;count3=0;count4=0;count5=0;count6=0;count7=0;count8=0;
			count9=0;count10=0;count11=0;count12=0;count13=0;count14=0;count15=0;count16=0;
			return 0;			
		}
		
		if(Command==0x01){if(count1<1){count1++;printf("一号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x02){if(count2<1){count2++;printf("二号"); Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x03){if(count3<1){count3++;printf("三号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x04){if(count4<1){count4++;printf("四号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x05){if(count5<1){count5++;printf("五号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x06){if(count6<1){count6++;printf("六号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x07){if(count7<1){count7++;printf("七号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x08){if(count8<1){count8++;printf("八号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x09){if(count9<1){count9++;printf("九号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x10){if(count10<1){count10++;printf("十号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x11){if(count11<1){count11++;printf("十一号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x12){if(count12<1){count12++;printf("十二号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x13){if(count13<1){count13++;printf("十三号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x14){if(count14<1){count14++;printf("十四号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x15){if(count15<1){count15++;printf("十五号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x16){if(count16<1){count16++;printf("十六号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}

		OLED_ShowNum(3,6,k,2);			//真计时
		OLED_ShowString(3,8,".");
		OLED_ShowNum(3,9,j,1);		
		
		OLED_ShowNum(2,11,x,2);			//倒计时
		OLED_ShowString(2,13,".");
		OLED_ShowNum(2,14,s,1);
		
		if(KeyNum==3||res==3)
		{
			TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM3,DISABLE);
			
			if(0<k && k<=9){fs1=30;}if(10<=k && k<=14){fs1=20;}if(15<=k && k<=19){fs1=15;}if(20<=k && k<=24){fs1=10;}if(25<=k && k<=29){fs1=5;}if(k==30){fs1=0;}
			if(x<=29 && x>=25){fs2=30;}if(x<=24 && x>=20){fs2=25;}if(x<=19 && x>=15){fs2=20;}if(x<=14 && x>=10){fs2=15;}if(x<=9 && x>=5){fs2=10;}if(x<=4 && x>=1){fs2=5;}if(x==0){fs2=0;}			
			
			if(Command==0x01){sb1=sb1+fs1+fs2;}	if(Command==0x02){sb3=sb3+fs1+fs2;}	if(Command ==0x03){sb5=sb5+fs1+fs2;}if(Command ==0x04){sb7=sb7+fs1+fs2;}
			if(Command ==0x05){sb9=sb9+fs1+fs2;}if(Command ==0x06){sb11=sb11+fs1+fs2;}if(Command ==0x07){sb13=sb13+fs1+fs2;}if(Command ==0x08){sb15=sb15+fs1+fs2;}
			if(Command ==0x09){sb17=sb17+fs1+fs2;}if(Command ==0x10){sb19=sb19+fs1+fs2;}if(Command ==0x11){sb21=sb21+fs1+fs2;}if(Command ==0x12){sb23=sb23+fs1+fs2;}
      if(Command ==0x13){sb25=sb25+fs1+fs2;}if(Command ==0x14){sb27=sb27+fs1+fs2;}if(Command ==0x15){sb29=sb29+fs1+fs2;}if(Command ==0x16){sb31=sb31+fs1+fs2;}	
									
			OLED_ShowString(4,13,"+");			
			OLED_ShowNum(4,14,fs1+fs2,2);			
		}
		
		if(KeyNum==4||res==4)
		{
			TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM3,DISABLE);
			
			if(0<k && k<=9){fs1=30;}if(10<=k && k<=14){fs1=20;}if(15<=k && k<=19){fs1=15;}if(20<=k && k<=24){fs1=10;}if(25<=k && k<=29){fs1=5;}if(k==30){fs1=0;}
			if(x<=29 && x>=25){fs2=30;}if(x<=24 && x>=20){fs2=25;}if(x<=19 && x>=15){fs2=20;}if(x<=14 && x>=10){fs2=15;}if(x<=9 && x>=5){fs2=10;}if(x<=4 && x>=1){fs2=5;}if(x==0){fs2=0;}			
		
			if(Command==0x01){sb2=sb2+fs1+fs2;sb1=sb1-sb2;}if(Command==0x02){sb4=sb2+fs1+fs2;sb3=sb3-sb4;}if(Command==0x03){sb6=sb2+fs1+fs2;sb5=sb5-sb6;}if(Command==0x04){sb8=sb8+fs1+fs2;sb7=sb7-sb8;}
			if(Command==0x05){sb10=sb10+fs1+fs2;sb9=sb9-sb10;}if(Command==0x06){sb12=sb12+fs1+fs2;sb11=sb11-sb12;}if(Command==0x07){sb14=sb14+fs1+fs2;sb13=sb13-sb14;}if(Command==0x08){sb16=sb16+fs1+fs2;sb15=sb15-sb16;}
			if(Command==0x09){sb18=sb18+fs1+fs2;sb17=sb17-sb18;}if(Command==0x10){sb20=sb20+fs1+fs2;sb19=sb19-sb20;}if(Command==0x11){sb22=sb22+fs1+fs2;sb21=sb21-sb22;}if(Command==0x12){sb24=sb24+fs1+fs2;sb23=sb23-sb24;}
			if(Command==0x13){sb26=sb26+fs1+fs2;sb25=sb25-sb26;}if(Command==0x14){sb28=sb28+fs1+fs2;sb27=sb27-sb28;}if(Command==0x15){sb30=sb30+fs1+fs2;sb29=sb29-sb30;}if(Command==0x16){sb32=sb32+fs1+fs2;sb31=sb31-sb32;}
										
				
			OLED_ShowString(4,13,"-");
			OLED_ShowNum(4,14,fs1+fs2,2);
			}
	}
	
}

int menu2(void)
{
	OLED_Init();
	Key_Init();
//	uart_init(9600);	 //串口初始化为9600
	USART2_Init(9600);
	uint8_t KeyNum;
	uint8_t count;
	
	OLED_ShowString(1,2,"--Close Light--");
	OLED_ShowString(2,4,"Back menu");
	OLED_ShowString(3,1,">>>>>>>1<<<<<<<");
	
	while(1)
	{
		count=Key1_GetNum();
		KeyNum=Key_GetNum();
		if(count==5||res==5)											//复位
		{
			PWM_Init();
			IR_SendNEC(0xff,0x44);
		}
		
		if(KeyNum==1||res==1)
		{
			return 0;
		}
		
	}
}

int menu3(void)
{
	OLED_Init();
	Key_Init();
	USART2_Init(9600);
	uint8_t KeyNum;
	while(1)
	{
		KeyNum=Key_GetNum();
		OLED_ShowString(1,1,"1:");OLED_ShowSignedNum(1,3,sb1,3);OLED_ShowString(1,8,"2:");OLED_ShowSignedNum(1,10,sb3,3);
		OLED_ShowString(2,1,"2:");OLED_ShowSignedNum(2,3,sb5,3);OLED_ShowString(2,8,"4:");OLED_ShowSignedNum(2,10,sb7,3);
		OLED_ShowString(3,1,"5:");OLED_ShowSignedNum(3,3,sb9,3);OLED_ShowString(3,8,"6:");OLED_ShowSignedNum(3,10,sb11,3);
		OLED_ShowString(4,1,"7:");OLED_ShowSignedNum(4,3,sb13,3);OLED_ShowString(4,8,"8:");OLED_ShowSignedNum(4,10,sb15,3);
		if(KeyNum==1||res==1)
		{
			return 0;
		}
	}	
		
}

int menu4(void)
{
	OLED_Init();
	Key_Init();
	USART2_Init(9600);
	uint8_t KeyNum;
	while(1)
	{
		KeyNum=Key_GetNum();
		OLED_ShowString(1,1,"9:");OLED_ShowSignedNum(1,3,sb17,3);OLED_ShowString(1,9,"10:");OLED_ShowSignedNum(1,12,sb19,3);
		OLED_ShowString(2,1,"11:");OLED_ShowSignedNum(2,4,sb21,3);OLED_ShowString(2,9,"12:");OLED_ShowSignedNum(2,12,sb23,3);
		OLED_ShowString(3,1,"13:");OLED_ShowSignedNum(3,4,sb25,3);OLED_ShowString(3,9,"14:");OLED_ShowSignedNum(3,12,sb27,3);
		OLED_ShowString(4,1,"15:");OLED_ShowSignedNum(4,4,sb29,3);OLED_ShowString(4,9,"16:");OLED_ShowSignedNum(4,12,sb31,3);
		if(KeyNum==1||res==1)
		{
			return 0;
		}
	}	
		
}

int menu5(void)
{
	int fs1=0;int fs2=0;
	
	OLED_Init();
	IC_Init();
	Key_Init();
	uart_init(9600);	 //串口初始化为9600
	USART2_Init(9600);
	TIM3_Configure();
	TIM4_Configure();
//	PWM_Init();
	
	uint8_t Command;
	uint8_t KeyNum;

	OLED_ShowString(1,1,"Responder game!");
	OLED_ShowString(3,1,"time:");
	OLED_ShowString(2,1,"Player:");
	
		for(int i=0;i<10;i++)
{
			PWM_Init();
			IR_SendNEC(0xff,0x41);
}
	
	while(1)
	{					
			x=second1_Get();
			s=second2_Get();
			k=second3_Get();
			j=second4_Get();
		
	
		
		if(IR_GetDataFlag() || IR_GetRepeatFlag())	
		{
			Command=IR_GetCommand();		//获取选手命令码
			OLED_ShowHexNum(2,8,(char)Command,2);	//显示选手		
			OLED_ShowString(3,12,"FLASH");
		}
		
		KeyNum=Key_GetNum();

		if(KeyNum==1||res==1)		//回到主菜单
		{			
			count1=0;count2=0;count3=0;count4=0;count5=0;count6=0;count7=0;count8=0;
			count9=0;count10=0;count11=0;count12=0;count13=0;count14=0;count15=0;count16=0;
			return 0;			
		}
		
		if(Command==0x01){if(count1<1){count1++;printf("一号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x02){if(count2<1){count2++;printf("二号"); Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x03){if(count3<1){count3++;printf("三号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x04){if(count4<1){count4++;printf("四号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x05){if(count5<1){count5++;printf("五号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x06){if(count6<1){count6++;printf("六号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x07){if(count7<1){count7++;printf("七号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x08){if(count8<1){count8++;printf("八号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x09){if(count9<1){count9++;printf("九号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x10){if(count10<1){count10++;printf("十号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x11){if(count11<1){count11++;printf("十一号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x12){if(count12<1){count12++;printf("十二号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x13){if(count13<1){count13++;printf("十三号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x14){if(count14<1){count14++;printf("十四号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x15){if(count15<1){count15++;printf("十五号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}
		if(Command==0x16){if(count16<1){count16++;printf("十六号");k--;Delay_ms(1000);TIM_ITConfig(TIM4,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM4,DISABLE);  TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,ENABLE);TIM_Cmd(TIM3,ENABLE);}}

		OLED_ShowNum(3,6,k,2);			//真计时
		OLED_ShowString(3,8,".");
		OLED_ShowNum(3,9,j,1);		
		
		OLED_ShowNum(2,11,x,2);			//倒计时
		OLED_ShowString(2,13,".");
		OLED_ShowNum(2,14,s,1);
		
		if(KeyNum==3||res==3)
		{
			TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM3,DISABLE);
			
			if(0<k && k<=9){fs1=30;}if(10<=k && k<=14){fs1=20;}if(15<=k && k<=19){fs1=15;}if(20<=k && k<=24){fs1=10;}if(25<=k && k<=29){fs1=5;}if(k==30){fs1=0;}
			if(x<=29 && x>=25){fs2=30;}if(x<=24 && x>=20){fs2=25;}if(x<=19 && x>=15){fs2=20;}if(x<=14 && x>=10){fs2=15;}if(x<=9 && x>=5){fs2=10;}if(x<=4 && x>=1){fs2=5;}if(x==0){fs2=0;}			
			
			if(Command==0x01){sb1=sb1+fs1+fs2;}	if(Command==0x02){sb3=sb3+fs1+fs2;}	if(Command ==0x03){sb5=sb5+fs1+fs2;}if(Command ==0x04){sb7=sb7+fs1+fs2;}
			if(Command ==0x05){sb9=sb9+fs1+fs2;}if(Command ==0x06){sb11=sb11+fs1+fs2;}if(Command ==0x07){sb13=sb13+fs1+fs2;}if(Command ==0x08){sb15=sb15+fs1+fs2;}
			if(Command ==0x09){sb17=sb17+fs1+fs2;}if(Command ==0x10){sb19=sb19+fs1+fs2;}if(Command ==0x11){sb21=sb21+fs1+fs2;}if(Command ==0x12){sb23=sb23+fs1+fs2;}
      if(Command ==0x13){sb25=sb25+fs1+fs2;}if(Command ==0x14){sb27=sb27+fs1+fs2;}if(Command ==0x15){sb29=sb29+fs1+fs2;}if(Command ==0x16){sb31=sb31+fs1+fs2;}	
									
			OLED_ShowString(4,13,"+");			
			OLED_ShowNum(4,14,fs1+fs2,2);			
		}
		
		if(KeyNum==4||res==4)
		{
			TIM_ITConfig(TIM3,TIM_IT_Update | TIM_IT_Trigger,DISABLE);TIM_Cmd(TIM3,DISABLE);
			
			if(0<k && k<=9){fs1=30;}if(10<=k && k<=14){fs1=20;}if(15<=k && k<=19){fs1=15;}if(20<=k && k<=24){fs1=10;}if(25<=k && k<=29){fs1=5;}if(k==30){fs1=0;}
			if(x<=29 && x>=25){fs2=30;}if(x<=24 && x>=20){fs2=25;}if(x<=19 && x>=15){fs2=20;}if(x<=14 && x>=10){fs2=15;}if(x<=9 && x>=5){fs2=10;}if(x<=4 && x>=1){fs2=5;}if(x==0){fs2=0;}			
		
			if(Command==0x01){sb2=sb2+fs1+fs2;sb1=sb1-sb2;}if(Command==0x02){sb4=sb2+fs1+fs2;sb3=sb3-sb4;}if(Command==0x03){sb6=sb2+fs1+fs2;sb5=sb5-sb6;}if(Command==0x04){sb8=sb8+fs1+fs2;sb7=sb7-sb8;}
			if(Command==0x05){sb10=sb10+fs1+fs2;sb9=sb9-sb10;}if(Command==0x06){sb12=sb12+fs1+fs2;sb11=sb11-sb12;}if(Command==0x07){sb14=sb14+fs1+fs2;sb13=sb13-sb14;}if(Command==0x08){sb16=sb16+fs1+fs2;sb15=sb15-sb16;}
			if(Command==0x09){sb18=sb18+fs1+fs2;sb17=sb17-sb18;}if(Command==0x10){sb20=sb20+fs1+fs2;sb19=sb19-sb20;}if(Command==0x11){sb22=sb22+fs1+fs2;sb21=sb21-sb22;}if(Command==0x12){sb24=sb24+fs1+fs2;sb23=sb23-sb24;}
			if(Command==0x13){sb26=sb26+fs1+fs2;sb25=sb25-sb26;}if(Command==0x14){sb28=sb28+fs1+fs2;sb27=sb27-sb28;}if(Command==0x15){sb30=sb30+fs1+fs2;sb29=sb29-sb30;}if(Command==0x16){sb32=sb32+fs1+fs2;sb31=sb31-sb32;}
										
				
			OLED_ShowString(4,13,"-");
			OLED_ShowNum(4,14,fs1+fs2,2);
			}
		}
}

