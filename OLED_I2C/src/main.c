#include "REG51.h"
#include "oled.h"
#include "bmp.h"

 int main(void)
 {	
		u8 t;
	 	t=' ';		//ASCII以空格起始
	 
		OLED_Init();			//初始化OLED  
	
	  //显示图片
		OLED_DrawBMP(0,0,128,8,BMP1);  //图片显示
		Delay_1ms(1000);
	 	OLED_Clear();
	 
		while(1) 
		{		
			OLED_ShowString(0,0,"I2C",16); 
			OLED_ShowChinese(30,0,0);//好
			OLED_ShowChinese(48,0,1);//难
		
			OLED_ShowString(0,3,"Hello QG",16);
			OLED_ShowString(0,6,"ASCII:",16);  
			OLED_ShowString(63,6,"CODE:",16);  
			OLED_ShowChar(48,6,t,16);//显示ASCII字符	   
			t++;
			if(t>'~')				//循环归零
			{
				t=' ';
			}
			OLED_ShowNum(103,6,t,3,16);//显示ASCII字符的码值 	
			Delay_1ms(100);
		}	  
	
}