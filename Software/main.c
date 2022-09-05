#include "ecbm_core.h" //���ؿ⺯����ͷ�ļ���
#include "ST7567.h"    //����st7567���ͷ�ļ���
#include "DS1302.h"    //����DS1302���ͷ�ļ���
#include "EC11.h"      //����EC11���ͷ�ļ���

void main()
{

    system_init();                        //ϵͳ��ʼ���������Ǳ���ġ�
    uart_string(1, "SYS INIT OK\r\n");    // �����ַ���SYS INIT OK���س���
    Lcd_init();                           // LCD��Ļ��ʼ������������LCD�������
    uart_string(1, "LCD INIT OK\r\n");    // �����ַ���LCD INIT OK���س���
    DS1302_Init();                        // DS1302��ʼ��������
    uart_string(1, "DS1302 INIT OK\r\n"); // �����ַ���DS1302 INIT OK���س���
    DS1302_WriteReg(DS1302_W_PROTECT, 0x00); // д������
    DS1302_WriteReg(DS1302_W_HOUR, HEX2BCD(21));
    DS1302_WriteReg(DS1302_W_MINUTE, HEX2BCD(33));
    DS1302_WriteReg(DS1302_W_SECOND, HEX2BCD(00));
    DS1302_WriteReg(DS1302_W_PROTECT, 0x80); // д������
    while (1)
    {
        unsigned char str[9];
        Lcd_P16x16Ch(18, 0, "DS1302����", 1);
        str[0] = (DS1302_ReadReg(DS1302_R_HOUR) >> 4) + 0x30;
        str[1] = (DS1302_ReadReg(DS1302_R_HOUR) & 0x0f) + 0x30;
        str[2] = 0x3a;
        str[3] = (DS1302_ReadReg(DS1302_R_MINUTE) >> 4) + 0x30;
        str[4] = (DS1302_ReadReg(DS1302_R_MINUTE) & 0x0f) + 0x30;
        str[5] = 0x3a;
        str[6] = (DS1302_ReadReg(DS1302_R_SECOND) >> 4) + 0x30;
        str[7] = (DS1302_ReadReg(DS1302_R_SECOND) & 0x0f) + 0x30;

        //uart_string(1, str);
        //uart_string(1,  "\r\n ");            
        Lcd_P8x16Str(25, 3, str, 0);
        Lcd_P8x16Str(17, 6, __DATE__, 0);
        //uart_printf(1,str);
        if (EC11_M == 0)
        {
            delay_ms(50);
            LCD_BL = !LCD_BL;
        }
    }
}