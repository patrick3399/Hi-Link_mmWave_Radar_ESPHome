#ifndef __IIC_H__
#define __IIC_H__

#include "time.h"


#define  IIC_SCL		RA1  // 定义SCL引脚
#define  IIC_SDA		RA0  // 定义SDA引脚

#define SDA_OUT  TRISA0 =0  // 配置SDA为输出
#define SDA_IN	 TRISA0 =1;	WPUA0= 1  // 配置SDA为输入上拉

#define SCL_OUT  TRISA1 =0  // 配置SCL为输出
#define SCL_IN	 TRISA1 =1;	WPUA1= 1  // 配置SCL为输入上拉

void IIC_GPIO_Init(void);
void IIC_Sleep(void);
void IIC_Start(void);void IIC_Stop(void);
unsigned char IIC_Wait_Ack(void);
void IIC_Ack(void);
void IIC_NAck(void);
void IIC_Send_Byte(unsigned char txd);
unsigned char IIC_Read_Byte(unsigned char ack);
unsigned char AT581x_ReadOneByte(unsigned char address);
void AT581x_WriteOneByte(unsigned char address,unsigned char data);

#endif
