#include "ecbm_core.h" //加载库函数的头文件。
#include "ST7567.h"    //加载st7567库的头文件。
#include "DS1302.h"    //加载DS1302库的头文件。
#include "EC11.h"      //加载EC11库的头文件。
ds1302_def ds1302;     //定义一个OLED对象。
void main()
{
    system_init();                        //系统初始化函数，是必须的。
    uart_string(1, "SYS INIT OK\r\n");    // 发送字符串SYS INIT OK并回车。
    Lcd_init();                           // LCD屏幕初始化函数，配置LCD各项参数
    uart_string(1, "LCD INIT OK\r\n");    // 发送字符串LCD INIT OK并回车。
    ds1302_init(&ds1302, D15, D16, D17);  // DS1302初始化函数，
    uart_string(1, "DS1302 INIT OK\r\n"); // 发送字符串DS1302 INIT OK并回车。
    while (1)
    {
        Lcd_P16x16Ch(18, 0, "DS1302测试", 1);
        Lcd_P8x16Str(25, 3, "20", 0); // x,y,时,反显
        Lcd_P8x16Str(42, 3, ":", 0);
        Lcd_P8x16Str(50, 3, "24", 0); // x,y,分,反显
        Lcd_P8x16Str(70, 3, ":", 0);
        Lcd_P8x16Str(80, 3, "59", 0); // x,y,秒,反显
        Lcd_P8x16Str(17, 6, __DATE__, 0);
    }
}