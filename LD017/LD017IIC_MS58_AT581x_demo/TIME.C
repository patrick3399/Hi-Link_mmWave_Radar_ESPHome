#include "time.h"

/*-------------------------------------------------
 * 函数名称：DelayUs
 * 功能：   短延时函数
 * 输入参数：Time延时时间长度 延时时长Time*2Us
 * 返回参数：无 
 -------------------------------------------------*/
void DelayUs(unsigned char Time)
{
	unsigned char a;
	for(a=0;a<Time;a++)
	{
		NOP();
	}
} 

/*------------------------------------------------- 
 * 函数名称：DelayMs
 * 功能：   短延时函数
 * 输入参数：Time延时时间长度 延时时长Time ms
 * 返回参数：无 
 -------------------------------------------------*/
void DelayMs(unsigned char Time)
{
	unsigned char a,b;
	for(a=0;a<Time;a++)
	{
		for(b=0;b<5;b++)
		{
		 	DelayUs(98); //快1%
		}
	}
}

/*------------------------------------------------- 
 * 函数名称：DelayS
 * 功能：   短延时函数
 * 输入参数：Time 延时时间长度 延时时长Time S
 * 返回参数：无 
 -------------------------------------------------*/
void DelayS(unsigned char Time)
{
	unsigned char a,b;
	for(a=0;a<Time;a++)
	{
		for(b=0;b<10;b++)
		{
		 	DelayMs(100); 
		}
	}
}