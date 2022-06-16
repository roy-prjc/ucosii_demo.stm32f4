/*
 * user_led.c
 *
 *	驱动普通IO输出
 *
 *  Created on: 2022-6-12
 *      Author: tly
 */

#include "user_led.h"


/*****************************************************************************
Function Name        :: void LED_Init(void)
Function Description :: 端口初始化
Bank Ports           :: GPIOB.5 、 GPIOE.5
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 ::
Function called	-

Last Chang Date      : 2022/06/15
*****************************************************************************/
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能GPIOF时钟

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化GPIO
	
	GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10);//GPIOF9,F10设置高，灯灭

}


