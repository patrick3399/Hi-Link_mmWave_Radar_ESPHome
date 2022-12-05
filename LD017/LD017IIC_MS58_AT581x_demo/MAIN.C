#include "time.h"
#include "IIC.h"
#include "AT581x.h"

//***********************宏定义*****************************
#define  unchar	unsigned char 
#define  unint	unsigned int
#define  unlong	unsigned long

/*-------------------------------------------------
 * 函数名：POWER_INITIAL
 *	功能：  上电系统初始化
 * 输入：  无
 * 输出：  无
 --------------------------------------------------*/	
void POWER_INITIAL (void) 
{

}

/*-------------------------------------------------
 *  函数名: main 
 *	功能：  主函数
 *  输入：  无
 *  输出：  无
 --------------------------------------------------*/
void main()
{
	DelayMs(100);
 	POWER_INITIAL();	//系统初始化，根据用户实际MCU进行初始化
    IIC_GPIO_Init();  // 初始化IIC
    
	DelayMs(100);	
	AT581x_REG_Init();
    
	while(1)  
    {
		set_distance(0, 1023, 0x3B);
		DelayS(20);
		set_distance(0, 50, 0x3B);
		DelayS(20);
    }
}
