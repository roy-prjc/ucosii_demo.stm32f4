/*
 * main.c
 *
 *	UCosII系统移植程序
 *
 *  Created on: 2022-6-15
 *      Author: tly
 */

#include "sys.h"
#include "delay.h" 
#include "usart.h"
#include "includes.h"
#include "user_led.h"



//START 任务
//设置任务优先级
#define START_TASK_PRIO			10  ///开始任务的优先级为最低
//设置任务堆栈大小
#define START_STK_SIZE			128
//任务任务堆栈
OS_STK START_TASK_STK[START_STK_SIZE];
//任务函数
void start_task(void *pdata);


//LED0任务
//设置任务优先级
#define LED0_TASK_PRIO			7
//设置任务堆栈大小
#define LED0_STK_SIZE			128
//任务堆栈
OS_STK LED0_TASK_STK[LED0_STK_SIZE];
//任务函数
void led0_task(void *pdata);


//LED1任务
//设置任务优先级
#define LED1_TASK_PRIO			6
//设置任务堆栈大小
#define LED1_STK_SIZE			128
//任务堆栈
OS_STK LED1_TASK_STK[LED1_STK_SIZE];
//任务函数
void led1_task(void *pdata);



 /*****************************************************************************
Function Name        :: int main(void)
Function Description :: 主函数
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
int main(void)
{ 
	delay_init(168);			//初始化延时函数
	LED_Init();					//初始化LED时钟   
	OSInit();   				//初始化UCOSII
 	OSTaskCreate( start_task,
								(void  *  )0,
								(OS_STK * )&START_TASK_STK[START_STK_SIZE-1],
								START_TASK_PRIO );//创建起始任务
	OSStart();	  	 			//启动UCOSII
}



 /*****************************************************************************
Function Name        :: void start_task(void *pdata)
Function Description :: 开始任务
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
//开始任务
void start_task(void *pdata)
{
  OS_CPU_SR cpu_sr=0;
	pdata = pdata; 
	OSStatInit();  //开启统计任务
  OS_ENTER_CRITICAL();			//进入临界区(无法被中断打断)    
 	OSTaskCreate(	led0_task,
								(void *)0,
								(OS_STK*)&LED0_TASK_STK[LED0_STK_SIZE-1],
								LED0_TASK_PRIO);						   
 	OSTaskCreate(	led1_task,
								(void *)0,
								(OS_STK*)&LED1_TASK_STK[LED1_STK_SIZE-1],
								LED1_TASK_PRIO);	 				   
	OSTaskSuspend(START_TASK_PRIO);	//挂起起始任务.
	OS_EXIT_CRITICAL();				//退出临界区(可以被中断打断)
} 



 /*****************************************************************************
Function Name        :: void led0_task(void *pdata)
Function Description :: 任务
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
//LED0任务
void led0_task(void *pdata)
{	 	
	while(1)
	{
		LED0_OFF;
		delay_ms(80);
		LED0_ON;
		delay_ms(920);
	};
}



 /*****************************************************************************
Function Name        :: void led1_task(void *pdata)
Function Description :: 任务
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
//LED1任务
void led1_task(void *pdata)
{	  
	while(1)
	{
		LED1_OFF;
		delay_ms(300);
		LED1_ON;
		delay_ms(300);
	};
}



