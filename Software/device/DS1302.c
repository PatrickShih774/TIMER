#include "DS1302.h" //加载DS1302库的头文件。
u16 code READ_RTC_ADDR[7]  = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d}; //读寄存器的秒分钟日月周年
u16 code WRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c}; //写寄存器的秒分钟日月周年
u16 TIME[7]                = {0x50, 0x43, 0x21, 0x25, 0x07, 0x06, 0x20}; //数码管显示的时间2020年7月25日星期六21点43分50秒

/*-------------------------------------------------------
DS1302初始化函数
-------------------------------------------------------*/
void ds1302_init(ds1302_def *dev, u8 sclk, u8 dat, u8 ce)
{
    dev->sclk_pin = sclk;              //保存时钟脚设置。
    dev->dat_pin  = dat;               //保存数据脚设置。
    dev->ce_pin   = ce;                //保存使能脚设置。
    gpio_mode(dev->sclk_pin, GPIO_PP); //设置dev->dat_pin为推挽。
    gpio_mode(dev->dat_pin, GPIO_PU);  //设置dev->dat_pin为弱上拉。
    gpio_mode(dev->ce_pin, GPIO_PP);   //设置dev->dat_pin为推挽。
}

/////////////////////////////////////////////////////////////////////////////////

void write1302(ds1302_def *dev, u8 add, u8 dat) // DS1302的写操作（写地址，写数据）
{
    u8 i;
    dev->ce_pin   = 0;      //一开始dev->ce_pin为0
    dev->sclk_pin = 0;      //时钟线为0
    dev->ce_pin   = 1;      //过段时间dev->ce_pin为1开始工作
    for (i = 0; i < 8; i++) // FOR循环八次，写八次地址
    {

        dev->dat_pin = add & 0x01; //从最低位开始接收
        add >>= 1;                 //右移一位，执行8次
        dev->sclk_pin = 1;         //时钟线升高，上升沿
        dev->sclk_pin = 0;         //时钟线降低，为下一次for循环的上升沿做准备
    }
    for (i = 0; i < 8; i++) //与上同理
    {

        dev->dat_pin = dat & 0x01;
        dat >>= 1;
        dev->sclk_pin = 1;
        dev->sclk_pin = 0;
    }
    dev->ce_pin = 0; // dev->ce_pin为0，停止工作
}

u16 read1302(ds1302_def *dev, u8 add) // DS1302的读操作，注意因为是读操作，所以有返回值，不能为void而是需要unsigned，形参为之前的地址
{
    u8 i, dat, dat1;
    dev->sclk_pin = 0;
    dev->ce_pin   = 0;
    dev->ce_pin   = 1;
    for (i = 0; i < 8; i++)
    {
        dev->dat_pin = add & 0x01; //与上同理
        add >>= 1;
        dev->sclk_pin = 1; //读操作时，时钟线做下降沿
        dev->sclk_pin = 0;
    }
    for (i = 0; i < 8; i++)
    {
        dat1          = dev->dat_pin;
        dat           = (dat >> 1) | (dat1 << 7); // dat1左移7位变成最高位，dat1右移一位变成次高位，循环操作就能够将数据完整的读出
        dev->sclk_pin = 1;
        dev->sclk_pin = 0;
    }
    dev->ce_pin = 0;
    return dat; //返回dat值
}

void init1302(ds1302_def *dev) //初始化ds1302
{
    u8 i;
    write1302(dev, 0x8e, 0); //去除写保护
    for (i = 0; i < 7; i++)
    {
        write1302(dev, WRITE_RTC_ADDR[i], TIME[i]); //循环七次的目的就是为了能够将秒分钟日月周年输入，括号内就是为之前的写地址和写数据
    }
    write1302(dev, 0x8e, 0x80); //重新赋予写保护
}

void read1302time(ds1302_def *dev) //读取ds1302的数据
{
    u8 i;
    for (i = 0; i < 7; i++)
    {
        TIME[i] = read1302(dev, READ_RTC_ADDR[i]); //读七次，依次输出秒分钟日月周年，但是要注意的是，由于八段数码管数量有限，只能显示出时分秒
    }
}
