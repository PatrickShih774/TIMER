#include "ecbm_core.h" //���ؿ⺯����ͷ�ļ���
#include "ST7567.h"    //����st7567���ͷ�ļ���
void main()
{                  // main����������ġ�
    system_init(); //ϵͳ��ʼ��������Ҳ�Ǳ���ġ�
    uart_string(1,"SYS INIT OK\r\n");//1 �����ַ���SYS INIT OK���س���   
    Lcd_init();//LCD��Ļ��ʼ������������LCD�������
    uart_string(1, "LCD INIT OK\r\n"); // 1 �����ַ���LCD INIT OK���س���

    while (1)
    {
        Lcd_P16x16Ch(0, 0, "  ST7567  DEMO ", 0);
        Lcd_P16x16Ch(0, 2, "   Һ��������   ", 0);
        Lcd_P16x16Ch(0, 4, "   LCD12864 or  ", 0);
        Lcd_P16x16Ch(0, 6, "    LCD13264    ", 0);
    }
}