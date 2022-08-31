/*DS1302������ͷ�ļ���*/
#ifndef __DS1302_H
#define __DS1302_H

#include "ecbm_core.h" //���ؿ⺯����ͷ�ļ���

typedef struct
{
    u8 sclk_pin; // DS1302��SCLK��
    u8 dat_pin;  // DS1302��dat/io��
    u8 ce_pin;   // DS1302��ce��
    u8 year;     //��
    u8 month;    //��
    u8 day;      //��
    u8 hour;     //Сʱ
    u8 minute;   //����
    u8 second;   //��
    u8 dow;      //����(day of week)
} ds1302_def;

// DS1302�������ź���
extern void ds1302_set_pin(ds1302_def *dev, u8 sclk, u8 dat, u8 ce);
// DS1302��ʼ������
extern void ds1302_init(ds1302_def *dev, u8 sclk, u8 dat, u8 ce);

#endif