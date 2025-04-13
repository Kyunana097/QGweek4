#include "REG51.h"
#include "oled.h"
#include "bmp.h"

 int main(void)
 {	
		u8 t;
	 	t=' ';		//ASCII�Կո���ʼ
	 
		OLED_Init();			//��ʼ��OLED  
	
	  //��ʾͼƬ
		OLED_DrawBMP(0,0,128,8,BMP1);  //ͼƬ��ʾ
		Delay_1ms(1000);
	 	OLED_Clear();
	 
		while(1) 
		{		
			OLED_ShowString(0,0,"I2C",16); 
			OLED_ShowChinese(30,0,0);//��
			OLED_ShowChinese(48,0,1);//��
		
			OLED_ShowString(0,3,"Hello QG",16);
			OLED_ShowString(0,6,"ASCII:",16);  
			OLED_ShowString(63,6,"CODE:",16);  
			OLED_ShowChar(48,6,t,16);//��ʾASCII�ַ�	   
			t++;
			if(t>'~')				//ѭ������
			{
				t=' ';
			}
			OLED_ShowNum(103,6,t,3,16);//��ʾASCII�ַ�����ֵ 	
			Delay_1ms(100);
		}	  
	
}