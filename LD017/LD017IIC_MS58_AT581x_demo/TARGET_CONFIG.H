#ifndef __TARGET_CONFIG_H__
#define __TARGET_CONFIG_H__


/*========================��������======================*/
#define	TRUE	1
#define	FALSE	0

#define	PWR_40UA_SWITCH			TRUE	// ���ù��ġTTRUE - 40uA��ֻ��AT5815��Ч����FALSE - 68uA��AT5815����68uA��AT5812����9mA��
#define	SELF_CHECK_TIME			2000	// �ϵ��Լ�ʱ�� 0~65536 ms 
#define	LIGHT_OFF_TIME			1000	// �صƱ���ʱ�䣬����1000ms
#define	LIGHT_ON_BASE_TIME		500		// ����Ĭ��500ms
#define	LIGHT_ON_TIME			1500	// �ܿ���ʱ��=LIGHT_ON_BASE_TIME+LIGHT_ON_TIME����С������Ϊ1
#define	DELTA					200		// deltaֵ��0~1023��ֵԽ�����Խ��
#define	GAIN					0x3B	// ����ֵ��Χ��[0x0B, 0x1B, 0x2B, 0x3B, 0x4B, 0x5B, 0x6B, 0x7B, 0x8B, 0x9B, 0xAB, 0xBB, 0xCB]
										// default = 0x3B  ����Ĭ�ϡ��������Ӧ������2m�ڣ�ʹ�ã�����������Ӧ�ã�������Ϊ0x7B ~ 0x9B

// �����ǹ������ù���
#define	LIGHT_SENSOR_STATUS			0		// 0-�رչ��� 1-��������
#define	LIGHT_SENSOR_VALUE_LOW   	500		// ������ֵ : 0~1023, 10bit
#define	LIGHT_SENSOR_VALUE_HIGH  	530		// ������ֵ : 0~1023, 10bit
#define	LIGHT_SENSOR_INIVERSE    	0		// Ĭ��ֵ0����Ҫ�Ķ�

// ������Ƶ������ֵ
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