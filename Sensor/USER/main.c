/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include <stdio.h>
#include "led.h"
#include "eeprom.h"
#include "bsp.h"
#include "adc.h"

uint16_t VarValue = 0;
/* Virtual address defined by the user: 0xFFFF value is prohibited */
uint16_t VirtAddVarTab[NumbOfVar] = {0x5555, 0x6666, 0x7777};
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
typedef struct {

u16 value;
u16 value075;
u16 value085;
}AD_value;
AD_value AD_VALUE;
int main(void)
{	
  uint16_t temp;
//	u16 AD_value0=0;
//	u16 AD_value1=0;
  SystemInit();
	delay_init(72);
	uart_init(72,9600);	 	//串口初始化为9600
  Adc_Init();
  LED_Init();
	Bsp_Init();
  /* Unlock the Flash Program Erase controller */
  FLASH_Unlock();
  /* EEPROM Init */
  EE_Init();
/* --- Store successively many values of the three variables in the EEPROM ---*/
  /* Store 1000 values of Variable1 in EEPROM */
  //for (VarValue = 0; VarValue < 1000; VarValue++)
  //{
    //EE_WriteVariable(VirtAddVarTab[0], 200);
  //}
	//EE_ReadVariable(VirtAddVarTab[0],&temp);
	//			printf("temp=%d",temp);
	printf("Init OK");

  while (1)
  {
//   	AD_value0=Get_Adc_Average(8,10);
//   	AD_value1=Get_Adc_Average(9,10);
//		printf("ADC8=%d\n",Get_Adc_Average(8,10));
//		printf("ADC9=%d\n",Get_Adc_Average(9,10));


AD_VALUE.value=Get_Adc_Average(8,10);
AD_VALUE.value075=AD_VALUE.value*0.75;
AD_VALUE.value085=AD_VALUE.value*0.85;


EE_WriteVariable(VirtAddVarTab[0],AD_VALUE.value075);
EE_WriteVariable(VirtAddVarTab[1],AD_VALUE.value085);


#if SWITCH==0
	  COM0=1;
    if(KEY1==0){
	    COM0=0;
			if(KEY1==0&&COM2==0)
			{
	 	    LED1=0;
				EE_WriteVariable(VirtAddVarTab[0],AD_VALUE.value075);
			}
    }
#else
	  COM2=1;
    if(KEY1==0){
	    COM2=0;
			if(KEY1==0&&COM0==0)
			{
	 	    LED1=0;
				EE_WriteVariable(VirtAddVarTab[0],AD_VALUE.value075);
			}
    }
#endif

     if(AD_VALUE.value>AD_VALUE.value075){
		    OCP0=0;
        OCP1=0;
		 }

		 if(AD_VALUE.value>AD_VALUE.value085){
		    OCP0=0;
        OCP1=0;
		 }

		 if(AD_VALUE.value>500){
		    OCP0=0;
        OCP1=0;
	 	    LED1=0;
		 
		 }
   	//OCP0=0;
    //OCP1=0;
}
}
