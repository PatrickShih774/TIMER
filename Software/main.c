#include "ecbm_core.h" //���ؿ⺯����ͷ�ļ���
#include "ST7567.h"    //����st7567���ͷ�ļ���
#include "DS1302.h"    //����DS1302���ͷ�ļ���
#include "EC11.h"      //����EC11���ͷ�ļ���
ds1302_def ds1302;     //����һ��OLED����
void main()
{
    system_init();                        //ϵͳ��ʼ���������Ǳ���ġ�
    uart_string(1, "SYS INIT OK\r\n");    // �����ַ���SYS INIT OK���س���
    Lcd_init();                           // LCD��Ļ��ʼ������������LCD�������
    uart_string(1, "LCD INIT OK\r\n");    // �����ַ���LCD INIT OK���س���
    ds1302_init(&ds1302, D15, D16, D17);  // DS1302��ʼ��������
    uart_string(1, "DS1302 INIT OK\r\n"); // �����ַ���DS1302 INIT OK���س���
    while (1)
    {
        Lcd_P16x16Ch(18, 0, "DS1302����", 1);
        Lcd_P8x16Str(25, 3, "20", 0); // x,y,ʱ,����
        Lcd_P8x16Str(42, 3, ":", 0);
        Lcd_P8x16Str(50, 3, "24", 0); // x,y,��,����
        Lcd_P8x16Str(70, 3, ":", 0);
        Lcd_P8x16Str(80, 3, "59", 0); // x,y,��,����
        Lcd_P8x16Str(17, 6, __DATE__, 0);
    }
}