/*
	OLED菜单架构
	write == HDF
	
*/

#include <stm32f10x.h>
#include "RE_basic.h"
#include "OLED.h"
#include "menu.h"

int menu2;

int main(void)
{
	  key_Init();
	  OLED_Init();
	  while (1)
	  {
		menu2 = menu1();                   //进入一级菜单，并返回你的选择
		if(menu2==1) menu2_vision();	   //进入数字识别模式
		if(menu2==2) menu2_mode();         //进入自动控制模式
		if(menu2==3) menu2_head();         //进入综合手柄控制
	  }
}
