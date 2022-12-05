#include "time.h"
#include "IIC.h"
#include "AT581x.h"

//***********************�궨��*****************************
#define  unchar	unsigned char 
#define  unint	unsigned int
#define  unlong	unsigned long

/*-------------------------------------------------
 * ��������POWER_INITIAL
 *	���ܣ�  �ϵ�ϵͳ��ʼ��
 * ���룺  ��
 * �����  ��
 --------------------------------------------------*/	
void POWER_INITIAL (void) 
{

}

/*-------------------------------------------------
 *  ������: main 
 *	���ܣ�  ������
 *  ���룺  ��
 *  �����  ��
 --------------------------------------------------*/
void main()
{
	DelayMs(100);
 	POWER_INITIAL();	//ϵͳ��ʼ���������û�ʵ��MCU���г�ʼ��
    IIC_GPIO_Init();  // ��ʼ��IIC
    
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