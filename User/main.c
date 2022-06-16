/*
 * main.c
 *
 *	UCosIIϵͳ��ֲ����
 *
 *  Created on: 2022-6-15
 *      Author: tly
 */

#include "sys.h"
#include "delay.h" 
#include "usart.h"
#include "includes.h"
#include "user_led.h"



//START ����
//�����������ȼ�
#define START_TASK_PRIO			10  ///��ʼ��������ȼ�Ϊ���
//���������ջ��С
#define START_STK_SIZE			128
//���������ջ
OS_STK START_TASK_STK[START_STK_SIZE];
//������
void start_task(void *pdata);


//LED0����
//�����������ȼ�
#define LED0_TASK_PRIO			7
//���������ջ��С
#define LED0_STK_SIZE			128
//�����ջ
OS_STK LED0_TASK_STK[LED0_STK_SIZE];
//������
void led0_task(void *pdata);


//LED1����
//�����������ȼ�
#define LED1_TASK_PRIO			6
//���������ջ��С
#define LED1_STK_SIZE			128
//�����ջ
OS_STK LED1_TASK_STK[LED1_STK_SIZE];
//������
void led1_task(void *pdata);



 /*****************************************************************************
Function Name        :: int main(void)
Function Description :: ������
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
int main(void)
{ 
	delay_init(168);			//��ʼ����ʱ����
	LED_Init();					//��ʼ��LEDʱ��   
	OSInit();   				//��ʼ��UCOSII
 	OSTaskCreate( start_task,
								(void  *  )0,
								(OS_STK * )&START_TASK_STK[START_STK_SIZE-1],
								START_TASK_PRIO );//������ʼ����
	OSStart();	  	 			//����UCOSII
}



 /*****************************************************************************
Function Name        :: void start_task(void *pdata)
Function Description :: ��ʼ����
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
//��ʼ����
void start_task(void *pdata)
{
  OS_CPU_SR cpu_sr=0;
	pdata = pdata; 
	OSStatInit();  //����ͳ������
  OS_ENTER_CRITICAL();			//�����ٽ���(�޷����жϴ��)    
 	OSTaskCreate(	led0_task,
								(void *)0,
								(OS_STK*)&LED0_TASK_STK[LED0_STK_SIZE-1],
								LED0_TASK_PRIO);						   
 	OSTaskCreate(	led1_task,
								(void *)0,
								(OS_STK*)&LED1_TASK_STK[LED1_STK_SIZE-1],
								LED1_TASK_PRIO);	 				   
	OSTaskSuspend(START_TASK_PRIO);	//������ʼ����.
	OS_EXIT_CRITICAL();				//�˳��ٽ���(���Ա��жϴ��)
} 



 /*****************************************************************************
Function Name        :: void led0_task(void *pdata)
Function Description :: ����
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
//LED0����
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
Function Description :: ����
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
//LED1����
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



