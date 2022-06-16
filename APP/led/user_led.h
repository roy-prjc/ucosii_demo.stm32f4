/*
 * user_led.h
 *
 *	驱动普通IO输出
 *
 *  Created on: 2022-6-12
 *      Author: tly
 */

#ifndef __USER_LED_H
#define __USER_LED_H


#include "sys.h"


#define LED0_OFF		GPIO_SetBits(GPIOF,GPIO_Pin_9)		//置1
#define LED0_ON			GPIO_ResetBits(GPIOF,GPIO_Pin_9)	//清0
#define LED1_OFF		GPIO_SetBits(GPIOF,GPIO_Pin_10)		//置1
#define LED1_ON			GPIO_ResetBits(GPIOF,GPIO_Pin_10)	//清0

#define LED0 PFout(9)	// DS0
#define LED1 PFout(10)	// DS1	 

void LED_Init(void);



#endif /* USER_LED_H_ */
