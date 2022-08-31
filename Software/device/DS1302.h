/*DS1302驱动（头文件）*/
#ifndef __DS1302_H
#define __DS1302_H

#include "ecbm_core.h" //加载库函数的头文件。

typedef struct
{
    u8 sclk_pin; // DS1302的SCLK脚
    u8 dat_pin;  // DS1302的dat/io脚
    u8 ce_pin;   // DS1302的ce脚
    u8 year;     //年
    u8 month;    //月
    u8 day;      //日
    u8 hour;     //小时
    u8 minute;   //分钟
    u8 second;   //秒
    u8 dow;      //星期(day of week)
} ds1302_def;

// DS1302配置引脚函数
extern void ds1302_set_pin(ds1302_def *dev, u8 sclk, u8 dat, u8 ce);
// DS1302初始化函数
extern void ds1302_init(ds1302_def *dev, u8 sclk, u8 dat, u8 ce);

#endif