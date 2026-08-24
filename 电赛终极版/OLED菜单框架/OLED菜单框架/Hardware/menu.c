#include <stm32f10x.h>
#include "menu.h"
#include "OLED.h"
#include "RE_basic.h"
#include "delay.h"

int menu1()
{
	int menu1_flag=1;         //选择

	uint8_t key;
	while(1)
	{
		key = read_key();
		
		if(key==1)//控制键
		{
			menu1_flag++;
			if(menu1_flag==4) menu1_flag=1;	
		}
		if(key==2)//选择键
		{
			OLED_Clear();
			return menu1_flag;
		}
		
		switch(menu1_flag)
		{
			case 1:
			{
				OLED_ShowString(2,1,"*");
				OLED_ShowString(3,1," ");
				OLED_ShowString(4,1," ");

			}break;
			case 2:
			{
				OLED_ShowString(2,1," ");
				OLED_ShowString(3,1,"*");
				OLED_ShowString(4,1," ");
			}break;
			case 3:
			{
				OLED_ShowString(2,1," ");
				OLED_ShowString(3,1," ");
				OLED_ShowString(4,1,"*");				
			}break;
		}
		
	}

}

int menu2_vision()
{
	/*数字识别显示*/	
	OLED_ShowChinese(2, 2, 62);
	OLED_ShowChinese(2, 4, 63);
	OLED_ShowChinese(2, 6, 64);
	OLED_ShowChinese(3, 2, 66);
	OLED_ShowChinese(3, 4, 67);
	OLED_ShowChinese(3, 6, 68);
	OLED_ShowString(3,8,":");
	
/**************************************************************************************/
		uint8_t key;
		uint8_t num;
		while(1)
		{
		num++;
		key = read_key();
		if(key==1)
		{
			OLED_Clear();
			return 0;
		}
		delay_ms(500);
		OLED_ShowNum(3,12,num,1);
		}
}


int menu2_mode()
{
	int menu2_flag=1;         //选择
	
	/*自动模式*/
	OLED_ShowChinese(2, 4, 69);
	OLED_ShowChinese(2, 6, 70);
	OLED_ShowChinese(2, 8, 71);
	OLED_ShowChinese(2, 10, 72);
	OLED_ShowChinese(4, 4, 73);
	OLED_ShowChinese(4, 6, 74);
	OLED_ShowChinese(4, 8, 71);
	OLED_ShowChinese(4, 10, 72);
/**************************************************************************************/
	uint8_t key;
		while(1)
		{
		key = read_key();
		if(key==1)
		{
			OLED_Clear();
			return 0;
		}
		if(key==2)
		{
			menu2_flag++;
			if(menu2_flag==3) menu2_flag=1;	
		}
		switch(menu2_flag)      //光标移动
		{
			case 1:
			{
				OLED_ShowString(2,1,"*");
				OLED_ShowString(3,1," ");
				OLED_ShowString(4,1," ");

			}break;
			case 2:
			{
				OLED_ShowString(2,1," ");
				OLED_ShowString(3,1," ");
				OLED_ShowString(4,1,"*");
			}break;
		}
		}
}


int menu2_head()
{
	/*综合显示*/
	OLED_ShowString(1,8,"*");
	OLED_ShowString(2,8,"*");
	OLED_ShowString(3,8,"*");
	OLED_ShowString(4,8,"*");
	
	OLED_ShowChinese(4, 2, 41);
	OLED_ShowChinese(4, 4, 42);
	OLED_ShowChinese(4, 11, 52);
	OLED_ShowChinese(4, 13, 42);
	
	OLED_ShowChinese(2, 2, 45);
	OLED_ShowChinese(2, 4, 44);
	
	OLED_ShowChinese(2, 11, 46);
	OLED_ShowChinese(2, 13, 44);
/**************************************************************************************/
	uint8_t key;
		while(1)
		{
		key = read_key();
		if(key==1)
		{
			OLED_Clear();
			return 0;
		}
		}
}
