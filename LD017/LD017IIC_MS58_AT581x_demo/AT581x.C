#include "AT581x.h"

/*
������λ
*/
void soft_reset(void)
{
	AT581x_WriteOneByte(0x00, 0x00);
	AT581x_WriteOneByte(0x00, 0x01);
}

/*
����Ƶ��
*/
void set_freq(unsigned char freq_0x5f, unsigned char freq_0x60)
{
	AT581x_WriteOneByte(0x61, 0xC2);  //10���Ĵ����޸���Ч
	AT581x_WriteOneByte(0x5f, freq_0x5f);
	AT581x_WriteOneByte(0x60, freq_0x60);
}

/*
�����Լ�ʱ��
*/
void set_self_check_time(unsigned int self_check_time)
{
	AT581x_WriteOneByte(0x38, (unsigned char)(self_check_time));
	AT581x_WriteOneByte(0x39, (unsigned char)(self_check_time >> 8));
}

/*
��������ʱ�����ʱ��-���Ϊ500ms
*/
void set_light_on_base_time(unsigned long light_on_base_time)
{
	AT581x_WriteOneByte(0x3d, (unsigned char)(light_on_base_time));
	AT581x_WriteOneByte(0x3e, (unsigned char)(light_on_base_time >> 8));
	AT581x_WriteOneByte(0x3f, (unsigned char)(light_on_base_time >> 16));
	AT581x_WriteOneByte(0x40, (unsigned char)(light_on_base_time >> 24));
}

/*
���ùصƱ���ʱ��
*/
void set_light_off_time(unsigned int light_off_time)
{
	AT581x_WriteOneByte(0x4e, (unsigned char)(LIGHT_OFF_TIME));
	AT581x_WriteOneByte(0x4f, (unsigned char)(LIGHT_OFF_TIME >> 8));
}

/*
���ø�Ӧ����
*/
void set_distance(unsigned char pwr_40uA_switch, unsigned int delta, unsigned char gain)
{
	// ���ù���
    if (pwr_40uA_switch == 1)  // 40uA
    {
        AT581x_WriteOneByte(0x68, 0x48&0xc7|0x38);
		AT581x_WriteOneByte(0x67, 0xf3&0xf0|0x08);
	}
    else   // 70uA
    {
        AT581x_WriteOneByte(0x68, 0x48);
		AT581x_WriteOneByte(0x67, 0xf3);	
	}
    // д��deltaֵ
	AT581x_WriteOneByte(0x10, (unsigned char)(delta));
	AT581x_WriteOneByte(0x11, (unsigned char)(delta >> 8));	
	// д��gainֵ
	AT581x_WriteOneByte(0x5C, gain);
}

/*
���ø�Ӧʱ��
*/
void set_light_on_time(unsigned long light_on_time)
{
	AT581x_WriteOneByte(0x41, 0x01);
	AT581x_WriteOneByte(0x42, (unsigned char)(light_on_time));
	AT581x_WriteOneByte(0x43, (unsigned char)(light_on_time >> 8));
	AT581x_WriteOneByte(0x44, (unsigned char)(light_on_time >> 16));
	AT581x_WriteOneByte(0x45, (unsigned char)(light_on_time >> 24));
}

/*
���ù�������
*/
void set_light_sensor_threshold(unsigned char onoff, 
								unsigned int light_sensor_value_high, 
								unsigned int light_sensor_value_low, 
                                unsigned int light_sensor_iniverse)
{
	if (onoff)
		AT581x_WriteOneByte(0x66, 0x42);
	else
		AT581x_WriteOneByte(0x66, 0x4a);
	
	AT581x_WriteOneByte(0x34, (unsigned char)(light_sensor_value_low));
	AT581x_WriteOneByte(0x35, (unsigned char)(light_sensor_value_high));
	AT581x_WriteOneByte(0x36, (unsigned char)((light_sensor_value_low >> 8) | ((light_sensor_value_high >> 8)<<2) | (light_sensor_iniverse << 4)));
}

/*
����RFģ��
�ر�RF���ܺ�ģ��رո�Ӧ���ܣ��ɽ�ʡԼ10uA����
*/
void control_rf_module(unsigned char onoff)
{
    if (onoff)
    {
		AT581x_WriteOneByte(0x5d, 0x45);
		AT581x_WriteOneByte(0x62, 0x55);
		AT581x_WriteOneByte(0x51, 0xa0);
	}
    else
    {
		AT581x_WriteOneByte(0x5d, 0x46);
		AT581x_WriteOneByte(0x62, 0xaa);
		AT581x_WriteOneByte(0x51, 0x50);
	}
}

/*
���ô��ڼ�ⳤ��&��ֵ
*/
void set_window_detect(unsigned char window_length, unsigned char window_threshold)
{
	AT581x_WriteOneByte(0x31, window_length);		// Default: detect Win = 4
	AT581x_WriteOneByte(0x32, window_threshold);	// Default: 3
}

/*
AT581x��ʼ��
*/
void AT581x_REG_Init(void)
{
	set_freq(FREQ_0X5F_5869MHZ, FREQ_0X60_5869MHZ);  // �粻��Ҫ����Ƶ�㣬���Բ�����
	
    set_distance(PWR_40UA_SWITCH, DELTA, GAIN);
    
	set_light_on_time(LIGHT_ON_TIME);
    
	set_self_check_time(SELF_CHECK_TIME);
	
    set_light_on_base_time(LIGHT_ON_BASE_TIME);
	
	set_light_off_time(LIGHT_OFF_TIME);
	
	// �������ܣ���Ҫʱ�ٿ���
	// set_light_sensor_threshold(LIGHT_SENSOR_STATUS, LIGHT_SENSOR_VALUE_LOW, LIGHT_SENSOR_VALUE_HIGH, LIGHT_SENSOR_INIVERSE);

	AT581x_WriteOneByte(0x55, 0x04);
	
    soft_reset();
} 

/*
����AT581x����
*/
void AT581x_update_param(void)
{
    //������²��������Ӧ���롢���ʱ���
    
	// ��λʹ������Ч
	soft_reset();
}