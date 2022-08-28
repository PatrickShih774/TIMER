#include "ecbm_core.h" //统一加载核心头文件
u8 code ecbm_pin_mask[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
u8 data ecbm_port, ecbm_pin;
/*--------------------------------------程序定义-----------------------------------*/
/*程序区折叠专用************************IO设置模块******************************/ #if 1 
void gpio_analysis(u8 pin)
{
    ecbm_port = pin & 0xf0;
    ecbm_pin  = ecbm_pin_mask[pin & 0x0f];
}
/*-------------------------------------------------------
IO口上拉电阻配置函数。
-------------------------------------------------------*/
#if ECBM_GPIO_UPPULL_EN
void gpio_uppull(u8 pin, u8 en)
{
    /*---从这里开始，都是在解读IO口编号。---*/
    if ((pin & 0x0f) > 7) return;
    gpio_analysis(pin);
    /*-------到这里结束，解读完成。-------*/
    switch (ecbm_port)
    {
        default:
            break;
#if ECBM_GPIO0_EN
        case 0x00:
            if (en) { P0PU |= ecbm_pin; }
            else { P0PU &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO1_EN
        case 0x10:
            if (en) { P1PU |= ecbm_pin; }
            else { P1PU &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO2_EN
        case 0x20:
            if (en) { P2PU |= ecbm_pin; }
            else { P2PU &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO3_EN
        case 0x30:
            if (en) { P3PU |= ecbm_pin; }
            else { P3PU &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO4_EN
        case 0x40:
            if (en) { P4PU |= ecbm_pin; }
            else { P4PU &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO5_EN
        case 0x50:
            if (en) { P5PU |= ecbm_pin; }
            else { P5PU &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO6_EN
        case 0x60:
            if (en) { P6PU |= ecbm_pin; }
            else { P6PU &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO7_EN
        case 0x70:
            if (en) { P7PU |= ecbm_pin; }
            else { P7PU &= ~ecbm_pin; }
            break;
#endif
    }
}
#endif
/*-------------------------------------------------------
设置IO口工作模式函数。
-------------------------------------------------------*/
#if ECBM_GPIO_MODE_EN
void gpio_mode(u8 pin, u8 mode)
{
    /*---从这里开始，都是在解读IO口编号。---*/
    if ((pin & 0x0f) > 7) return;
    gpio_analysis(pin);
    /*-------到这里结束，解读完成。-------*/
    if (mode == GPIO_PU)
    {
#if ECBM_GPIO0_EN
        if (ecbm_port == 0x00)
        {
            P0M1 &= ~ecbm_pin;
            P0M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO1_EN
        if (ecbm_port == 0x10)
        {
            P1M1 &= ~ecbm_pin;
            P1M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO2_EN
        if (ecbm_port == 0x20)
        {
            P2M1 &= ~ecbm_pin;
            P2M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO3_EN
        if (ecbm_port == 0x30)
        {
            P3M1 &= ~ecbm_pin;
            P3M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO4_EN
        if (ecbm_port == 0x40)
        {
            P4M1 &= ~ecbm_pin;
            P4M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO5_EN
        if (ecbm_port == 0x50)
        {
            P5M1 &= ~ecbm_pin;
            P5M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO6_EN
        if (ecbm_port == 0x60)
        {
            P6M1 &= ~ecbm_pin;
            P6M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO7_EN
        if (ecbm_port == 0x70)
        {
            P7M1 &= ~ecbm_pin;
            P7M0 &= ~ecbm_pin;
        }
#endif
    }
    if (mode == GPIO_HZ)
    {
#if ECBM_GPIO0_EN
        if (ecbm_port == 0x00)
        {
            P0M1 |= ecbm_pin;
            P0M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO1_EN
        if (ecbm_port == 0x10)
        {
            P1M1 |= ecbm_pin;
            P1M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO2_EN
        if (ecbm_port == 0x20)
        {
            P2M1 |= ecbm_pin;
            P2M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO3_EN
        if (ecbm_port == 0x30)
        {
            P3M1 |= ecbm_pin;
            P3M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO4_EN
        if (ecbm_port == 0x40)
        {
            P4M1 |= ecbm_pin;
            P4M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO5_EN
        if (ecbm_port == 0x50)
        {
            P5M1 |= ecbm_pin;
            P5M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO6_EN
        if (ecbm_port == 0x60)
        {
            P6M1 |= ecbm_pin;
            P6M0 &= ~ecbm_pin;
        }
#endif
#if ECBM_GPIO7_EN
        if (ecbm_port == 0x70)
        {
            P7M1 |= ecbm_pin;
            P7M0 &= ~ecbm_pin;
        }
#endif
    }
    if (mode == GPIO_OD)
    {
#if ECBM_GPIO0_EN
        if (ecbm_port == 0x00)
        {
            P0M1 |= ecbm_pin;
            P0M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO1_EN
        if (ecbm_port == 0x10)
        {
            P1M1 |= ecbm_pin;
            P1M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO2_EN
        if (ecbm_port == 0x20)
        {
            P2M1 |= ecbm_pin;
            P2M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO3_EN
        if (ecbm_port == 0x30)
        {
            P3M1 |= ecbm_pin;
            P3M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO4_EN
        if (ecbm_port == 0x40)
        {
            P4M1 |= ecbm_pin;
            P4M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO5_EN
        if (ecbm_port == 0x50)
        {
            P5M1 |= ecbm_pin;
            P5M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO6_EN
        if (ecbm_port == 0x60)
        {
            P6M1 |= ecbm_pin;
            P6M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO7_EN
        if (ecbm_port == 0x70)
        {
            P7M1 |= ecbm_pin;
            P7M0 |= ecbm_pin;
        }
#endif
    }
    if (mode == GPIO_PP)
    {
#if ECBM_GPIO0_EN
        if (ecbm_port == 0x00)
        {
            P0M1 &= ~ecbm_pin;
            P0M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO1_EN
        if (ecbm_port == 0x10)
        {
            P1M1 &= ~ecbm_pin;
            P1M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO2_EN
        if (ecbm_port == 0x20)
        {
            P2M1 &= ~ecbm_pin;
            P2M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO3_EN
        if (ecbm_port == 0x30)
        {
            P3M1 &= ~ecbm_pin;
            P3M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO4_EN
        if (ecbm_port == 0x40)
        {
            P4M1 &= ~ecbm_pin;
            P4M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO5_EN
        if (ecbm_port == 0x50)
        {
            P5M1 &= ~ecbm_pin;
            P5M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO6_EN
        if (ecbm_port == 0x60)
        {
            P6M1 &= ~ecbm_pin;
            P6M0 |= ecbm_pin;
        }
#endif
#if ECBM_GPIO7_EN
        if (ecbm_port == 0x70)
        {
            P7M1 &= ~ecbm_pin;
            P7M0 |= ecbm_pin;
        }
#endif
    }
}
#endif
/*程序区折叠专用**************************************************************/ #endif
    /*程序区折叠专用**********************普通IO操作模块****************************/ #if 1
/*-------------------------------------------------------
P口写入函数，直接写入8位数据到某个P口上。
-------------------------------------------------------*/
#if ECBM_GPIO_WRITE_EN
    void
    gpio_write(u8 port, u8 dat)
{
#if ECBM_GPIO0_EN
    if (port == GPIO_P0) P0 = dat;
#endif
#if ECBM_GPIO1_EN
    if (port == GPIO_P1) P1 = dat;
#endif
#if ECBM_GPIO2_EN
    if (port == GPIO_P2) P2 = dat;
#endif
#if ECBM_GPIO3_EN
    if (port == GPIO_P3) P3 = dat;
#endif
#if ECBM_GPIO4_EN
    if (port == GPIO_P4) P4 = dat;
#endif
#if ECBM_GPIO5_EN
    if (port == GPIO_P5) P5 = dat;
#endif
#if ECBM_GPIO6_EN
    if (port == GPIO_P6) P6 = dat;
#endif
#if ECBM_GPIO7_EN
    if (port == GPIO_P7) P7 = dat;
#endif
}
#endif
/*-------------------------------------------------------
P口读出函数，将整个P口的值一次性读出(并口)。
-------------------------------------------------------*/
#if ECBM_GPIO_READ_EN
u8 gpio_read(u8 port)
{
#if ECBM_GPIO0_EN
    if (port == GPIO_P0) return P0;
#endif
#if ECBM_GPIO1_EN
    if (port == GPIO_P1) return P1;
#endif
#if ECBM_GPIO2_EN
    if (port == GPIO_P2) return P2;
#endif
#if ECBM_GPIO3_EN
    if (port == GPIO_P3) return P3;
#endif
#if ECBM_GPIO4_EN
    if (port == GPIO_P4) return P4;
#endif
#if ECBM_GPIO5_EN
    if (port == GPIO_P5) return P5;
#endif
#if ECBM_GPIO6_EN
    if (port == GPIO_P6) return P6;
#endif
#if ECBM_GPIO7_EN
    if (port == GPIO_P7) return P7;
#endif
    return 0xff;
}
#endif
/*-------------------------------------------------------
IO口输出函数。
-------------------------------------------------------*/
#if ECBM_GPIO_OUT_EN
void gpio_out(u8 pin, u8 value)
{
    /*---从这里开始，都是在解读IO口编号。---*/
    if ((pin & 0x0f) > 7) return;
    gpio_analysis(pin);
    /*-------到这里结束，解读完成。-------*/
    switch (ecbm_port)
    {
        default:
            break;
#if ECBM_GPIO0_EN
        case 0x00:
            if (value) { P0 |= ecbm_pin; }
            else { P0 &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO1_EN
        case 0x10:
            if (value) { P1 |= ecbm_pin; }
            else { P1 &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO2_EN
        case 0x20:
            if (value) { P2 |= ecbm_pin; }
            else { P2 &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO3_EN
        case 0x30:
            if (value) { P3 |= ecbm_pin; }
            else { P3 &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO4_EN
        case 0x40:
            if (value) { P4 |= ecbm_pin; }
            else { P4 &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO5_EN
        case 0x50:
            if (value) { P5 |= ecbm_pin; }
            else { P5 &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO6_EN
        case 0x60:
            if (value) { P6 |= ecbm_pin; }
            else { P6 &= ~ecbm_pin; }
            break;
#endif
#if ECBM_GPIO7_EN
        case 0x70:
            if (value) { P7 |= ecbm_pin; }
            else { P7 &= ~ecbm_pin; }
            break;
#endif
    }
}
#endif
/*-------------------------------------------------------
IO口输入函数。
-------------------------------------------------------*/
#if ECBM_GPIO_IN_EN
u8 gpio_in(u8 pin)
{
    u8 value;
    /*---从这里开始，都是在解读IO口编号。---*/
    if ((pin & 0x0f) > 7) return 1;
    gpio_analysis(pin);
/*-------到这里结束，解读完成。-------*/
#if ECBM_GPIO0_EN
    if (ecbm_port == 0x00)
    {
        value = P0;
    }
#endif
#if ECBM_GPIO1_EN
    if (ecbm_port == 0x10)
    {
        value = P1;
    }
#endif
#if ECBM_GPIO2_EN
    if (ecbm_port == 0x20)
    {
        value = P2;
    }
#endif
#if ECBM_GPIO3_EN
    if (ecbm_port == 0x30)
    {
        value = P3;
    }
#endif
#if ECBM_GPIO4_EN
    if (ecbm_port == 0x40)
    {
        value = P4;
    }
#endif
#if ECBM_GPIO5_EN
    if (ecbm_port == 0x50)
    {
        value = P5;
    }
#endif
#if ECBM_GPIO6_EN
    if (ecbm_port == 0x60)
    {
        value = P6;
    }
#endif
#if ECBM_GPIO7_EN
    if (ecbm_port == 0x70)
    {
        value = P7;
    }
#endif
    if (value & ecbm_pin)
        return 1;
    else
        return 0;
}
#endif
/*-------------------------------------------------------
IO口电平翻转函数。
-------------------------------------------------------*/
#if ECBM_GPIO_TOGGLE_EN
void gpio_toggle(u8 pin)
{
    /*---从这里开始，都是在解读IO口编号。---*/
    if ((pin & 0x0f) > 7) return;
    gpio_analysis(pin);
/*-------到这里结束，解读完成。-------*/
#if ECBM_GPIO0_EN
    if (ecbm_port == 0x00)
    {
        P0 ^= ecbm_pin;
    }
#endif
#if ECBM_GPIO1_EN
    if (ecbm_port == 0x10)
    {
        P1 ^= ecbm_pin;
    }
#endif
#if ECBM_GPIO2_EN
    if (ecbm_port == 0x20)
    {
        P2 ^= ecbm_pin;
    }
#endif
#if ECBM_GPIO3_EN
    if (ecbm_port == 0x30)
    {
        P3 ^= ecbm_pin;
    }
#endif
#if ECBM_GPIO4_EN
    if (ecbm_port == 0x40)
    {
        P4 ^= ecbm_pin;
    }
#endif
#if ECBM_GPIO5_EN
    if (ecbm_port == 0x50)
    {
        P5 ^= ecbm_pin;
    }
#endif
#if ECBM_GPIO6_EN
    if (ecbm_port == 0x60)
    {
        P6 ^= ecbm_pin;
    }
#endif
#if ECBM_GPIO7_EN
    if (ecbm_port == 0x70)
    {
        P7 ^= ecbm_pin;
    }
#endif
}
#endif
/*程序区折叠专用**************************************************************/ #endif
    /*程序区折叠专用**********************快速IO操作模块****************************/ #if 1
/*-------------------------------------------------------
IO口电平快速翻转函数。
-------------------------------------------------------*/
#if ECBM_GPIO_TOGGLE_FAST_EN
    void
    gpio_toggle_fast(u8 port, u8 pin)
{
#if ECBM_GPIO0_EN
    if (port == GPIO_P0)
    {
        P0 ^= pin;
    }
#endif
#if ECBM_GPIO1_EN
    if (port == GPIO_P1)
    {
        P1 ^= pin;
    }
#endif
#if ECBM_GPIO2_EN
    if (port == GPIO_P2)
    {
        P2 ^= pin;
    }
#endif
#if ECBM_GPIO3_EN
    if (port == GPIO_P3)
    {
        P3 ^= pin;
    }
#endif
#if ECBM_GPIO4_EN
    if (port == GPIO_P4)
    {
        P4 ^= pin;
    }
#endif
#if ECBM_GPIO5_EN
    if (port == GPIO_P5)
    {
        P5 ^= pin;
    }
#endif
#if ECBM_GPIO6_EN
    if (port == GPIO_P6)
    {
        P6 ^= pin;
    }
#endif
#if ECBM_GPIO7_EN
    if (port == GPIO_P7)
    {
        P7 ^= pin;
    }
#endif
}
#endif
/*-------------------------------------------------------
IO口电平快速输出函数。
-------------------------------------------------------*/
#if ECBM_GPIO_OUT_FAST_EN
void gpio_out_fast(u8 port, u8 pin, u8 val)
{
#if ECBM_GPIO0_EN
    if (port == GPIO_P0)
    {
        if (val) { P0 |= pin; }
        else { P0 &= ~pin; }
    }
#endif
#if ECBM_GPIO1_EN
    if (port == GPIO_P1)
    {
        if (val) { P1 |= pin; }
        else { P1 &= ~pin; }
    }
#endif
#if ECBM_GPIO2_EN
    if (port == GPIO_P2)
    {
        if (val) { P2 |= pin; }
        else { P2 &= ~pin; }
    }
#endif
#if ECBM_GPIO3_EN
    if (port == GPIO_P3)
    {
        if (val) { P3 |= pin; }
        else { P3 &= ~pin; }
    }
#endif
#if ECBM_GPIO4_EN
    if (port == GPIO_P4)
    {
        if (val) { P4 |= pin; }
        else { P4 &= ~pin; }
    }
#endif
#if ECBM_GPIO5_EN
    if (port == GPIO_P5)
    {
        if (val) { P5 |= pin; }
        else { P5 &= ~pin; }
    }
#endif
#if ECBM_GPIO6_EN
    if (port == GPIO_P6)
    {
        if (val) { P6 |= pin; }
        else { P6 &= ~pin; }
    }
#endif
#if ECBM_GPIO7_EN
    if (port == GPIO_P7)
    {
        if (val) { P7 |= pin; }
        else { P7 &= ~pin; }
    }
#endif
}
#endif
/*-------------------------------------------------------
IO口电平快速输入函数。
-------------------------------------------------------*/
#if ECBM_GPIO_IN_FAST_EN
u8 gpio_in_fast(u8 port, u8 pin)
{
    u8 val = 0xff;
#if ECBM_GPIO0_EN
    if (port == GPIO_P0)
    {
        val = P0;
    }
#endif
#if ECBM_GPIO1_EN
    if (port == GPIO_P1)
    {
        val = P1;
    }
#endif
#if ECBM_GPIO2_EN
    if (port == GPIO_P2)
    {
        val = P2;
    }
#endif
#if ECBM_GPIO3_EN
    if (port == GPIO_P3)
    {
        val = P3;
    }
#endif
#if ECBM_GPIO4_EN
    if (port == GPIO_P4)
    {
        val = P4;
    }
#endif
#if ECBM_GPIO5_EN
    if (port == GPIO_P5)
    {
        val = P5;
    }
#endif
#if ECBM_GPIO6_EN
    if (port == GPIO_P6)
    {
        val = P6;
    }
#endif
#if ECBM_GPIO7_EN
    if (port == GPIO_P7)
    {
        val = P7;
    }
#endif
    if (val & pin)
        return 1;
    else
        return 0;
}
#endif
/*程序区折叠专用**************************************************************/
#endif //和最上面的#ifndef配合成一个程序段。
       //以一个空行为结尾。