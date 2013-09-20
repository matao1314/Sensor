#include "bsp.h"


void Bsp_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7; //光耦控制		
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);	
 GPIO_SetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7);				
 #if SWITCH==0
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//通信
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz		
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
    GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1);				

		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
		GPIO_Init(GPIOA, &GPIO_InitStructure);	

 #else
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;//通信
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz		
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
    GPIO_SetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2);				
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
 #endif

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6; //按键控制		
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 GPIO_Init(GPIOA, &GPIO_InitStructure);	

 				 
}
	 

