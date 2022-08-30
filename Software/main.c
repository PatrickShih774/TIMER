#include "ecbm_core.h" //加载库函数的头文件。
#include "ST7567.h"    //加载st7567库的头文件。
void main()
{                  // main函数，必须的。
    system_init(); //系统初始化函数，也是必须的。
    uart_string(1,"SYS INIT OK\r\n");//1 发送字符串SYS INIT OK并回车。   
    Lcd_init();//LCD屏幕初始化函数，配置LCD各项参数
    uart_string(1, "LCD INIT OK\r\n"); // 1 发送字符串LCD INIT OK并回车。

    while (1)
    {
        Lcd_P16x16Ch(0, 0, "  ST7567  DEMO ", 0);
        Lcd_P16x16Ch(0, 2, "   液晶屏测试   ", 0);
        Lcd_P16x16Ch(0, 4, "   LCD12864 or  ", 0);
        Lcd_P16x16Ch(0, 6, "    LCD13264    ", 0);
    }
}