#ifndef __BSP_H
#define __BSP_H	 
#include "stm32f10x.h"

#define SWITCH  1

#define OCP0 PBout(6)
#define OCP1 PBout(7)	


#define KEY1 PAin(5)
#define KEY2 PAin(6)	

#if SWITCH==0
	#define COM0 PAout(0)
	#define COM1 PAout(1)
	#define COM2 PAin(2)
#else
	#define COM0 PAin(0)
	#define COM1 PAout(1)
	#define COM2 PAout(2)
#endif

void Bsp_Init(void);

#endif

