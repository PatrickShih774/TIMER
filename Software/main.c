#include "ecbm_core.h" //���ؿ⺯����ͷ�ļ���
#include "ST7567.h" //����st7567���ͷ�ļ���
void main()
{                  // main����������ġ�
    system_init(); //ϵͳ��ʼ��������Ҳ�Ǳ���ġ�
    Lcd_init();
    // Lcd_P16x16Ch(0, 0, "  ST7567  DEMO ", 0);
    // Lcd_P16x16Ch(0, 2, "   Һ��������   ", 0);
    // Lcd_P16x16Ch(0, 4, "   LCD12864 or  ", 0);
    // Lcd_P16x16Ch(0, 6, "    LCD13264    ", 0);
    // delay_ms(2000);
    // Lcd_cls();
    // Lcd_P16x16Ch(0, 0, "����ʱ��", 0);
    // Lcd_P5x7Str(64, 0, __DATE__, 0);
    // Lcd_P5x7Str(72, 1, __TIME__, 0);
    // Lcd_P16x16Ch(0, 2, " ������:ST7567 ", 0);
    // Lcd_P16x16Ch(0, 4, "�ӿ�:", 0);
    // Lcd_P16x16Ch(0, 6, "������:����׽�", 0);
    // delay_ms(2000);
    // Lcd_cls();
    // //ˢ������
    // Lcd_P16x16Ch(0, 0, "ˢ������:", 1);
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
    // // 8x16ASCLL����
    // Lcd_P16x16Ch(0, 0, "8x16ASCLL����:", 1);
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
    // // 5x7ASCLL����
    // Lcd_P16x16Ch(0, 0, "5x7ASCLL����:", 1);
    // Lcd_P5x7Str(0, 2, " !\"#$%&'()*+,-./01234", 0);
    // Lcd_P5x7Str(0, 3, "56789:;<=>?@ABCDEFGHI", 0);
    // Lcd_P5x7Str(0, 4, "JKLMNOPQRSTUVWXYZ[\\]^", 0);
    // Lcd_P5x7Str(0, 5, "_`abcdefghijklmnopqrs", 0);
    // Lcd_P5x7Str(0, 6, "tuvwxyz{|}~", 0);
    // delay_ms(2000);
    // Lcd_cls();
    // // 16x16���ֲ���
    // Lcd_P16x16Ch(0, 0, "16x16���ֲ���:", 1);
    // Lcd_P16x16Ch(0, 2, "�ܾúܾ���ǰ", 0);
    // delay_ms(800);
    // Lcd_P16x16Ch(0, 4, "����ͻȻ����", 0);
    // delay_ms(800);
    // Lcd_P16x16Ch(0, 6, "��������", 0);
    // delay_ms(800);
    // Lcd_cls();
    // Lcd_P16x16Ch(0, 0, "�����˹�������ʧ", 0);
    // Lcd_P16x16Ch(0, 2, "����", 0);
    // delay_ms(800);
    // Lcd_P16x16Ch(0, 4, "����ʮ��Σ��", 0);
    // delay_ms(800);
    // Lcd_P16x16Ch(0, 6, "����˭���¸�", 0);
    // delay_ms(2000);
    // Lcd_cls();
    while (1)
    {
        Lcd_P16x16Ch(0, 0, "  ST7567  DEMO ", 0);
        Lcd_P16x16Ch(0, 2, "   Һ��������   ", 0);
        Lcd_P16x16Ch(0, 4, "   LCD12864 or  ", 0);
        Lcd_P16x16Ch(0, 6, "    LCD13264    ", 0);

    }
}