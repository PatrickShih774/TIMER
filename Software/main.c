#include "ecbm_core.h" //加载库函数的头文件。
#include "ST7567.h" //加载st7567库的头文件。
void main()
{                  // main函数，必须的。
    system_init(); //系统初始化函数，也是必须的。
    Lcd_init();
    // Lcd_P16x16Ch(0, 0, "  ST7567  DEMO ", 0);
    // Lcd_P16x16Ch(0, 2, "   液晶屏测试   ", 0);
    // Lcd_P16x16Ch(0, 4, "   LCD12864 or  ", 0);
    // Lcd_P16x16Ch(0, 6, "    LCD13264    ", 0);
    // delay_ms(2000);
    // Lcd_cls();
    // Lcd_P16x16Ch(0, 0, "测试时间", 0);
    // Lcd_P5x7Str(64, 0, __DATE__, 0);
    // Lcd_P5x7Str(72, 1, __TIME__, 0);
    // Lcd_P16x16Ch(0, 2, " 控制器:ST7567 ", 0);
    // Lcd_P16x16Ch(0, 4, "接口:", 0);
    // Lcd_P16x16Ch(0, 6, "测试人:社会易姐", 0);
    // delay_ms(2000);
    // Lcd_cls();
    // //刷屏测试
    // Lcd_P16x16Ch(0, 0, "刷屏测试:", 1);
    // delay_ms(1000);
    // Lcd_fill(0, 0, 132, 8, 0xff);
    // delay_ms(500);
    // Lcd_fill(0, 0, 132, 8, 0x00);
    // delay_ms(500);
    // Lcd_fill(0, 0, 132, 8, 0x55);
    // delay_ms(500);
    // Lcd_fill(0, 0, 132, 8, 0xaa);
    // delay_ms(500);
    // Lcd_cls();
    // // 8x16ASCLL测试
    // Lcd_P16x16Ch(0, 0, "8x16ASCLL测试:", 1);
    // Lcd_P16x16Ch(0, 2, " !\"#$%&'()*+,-./", 0);
    // Lcd_P16x16Ch(0, 4, "0123456789:;<=>?", 0);
    // Lcd_P16x16Ch(0, 6, "@ABCDEFGHIJKLMNO", 0);
    // delay_ms(2000);
    // Lcd_cls();
    // Lcd_P16x16Ch(0, 0, "PQRSTUVWXYZ[\\]^_", 0);
    // Lcd_P16x16Ch(0, 2, "`abcdefghijklmno", 0);
    // Lcd_P16x16Ch(0, 4, "pqrstuvwxyz{|}~", 0);
    // delay_ms(2000);
    // Lcd_cls();
    // // 5x7ASCLL测试
    // Lcd_P16x16Ch(0, 0, "5x7ASCLL测试:", 1);
    // Lcd_P5x7Str(0, 2, " !\"#$%&'()*+,-./01234", 0);
    // Lcd_P5x7Str(0, 3, "56789:;<=>?@ABCDEFGHI", 0);
    // Lcd_P5x7Str(0, 4, "JKLMNOPQRSTUVWXYZ[\\]^", 0);
    // Lcd_P5x7Str(0, 5, "_`abcdefghijklmnopqrs", 0);
    // Lcd_P5x7Str(0, 6, "tuvwxyz{|}~", 0);
    // delay_ms(2000);
    // Lcd_cls();
    // // 16x16汉字测试
    // Lcd_P16x16Ch(0, 0, "16x16汉字测试:", 1);
    // Lcd_P16x16Ch(0, 2, "很久很久以前", 0);
    // delay_ms(800);
    // Lcd_P16x16Ch(0, 4, "巨龙突然出现", 0);
    // delay_ms(800);
    // Lcd_P16x16Ch(0, 6, "带来灾难", 0);
    // delay_ms(800);
    // Lcd_cls();
    // Lcd_P16x16Ch(0, 0, "带走了公主又消失", 0);
    // Lcd_P16x16Ch(0, 2, "不见", 0);
    // delay_ms(800);
    // Lcd_P16x16Ch(0, 4, "王国十分危险", 0);
    // delay_ms(800);
    // Lcd_P16x16Ch(0, 6, "世间谁最勇敢", 0);
    // delay_ms(2000);
    // Lcd_cls();
    while (1)
    {
        Lcd_P16x16Ch(0, 0, "  ST7567  DEMO ", 0);
        Lcd_P16x16Ch(0, 2, "   液晶屏测试   ", 0);
        Lcd_P16x16Ch(0, 4, "   LCD12864 or  ", 0);
        Lcd_P16x16Ch(0, 6, "    LCD13264    ", 0);

    }
}