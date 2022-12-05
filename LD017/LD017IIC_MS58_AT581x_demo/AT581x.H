#ifndef __AT581x_H__
#define __AT581x_H__

#include "time.h"
#include "IIC.h"
#include "target_config.h"

void soft_reset(void);
void set_freq(unsigned char freq_0x5f, unsigned char freq_0x60);
void set_self_check_time(unsigned int self_check_time);
void set_light_on_base_time(unsigned long light_on_base_time);
void set_light_off_time(unsigned int light_off_time);
void set_distance(unsigned char pwr_40uA_switch, unsigned int delta, unsigned char gain);
void set_light_on_time(unsigned long light_on_time);
void set_light_sensor_threshold(unsigned char onoff, unsigned int light_sensor_value_high, unsigned int light_sensor_value_low, unsigned int light_sensor_iniverse);
void control_rf_module(unsigned char onoff);
void set_window_detect(unsigned char window_length, unsigned char window_threshold);
void AT581x_REG_Init(void);
void AT581x_update_param(void);

#endif
