#ifndef __IIC_H__
#define __IIC_H__

#include "time.h"


#define  IIC_SCL		RA1  // ����SCL����
#define  IIC_SDA		RA0  // ����SDA����

#define SDA_OUT  TRISA0 =0  // ����SDAΪ���
#define SDA_IN	 TRISA0 =1;	WPUA0= 1  // ����SDAΪ��������

#define SCL_OUT  TRISA1 =0  // ����SCLΪ���
#define SCL_IN	 TRISA1 =1;	WPUA1= 1  // ����SCLΪ��������

void IIC_GPIO_Init(void);
void IIC_Sleep(void);
void IIC_Start(void);
unsigned char IIC_Wait_Ack(void);
void IIC_Ack(void);
void IIC_NAck(void);
void IIC_Send_Byte(unsigned char txd);
unsigned char IIC_Read_Byte(unsigned char ack);
unsigned char AT581x_ReadOneByte(unsigned char address);
void AT581x_WriteOneByte(unsigned char address,unsigned char data);

#endif