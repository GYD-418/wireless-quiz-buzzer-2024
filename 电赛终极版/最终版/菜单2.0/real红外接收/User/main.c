#include "stm32f10x.h"              
#include "IC.h"
#include "OLED.h"
#include "fuwei.h"
#include "PWM.h"
#include "OLED_Tim.h"
#include "Key.h"
#include "Delay.h"
#include "PWM.h"
#include "menu.h"

int menucount;

int main(void)
{

	OLED_Init();
	IC_Init();
	Key_Init();
	menu_start();

	while(1)
	{		
		menucount=menu_start();
		if(menucount==1){menu1();}
		if(menucount==2){menu2();}
		if(menucount==3){menu3();}
		if(menucount==4){menu4();}
		if(menucount==5){menu5();}
	}	

}
