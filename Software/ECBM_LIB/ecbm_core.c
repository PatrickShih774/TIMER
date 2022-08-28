#include "ecbm_core.h"
/*------------------------------------资源冲突警告---------------------------------*/
#if (ECBM_UART_LIB_EN == 0) && (ECBM_AUTO_DOWNLOAD_EN == 1)
#error 自动下载功能因串口库未加载而开启失败，请前往ecbm_core.h使能串口库！
#endif
#if (ECBM_UART1_EN == 0) && (ECBM_AUTO_DOWNLOAD_EN == 1)
#error 自动下载功能因串口1未使能而开启失败，请前往uart.h使能串口1！
#endif
#if (ECBM_UART1_IO != 0) && (ECBM_AUTO_DOWNLOAD_EN == 1)
#error 自动下载功能需要串口1映射到P30和P31，请前往uart.h修改串口1的输出IO！
#endif
/*--------------------------------------变量定义-----------------------------------*/
u16 xdata ecbm_delay_base = ECBM_SYSCLK_SETTING / 10000;
/*-----------------------------------可选模块设定----------------------------------*/
union
{
    u32 num32;
    u16 num16[2];
    u8 num8[4];
} fast_cout;

/*-------------------------------------------------------
毫秒级延时函数
-------------------------------------------------------*/
void delay_ms(u16 ms)
{
    u16 i;
    if (ms)
    {
        do {
            i = ecbm_delay_base;
            while (--i)
                ;
        } while (--ms);
    }
}

/*-------------------------------------------------------
微秒级延时函数（节拍）
-------------------------------------------------------*/
void delay_us(u16 us)
{
    u16 i;
    i = us;
    while (i--)
        ;
}
/*-------------------------------------------------------
微秒级延时函数的节拍计算函数
-------------------------------------------------------*/
u16 delay_set_us(u16 us)
{
    //公式计算所花的时间太长，拆分成两个函数。先用这个函数推算出延时的数值，再用下面的函数调用。
    fast_cout.num32 = ((u32)ecbm_delay_base * (u32)(us)) * 131;
    return fast_cout.num16[0] >> 1;
}
/************************************串口调试模块***************/ #if ECBM_AUTO_DOWNLOAD_EN
    /*-------------------------------------------------------
    自动下载所需的变量
    -------------------------------------------------------*/
    __IO u8 data old_char; //保存上一次接收的数据
__IO u8 data char_count;   //相同数据计数
/*-------------------------------------------------------
下载流判断函数
-------------------------------------------------------*/
void system_uart_reset()
{
    if (old_char != UART1_GET_REG_SBUF)
    {                                    //判断重复字符，如果字符不重复
        old_char   = UART1_GET_REG_SBUF; //就更新oldchar
        char_count = 0;                  //计数器清零
    }
    else
    {                 //如果字符重复
        char_count++; //则重复计数器+1
    }
    if (char_count >= 233)
    { //接收到233个重复数据时
        _nop_();
        POWER_RESET; //重启
        _nop_();
        _nop_();
    }
}
/****************************************************************************/ #endif
    /*----------------------------------其他系统函数-----------------------------------*/
    /*-------------------------------------------------------
    库函数系统初始化函数
    -------------------------------------------------------*/
    void
    system_init(void)
{
    EX_SFR_ENABLE; //打开额外的寄存器。
//---------------自动下载--------------//
#if ECBM_AUTO_DOWNLOAD_EN //判断否需要开启自动下载。
    old_char   = 0;       //初始化串口相关变量
    char_count = 0;       //初始化串口相关变量
    uart_init();
#endif
//-------------基本硬件设置------------//
#if ECBM_POWER_LIB_EN
#if ECBM_POWER_RST_CFG_EN
    power_rstcfg_init();
#endif
#endif

//-------------时钟输出设置------------//
#if ECBM_SYSCLK_OUT_EN                 //判断是否需要开启时钟输出。
#if ((ECBM_MCU & 0xF00000) > 0x200000) //检查是不是GH。
#if ECBM_SYSLCK_OUT_PIN
    CLK_SET_OUT_TO_P16_GH;
#else
    CLK_SET_OUT_TO_P54_GH;
#endif
    CLK_OUT_SET_DIV_GH(ECBM_SYSCLK_OUT_SETTING_GH);
#else
#if ECBM_SYSLCK_OUT_PIN
    CLK_SET_OUT_TO_P16_FA;
#else
    CLK_SET_OUT_TO_P54_FA;
#endif
    CLK_OUT_SET_DIV_FA(ECBM_SYSCLK_OUT_SETTING_FA);
#endif
#endif
    //--------------设置确认---------------//
    EA_ENABLE; //打开总中断。
}
/**********************************str系列函数************************/ #if ECBM_STRING_EN
    /*-------------------------------------------------------
    字符串查找函数。
    -------------------------------------------------------*/
    u16
    str_find(char *dest, char *key)
{
    u16 key_count = 0, key_first = 0, count = 0;
    while (*dest)
    { //判断目标字符串，直到字符串结束。
        if (key[key_count] == (*dest))
        {                //假如关键词字符串当前位对比成功，
            key_count++; //那么就去比较下一位。
        }
        else if (key[0] == (*dest))
        {                  //假如当前位没有对比成功，就看看是不是要从头开始对比。
            key_count = 1; //从头对比成功，说明再次找到了疑似的关键词，那么下次就从第二个开始对比。
        }
        else
        {                  //假如当前位和开始位都没有对比成功，说明这个就不是关键词，
            key_count = 0; //那么就清零计数。
        }
        count++; //记录循环的次数，用于计算关键词出现的位置。
        dest++;  //读取目标字符串的下一位。
        if (key[key_count] == 0)
        {                               //如果关键词字符串比对完，
            return (count - key_count); //返回关键词字符串第一次出现的位置。
        }
    }
    return 0xffff; //能运行到这一步，说明直到目标字符串结束都没有比对成功，返回-1。
}
/*-------------------------------------------------------
IO信息读取函数。
-------------------------------------------------------*/
u8 str_read_pin(char *str, u16 pos)
{
    u8 dat = 0, offset, count; //从左往右依次是读取的信息、字符串偏移和字数统计。
    count  = 0;                //字数统计清零。
    for (offset = 0; offset < 10; offset++)
    { //预留10个偏移量。
        if ((str[pos + offset] >= '0') && (str[pos + offset] <= '7'))
        {            // IO口的编号都是从0~7。
            count++; //在这个范围内，字数+1。
            if (count == 1)
            {                                         //如果是第一个数，
                dat = (str[pos + offset] - '0') << 4; //解析出来放到高4位。
            }
            if (count == 2)
            {                                          //如果是第二个数，
                dat = (str[pos + offset] - '0') | dat; //解析出来放到低4位。
                return dat;                            //返回该值。
            }
        }
        if ((str[pos + offset] >= '8') && (str[pos + offset] <= '9'))
        { //如果是8和9，那么只增加字数，不写入值。
            count++;
        }
        if (str[pos + offset] == ',') break; //遇到逗号就退出。
        if (str[pos + offset] == 0) break;   //字符串结束也退出。
    }
    return dat;
}
/*-------------------------------------------------------
u16变量读取函数。
-------------------------------------------------------*/
u16 str_read_u16(char *str, u16 pos)
{
    u16 dat = 0; //读取的信息。
    u8 offset;   //字符串偏移。
    for (offset = 0; offset < 20; offset++)
    { //预留20个字符的偏移。
        if ((str[pos + offset] >= '0') && (str[pos + offset] <= '9'))
        {                                   //数字都是从0~9。
            dat *= 10;                      //变量增加一位，即原来是12，就变成120，空出的个数就拿来装新的数。
            dat += str[pos + offset] - '0'; //将新的数加到个位上。
        }
        if (str[pos + offset] == ',') break; //遇到逗号就退出。
        if (str[pos + offset] == '.') break; //遇到点号就退出。
        if (str[pos + offset] == 0) break;   //字符串结束也退出。
    }
    return dat;
}
/*-------------------------------------------------------
字符串推出指令函数（带字符串长度参数版）。
-------------------------------------------------------*/
u8 str_push_len(u8 *dest, u16 dlen, u8 *key, u16 klen)
{
    u16 i, j = 0, start = 0, stop = 0;
    for (i = 0; i < dlen; i++)
    { //从头开始，直到指定的长度。
        if (dest[i] == key[j])
        {        //把当前的字符和关键词比较成功，
            j++; //取关键词的下一个字。
            if (j == klen)
            {             //当关键词全部比对完成的时候。
                stop = i; //保存【结束位置】。
                break;    //退出循环。
            }
        }
        else
        {                  //如果当前的字符和关键词比较失败，
            j     = 0;     //下一次从头开始比对。
            start = i + 1; //更新【开始位置】为下一位（因为当前位失败了）。
        }
    }
    if (start <= stop)
    { //当比对成功的时候，【开始位置】肯定小于等于【结束位置】。
        for (i = start; i < stop; i++)
        { //将从【开始位置】到【结束位置】之间的缓存全清零。
            dest[i] = 0;
        }
        return 1; //返回推出成功。
    }
    else
    {
        return 0; //返回推出失败。
    }
}
/*****************************************************************************/ #endif