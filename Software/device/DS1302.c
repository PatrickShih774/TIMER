#include "DS1302.h" //����DS1302���ͷ�ļ���
u16 code READ_RTC_ADDR[7]  = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d}; //���Ĵ������������������
u16 code WRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c}; //д�Ĵ������������������
u16 TIME[7]                = {0x50, 0x43, 0x21, 0x25, 0x07, 0x06, 0x20}; //�������ʾ��ʱ��2020��7��25��������21��43��50��

/*-------------------------------------------------------
DS1302��ʼ������
-------------------------------------------------------*/
void ds1302_init(ds1302_def *dev, u8 sclk, u8 dat, u8 ce)
{
    dev->sclk_pin = sclk;              //����ʱ�ӽ����á�
    dev->dat_pin  = dat;               //�������ݽ����á�
    dev->ce_pin   = ce;                //����ʹ�ܽ����á�
    gpio_mode(dev->sclk_pin, GPIO_PP); //����dev->dat_pinΪ���졣
    gpio_mode(dev->dat_pin, GPIO_PU);  //����dev->dat_pinΪ��������
    gpio_mode(dev->ce_pin, GPIO_PP);   //����dev->dat_pinΪ���졣
}

/////////////////////////////////////////////////////////////////////////////////

void write1302(ds1302_def *dev, u8 add, u8 dat) // DS1302��д������д��ַ��д���ݣ�
{
    u8 i;
    dev->ce_pin   = 0;      //һ��ʼdev->ce_pinΪ0
    dev->sclk_pin = 0;      //ʱ����Ϊ0
    dev->ce_pin   = 1;      //����ʱ��dev->ce_pinΪ1��ʼ����
    for (i = 0; i < 8; i++) // FORѭ���˴Σ�д�˴ε�ַ
    {

        dev->dat_pin = add & 0x01; //�����λ��ʼ����
        add >>= 1;                 //����һλ��ִ��8��
        dev->sclk_pin = 1;         //ʱ�������ߣ�������
        dev->sclk_pin = 0;         //ʱ���߽��ͣ�Ϊ��һ��forѭ������������׼��
    }
    for (i = 0; i < 8; i++) //����ͬ��
    {

        dev->dat_pin = dat & 0x01;
        dat >>= 1;
        dev->sclk_pin = 1;
        dev->sclk_pin = 0;
    }
    dev->ce_pin = 0; // dev->ce_pinΪ0��ֹͣ����
}

u16 read1302(ds1302_def *dev, u8 add) // DS1302�Ķ�������ע����Ϊ�Ƕ������������з���ֵ������Ϊvoid������Ҫunsigned���β�Ϊ֮ǰ�ĵ�ַ
{
    u8 i, dat, dat1;
    dev->sclk_pin = 0;
    dev->ce_pin   = 0;
    dev->ce_pin   = 1;
    for (i = 0; i < 8; i++)
    {
        dev->dat_pin = add & 0x01; //����ͬ��
        add >>= 1;
        dev->sclk_pin = 1; //������ʱ��ʱ�������½���
        dev->sclk_pin = 0;
    }
    for (i = 0; i < 8; i++)
    {
        dat1          = dev->dat_pin;
        dat           = (dat >> 1) | (dat1 << 7); // dat1����7λ������λ��dat1����һλ��ɴθ�λ��ѭ���������ܹ������������Ķ���
        dev->sclk_pin = 1;
        dev->sclk_pin = 0;
    }
    dev->ce_pin = 0;
    return dat; //����datֵ
}

void init1302(ds1302_def *dev) //��ʼ��ds1302
{
    u8 i;
    write1302(dev, 0x8e, 0); //ȥ��д����
    for (i = 0; i < 7; i++)
    {
        write1302(dev, WRITE_RTC_ADDR[i], TIME[i]); //ѭ���ߴε�Ŀ�ľ���Ϊ���ܹ�������������������룬�����ھ���Ϊ֮ǰ��д��ַ��д����
    }
    write1302(dev, 0x8e, 0x80); //���¸���д����
}

void read1302time(ds1302_def *dev) //��ȡds1302������
{
    u8 i;
    for (i = 0; i < 7; i++)
    {
        TIME[i] = read1302(dev, READ_RTC_ADDR[i]); //���ߴΣ��������������������꣬����Ҫע����ǣ����ڰ˶�������������ޣ�ֻ����ʾ��ʱ����
    }
}
