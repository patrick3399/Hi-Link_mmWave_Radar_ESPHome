#ifndef __TARGET_CONFIG_H__
#define __TARGET_CONFIG_H__


/*========================参数配置======================*/
#define	TRUE	1
#define	FALSE	0

#define	PWR_40UA_SWITCH			TRUE	// 配置功耗TRUE - 40uA（只对AT5815有效）；FALSE - 68uA（AT5815功耗68uA，AT5812功耗9mA）
#define	SELF_CHECK_TIME			2000	// 上电自检时间 0~65536 ms 
#define	LIGHT_OFF_TIME			1000	// 关灯保护时间，建议1000ms
#define	LIGHT_ON_BASE_TIME		500		// 保持默认500ms
#define	LIGHT_ON_TIME			1500	// 总开灯时间=LIGHT_ON_BASE_TIME+LIGHT_ON_TIME，最小可配置为1
#define	DELTA					200		// delta值：0~1023，值越大距离越短
#define	GAIN					0x3B	// 增益值范围：[0x0B, 0x1B, 0x2B, 0x3B, 0x4B, 0x5B, 0x6B, 0x7B, 0x8B, 0x9B, 0xAB, 0xBB, 0xCB]
										// default = 0x3B  建议默认。近距离感应场景（2m内）使用，如智能门锁应用，可配置为0x7B ~ 0x9B

// 以下是光敏配置功能
#define	LIGHT_SENSOR_STATUS			0		// 0-关闭光敏 1-开启光敏
#define	LIGHT_SENSOR_VALUE_LOW   	500		// 光敏阈值 : 0~1023, 10bit
#define	LIGHT_SENSOR_VALUE_HIGH  	530		// 光敏阈值 : 0~1023, 10bit
#define	LIGHT_SENSOR_INIVERSE    	0		// 默认值0，不要改动

// 以下是频率配置值
#define FREQ_0X5F_5696MHZ			0x40
#define FREQ_0X60_5696MHZ			0x9d

#define FREQ_0X5F_5715MHZ			0x41
#define FREQ_0X60_5715MHZ			0x9d

#define FREQ_0X5F_5730MHZ			0x42
#define FREQ_0X60_5730MHZ			0x9d

#define FREQ_0X5F_5748MHZ			0x43
#define FREQ_0X60_5748MHZ			0x9d

#define FREQ_0X5F_5765MHZ			0x44
#define FREQ_0X60_5765MHZ			0x9d

#define FREQ_0X5F_5784MHZ			0x45
#define FREQ_0X60_5784MHZ			0x9d

#define FREQ_0X5F_5800MHZ			0x46
#define FREQ_0X60_5800MHZ			0x9d

#define FREQ_0X5F_5819MHZ			0x47
#define FREQ_0X60_5819MHZ			0x9d

#define FREQ_0X5F_5836MHZ			0x40
#define FREQ_0X60_5836MHZ			0x9e

#define FREQ_0X5F_5851MHZ			0x41
#define FREQ_0X60_5851MHZ			0x9e

#define FREQ_0X5F_5869MHZ			0x42
#define FREQ_0X60_5869MHZ			0x9e

#define FREQ_0X5F_5888MHZ			0x43
#define FREQ_0X60_5888MHZ			0x9e

/*===================================================*/

#endif
