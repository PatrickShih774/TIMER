/*****************************************
模块名称：ST7567驱动
作者：SocialSisterYi
制作时间：2017.2
说明：ST7567（兼容ST7565、UC1701等等。。。）为单色STN控制器，接口：SPI/8-bit并口，分辨率132*64+1ICON,取模方式：8位竖置横排下高位
备注：
*****************************************/
#include "ST7567.h"

bit lcd_seg_reverse        = LCD_SEG_REVERSE,
    lcd_com_reverse        = LCD_COM_REVERSE,
    lcd_black_reverse      = LCD_BLACK_REVERSE;
unsigned char lcd_contrast = LCD_CONTRAST;

void Lcd_write_byte(unsigned char Byte)
{
    char i;
    for (i = 0; i < 8; i++)
    {
        LCD_CLK = 0;
        delay_us(2);
        if (Byte & 0x80)
            LCD_DAT = 1;
        else
            LCD_DAT = 0;
        LCD_CLK = 1;
        delay_us(2);
        Byte = Byte <<= 1;
    }
}
/*********************************
函数名称：Lcd_write_cmd
功能：LCD写指令
输入：写入指令
输出：无
备注：
*********************************/
void Lcd_write_cmd(unsigned char cmd)
{
    EA     = 0;
    LCD_CS = 0;
    LCD_RS = 0;
    Lcd_write_byte(cmd);
    LCD_CS = 1;
    EA     = 1;
}
/*********************************
函数名称：Lcd_write_dat
功能：LCD写数据
输入：写入数据
输出：无
备注：
*********************************/
void Lcd_write_dat(unsigned char dat)
{
    EA     = 0;
    LCD_CS = 0;
    LCD_RS = 1;
    Lcd_write_byte(dat);
    LCD_CS = 1;
    EA     = 1;
}
/*********************************
函数名称：Lcd_set_pos
功能：LCD设置坐标
输入：x坐标，y坐标
输出：无
备注：x<=131，y<=7
*********************************/
void Lcd_set_pos(unsigned char x, unsigned char y)
{
    if (lcd_seg_reverse)
        x += (132 - LCD_WEIGHT);
    Lcd_write_cmd(LCD_Set_Page_Address + y);                             //页地址
    Lcd_write_cmd(LCD_Set_Column_Address_lower_bit | x & 0x0f);          //低地址
    Lcd_write_cmd(LCD_Set_Column_Address_upper_bit | ((x & 0xf0) >> 4)); //高地址
}
/*********************************
函数名称：Lcd_fill
功能：LCD填充
输入：x起始坐标，y起始坐标，长度，宽度，填充值
输出：无
备注：
*********************************/
void Lcd_fill(unsigned char x0, unsigned char y0, unsigned char h, unsigned char w, unsigned char dat)
{
    unsigned char x;
    if (x0 > 131 || h > 132 || y0 > 7 || w > 8)
        return;
    h = h + x0 - 1; //计算坐标增量终止值
    w = w + y0 - 1;
    for (; y0 <= w; y0++)
    {
        Lcd_set_pos(x0, y0);
        for (x = x0; x <= h; x++)
            Lcd_write_dat(dat);
    }
}
/*********************************
函数名称：Lcd_cls
功能：LCD清屏
输入：无
输出：无
备注：
*********************************/
void Lcd_cls()
{
    Lcd_fill(0, 0, 132, 8, 0x00);
}
/*********************************
函数名称：Lcd_on
功能：LCD开启显示
输入：无
输出：无
备注：
*********************************/
void Lcd_on()
{
    Lcd_write_cmd(LCD_Set_Display_ON_OFF | LCD_Display_ON);
}
/*********************************
函数名称：Lcd_off
功能：LCD关闭显示
输入：无
输出：无
备注：
*********************************/
void Lcd_off()
{
    Lcd_write_cmd(LCD_Set_Display_ON_OFF | LCD_Display_OFF);
}
/*********************************
函数名称：Lcd_set_seg_reverse
功能：LCD设置垂直镜像
输入：0正常，1反转
输出：无
备注：只改变输入方向，不改变扫描方向
*********************************/
void Lcd_set_seg_reverse(bit on)
{
    lcd_seg_reverse = on;
    Lcd_write_cmd(LCD_Set_SEG_Direction | (on ? LCD_SEG_Direction_reverse : LCD_SEG_Direction_normal));
}
/*********************************
函数名称：Lcd_set_com_reverse
功能：LCD设置水平镜像
输入：0正常，1反转
输出：无
备注：
*********************************/
void Lcd_set_com_reverse(bit on)
{
    lcd_com_reverse = on;
    Lcd_write_cmd(LCD_Set_COM_Direction | (on ? LCD_COM_Direction_reverse : LCD_COM_Direction_normal));
}

/*********************************
函数名称：Lcd_set_com_reverse
功能：LCD设置反色显示
输入：0正常，1反转
输出：无
备注：
*********************************/
void Lcd_set_black_reverse(bit on)
{
    lcd_black_reverse = on;
    Lcd_write_cmd(LCD_Inverse_Display | (on ? LCD_Inverse_Display_inverse : LCD_Inverse_Display_normal));
}

/*********************************
函数名称：Lcd_set_contrast
功能：LCD设置对比度
输入：对比度
输出：无
备注：
*********************************/
void Lcd_set_contrast(unsigned char contrast)
{
    if (contrast > 63)
        return;
    lcd_contrast = contrast;
    Lcd_write_cmd(LCD_Set_EV);
    Lcd_write_cmd(contrast);
}
/*********************************
函数名称：Lcd_write_icon
功能：LCD写图标RAM（第9PAGE）
输入：图标序号，显示/关闭
输出：无
备注：
*********************************/
#if LCD_ICON
void Lcd_write_icon(unsigned char num, bit value)
{
    if (num > 131)
        return;
    Lcd_set_pos(num, 8);
    Lcd_write_dat(value);
}

/*********************************
函数名称：Lcd_clear_icon
功能：LCD清除所有图标
输入：无
输出：无
备注：
*********************************/
void Lcd_clear_icon()
{
    unsigned char i;
    for (i = 0; i < 131; i++)
        Lcd_write_icon(i, 0);
}
#endif
/*********************************
函数名称：Lcd_init
功能：LCD初始化
输入：无
输出：无
备注：
*********************************/
void Lcd_init()
{
    gpio_mode(D32, GPIO_PP);
    gpio_mode(D33, GPIO_PP);
    gpio_mode(D34, GPIO_PP);
    gpio_mode(D35, GPIO_PP);
    gpio_mode(D36, GPIO_PP);
    LCD_RST = 0; //硬复位
    delay_ms(10);
    LCD_RST = 1;
    delay_ms(10);

    Lcd_write_cmd(LCD_Reset); //软复位
    delay_ms(5);
    Lcd_write_cmd(LCD_Set_Display_ON_OFF); //开显示
    delay_ms(5);
    Lcd_write_cmd(0x2c); //升压步聚1打开内部升压
    delay_ms(5);
    Lcd_write_cmd(0x2e); //升压步聚2电压调整电路
    delay_ms(5);
    Lcd_write_cmd(0x2f); //升压步聚3电压跟随器
    delay_ms(5);
    Lcd_write_cmd(0x24); /*粗调对比度，可设置范围0x20～0x27*/
    Lcd_write_cmd(0x81); /*微调对比度*/
    Lcd_write_cmd(0x2f); /*微调对比度的值，可设置范围0x00～0x3f*/
    Lcd_write_cmd(0xa2); /*1/9 偏压比（bias）*/
    Lcd_write_cmd(0xc8); /*行扫描顺序：从上到下*/
    Lcd_write_cmd(0xa0); /*列扫描顺序：从左到右*/
    Lcd_write_cmd(0x40); /*起始行：第一行开始*/
    Lcd_write_cmd(0xaf); /*开显示*/
    Lcd_cls();           //清屏
#if LCD_ICON
    Lcd_clear_icon();
#endif
    Lcd_set_pos(0, 0); //坐标归位
    Lcd_write_cmd(0xaf); /*开显示*/
    //uart_printf(1, "LCD init OK");
}
/*********************************
函数名称：Lcd_pic
功能：LCD显示图片
输入：x起始坐标，y起始坐标，长度，宽度，图片数据，反显
输出：无
备注：
*********************************/
void Lcd_pic(unsigned char x0, unsigned char y0, unsigned char h, unsigned char w, unsigned char *pic, bit b)
{
    unsigned char x;
    if (x0 > 131 || h > 132 || y0 > 7 || w > 8)
        return;
    h = h + x0 - 1; //计算坐标增量终止值
    w = w + y0 - 1;
    for (; y0 <= w; y0++)
    {
        Lcd_set_pos(x0, y0);
        for (x = x0; x <= h; x++)
            Lcd_write_dat(b ? ~*pic++ : *pic++);
    }
}
/*********************************
函数名称：Lcd_P8x16char
功能：LCD显示一个8x16字符
输入：x坐标，y坐标，字符，反显
输出：无
备注：
*********************************/
#if (LCD_ASCLL8X16 || LCD_CH16X16)
#include "ASC8X16.h"
void Lcd_P8x16char(unsigned char x, unsigned char y, unsigned char chr, bit b)
{
    if (x > 131 || y > 7 || chr > 127)
        return;
    Lcd_pic(x, y, 8, 2, &ASC8X16[(chr - 32) * 16], b);
}
/*********************************
函数名称：Lcd_P8x16Str
功能：LCD显示8x16字符串
输入：x坐标，y坐标，字符串，反显
输出：无
备注：
*********************************/
void Lcd_P8x16Str(unsigned char x, unsigned char y, unsigned char *str, bit b)
{
    while (*str != '\0')
    {
        Lcd_P8x16char(x, y, *str++, b);
        x += 8;
    }
}
#endif
/*********************************
函数名称：Lcd_P5x7char
功能：LCD显示一个5x7字符
输入：x坐标，y坐标，字符，反显
输出：无
备注：
*********************************/
#if LCD_ASCLL5X7
#include "ASC5X7.h"
void Lcd_P5x7char(unsigned char x, unsigned char y, unsigned char chr, bit b)
{
    if (x > 131 || y > 7 || chr > 127)
        return;
    Lcd_pic(x, y, 5, 1, &ASC5X7[(chr - 32) * 5], b);
}

/*********************************
函数名称：Lcd_P5x7Str
功能：LCD显示5x7字符串
输入：x坐标，y坐标，字符串，反显
输出：无
备注：
*********************************/
void Lcd_P5x7Str(unsigned char x, unsigned char y, unsigned char *str, bit b)
{
    while (*str != '\0')
    {
        Lcd_P5x7char(x, y, *str++, b);
        x += 6;
    }
}
#endif

/*********************************
函数名称：Lcd_P16x16Ch
功能：LCD显示中文和8x16字符串
输入：x坐标，y坐标，字符串，反显
输出：无
备注：
*********************************/
#if LCD_CH16X16
#include "CH16X16.h"
const unsigned int CH_NUM = (sizeof GB_16) / 34; //计算字库字数

void Lcd_P16x16Ch(unsigned char x, unsigned char y, unsigned char *cnstr, bit b)
{

    unsigned int word;
    if (x > 131 || y > 7)
        return;
    while (*cnstr != '\0')
    {
        if (*cnstr >= 0x81) //文字为汉字
        {
            for (word = 0; word <= CH_NUM; word++) //搜索字库
                if ((GB_16[word].Index[0] == *cnstr) && (GB_16[word].Index[1] == *(cnstr + 1)))
                    Lcd_pic(x, y, 16, 2, GB_16[word].Msk, b);
            x += 16;
            cnstr += 2;
        }
        else //文字为ASCLL字符
        {
            Lcd_P8x16char(x, y, *cnstr, b);
            cnstr++;
            x += 8;
        }
    }
}
#endif