#include "IIC.h"


/*-------------------------------------------------
 *  �������IIIC_GPIO_Init
 *	���ܣ�  ��ʼ��IIC
  *  ���룺  ��
 *  �����  ��
 --------------------------------------------------*/
void IIC_GPIO_Init(void)
{
	SCL_OUT;
	SDA_OUT;
    IIC_Stop();
}

/*-------------------------------------------------
 *  �������IIC_Sleep
 *	���ܣ�  ����˯��״̬��IIC����Ϊ����
  *  ���룺  ��
 *  �����  ��
 --------------------------------------------------*/
void IIC_Sleep(void)
{
	SCL_IN;
	SDA_IN;
}

/*-------------------------------------------------
 *  ��������IIC_Start
 *	���ܣ�  ����IIC��ʼ�ź�
 *  ���룺  ��
 *  �����  ��
 --------------------------------------------------*/
void IIC_Start(void)
{
	SDA_OUT;
 	IIC_SDA=1;
    DelayUs(10);  	  
	IIC_SCL=1;
	DelayUs(10);
  	IIC_SDA=0;        //START:when CLK is high,DATA change form high to low 
	DelayUs(10);
	IIC_SCL=0;        //ǯסI2C���ߣ�׼�����ͻ�������� 
    DelayUs(10);          
}

/*-------------------------------------------------
 *  ��������IIC_Stop
 *	���ܣ�  ����IICֹͣ�ź�
 *  ���룺  ��
 *  �����  ��
 --------------------------------------------------*/
void IIC_Stop(void)
{
	SDA_OUT;          //SDA�����
	IIC_SCL=0;
	IIC_SDA=0;        //STOP:when CLK is high DATA change form low to high
 	DelayUs(10);
	IIC_SCL=1; 
    DelayUs(10);
	IIC_SDA=1;        //����I2C���߽����ź�
	DelayUs(10);							   	
}

/*-------------------------------------------------
 *  ��������IIC_Wait_Ack
 *	���ܣ�  �ȴ�Ӧ���źŵ���
 *  ���룺  ��
 *  �����  ����ֵ��1������Ӧ��ʧ��
 *               0������Ӧ��ɹ�
 --------------------------------------------------*/
unsigned char IIC_Wait_Ack(void)
{
	unsigned char ucErrTime=0;       
	IIC_SDA=1;
 	SDA_IN;               //SDA����Ϊ���� 
	DelayUs(10);	   
	IIC_SCL=1;
	DelayUs(10);	 
	while(IIC_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250) //�ȴ���ʱ
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL=0;            //ʱ�����0 	   
	return 0;  
} 
/*-------------------------------------------------
 * ��������IIC_Ack
 *	���ܣ�  ����ACKӦ��
 * ���룺  ��
 * �����  ��
 --------------------------------------------------*/
void IIC_Ack(void)
{
	IIC_SCL=0;
	SDA_OUT;              //SDA�����
	IIC_SDA=0;
	DelayUs(10);	
	IIC_SCL=1;
	DelayUs(10);	
	IIC_SCL=0;
}

/*-------------------------------------------------
 *  ��������IIC_NAck
 *	���ܣ�  ������ACKӦ��
 *  ���룺  ��
 *  �����  ��
 --------------------------------------------------*/	    
void IIC_NAck(void)
{
	IIC_SCL=0;
	SDA_OUT;              //SDA�����
	IIC_SDA=1;
	DelayUs(10);	
	IIC_SCL=1;
	DelayUs(10);	
	IIC_SCL=0;
}	

/*-------------------------------------------------
 *  ��������IIC_Send_Byte
 *	���ܣ�  IIC����һ���ֽ�
 *  ���룺  д��Ҫ���͵�һ���ֽ�����txd
 *  �����  ��
 --------------------------------------------------*/		  
void IIC_Send_Byte(unsigned char txd)
{                        
    unsigned char t;   
	SDA_OUT;	          //SDA�����   
    IIC_SCL=0;            //����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
		if(txd&0x80)
			IIC_SDA=1;
		else
			IIC_SDA=0;
		txd<<=1; 	  
		DelayUs(10);				  
		IIC_SCL=1;
		DelayUs(10);	
		IIC_SCL=0;	
		DelayUs(10);
    }	 
} 	 

/*-------------------------------------------------
 *  ��������IIC_Read_Byte
 *	���ܣ�  IIC��һ���ֽ�
 *  ���룺  ��
 *  �����  �����洢����������ݲ�����receive
 --------------------------------------------------*/
unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN;               //SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IIC_SCL=0; 
        DelayUs(10);	
     	IIC_SCL=1;
        receive<<=1;
        if(IIC_SDA)receive++;   
		DelayUs(10);	
    }		
    
	if (!ack)
    {
        IIC_NAck(); //����nACK
	}
    else
    {
        IIC_Ack(); //����ACK  
    }
    
    return receive;
}

/*-------------------------------------------------
 *  ��������AT581x_ReadOneByte
 *	���ܣ�  IIC�����ƶ�λ�õ�����
 *  ���룺  address
 *  �����  ����address�洢�����������iicdata
 --------------------------------------------------*/
unsigned char AT581x_ReadOneByte(unsigned char address)
{
	unsigned char iicdata = 0;
	IIC_READ_Begin:
		IIC_Start();
		IIC_Send_Byte(0x50);
		if(IIC_Wait_Ack())goto IIC_READ_Begin;
		IIC_Send_Byte(address%256);				    //��Ҫ�������ݵ�ַ
		if(IIC_Wait_Ack())goto IIC_READ_Begin; 
		IIC_Start();
		IIC_Send_Byte(0x51);
		if(IIC_Wait_Ack())goto IIC_READ_Begin;
		iicdata=IIC_Read_Byte(0);
		IIC_Stop();		
		return iicdata;
}
 /*-------------------------------------------------
 *  ��������AT581x_WriteOneByte
 *	���ܣ�  IIC������dataд���ƶ���λ��address
 *  ���룺  address��data
 *  �����  ��
 --------------------------------------------------*/
void AT581x_WriteOneByte(unsigned char address,unsigned char data)
{
	IIC_WRITE_Begin:
		IIC_Start();
		IIC_Send_Byte(0x50);
		if(IIC_Wait_Ack())goto IIC_WRITE_Begin;

		IIC_Send_Byte(address%256);
		if(IIC_Wait_Ack())goto IIC_WRITE_Begin;

		IIC_Send_Byte(data);
		if(IIC_Wait_Ack())goto IIC_WRITE_Begin;

		IIC_Stop();	
        DelayMs(1);
}