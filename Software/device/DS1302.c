#include "DS1302.h" //加载DS1302库的头文件。
// Write one byte to DS1302
void DS1302_WriteByte(u8 writeByte)
{
    u8 i;
    for (i = 0; i < 8; i++)
    {
        if (1 == (writeByte & 0x01))
        {
            DS1302_IO = 1;
        }
        else
        {
            DS1302_IO = 0;
        }
        DS1302_SCK = 1;
        DS1302_SCK = 0;
        writeByte >>= 1; // From low to high
    }
}

// Read one byte from DS1302
u8 DS1302_ReadByte(void)
{
    u8 dat, readByte, i = 0;
    for (i = 0; i < 8; i++)
    {
        // dat = DS1302_IO;
        // readByte = (readByte>>1) | (dat << 7); // From low to high
        readByte >>= 1;
        if (DS1302_IO)
        {
            readByte |= 0x80;
        }
        DS1302_SCK = 1;
        DS1302_SCK = 0;
    }
    return readByte;
}

void DS1302_WriteReg(u8 addr, u8 value)
{
    DS1302_RST = 0;
    DS1302_SCK = 0;
    DS1302_RST = 1;
    DS1302_WriteByte(addr);
    DS1302_WriteByte(value);
    DS1302_SCK = 1;
    DS1302_RST = 0;
}

u8 DS1302_ReadReg(u8 addr)
{
    u8 readByte = 0;
    DS1302_RST  = 0;
    DS1302_SCK  = 0;
    DS1302_RST  = 1;
    DS1302_WriteByte(addr);
    readByte   = DS1302_ReadByte();
    DS1302_SCK = 1;
    DS1302_RST = 0;
    return readByte;
}

void DS1302_ReadBurst(u8 cmd, u8 len, u8 *buf)
{
    u8 readByte = 0;
    DS1302_RST  = 0;
    DS1302_SCK  = 0;
    DS1302_RST  = 1;
    DS1302_WriteByte(cmd);
    while (len--)
        *buf++ = DS1302_ReadByte();
    DS1302_SCK = 1;
    DS1302_RST = 0;
}

void DS1302_Init(void)
{
    gpio_mode(D15, GPIO_PP);
    gpio_mode(D16, GPIO_IN);
    gpio_mode(D17, GPIO_PP);
    DS1302_WriteReg(DS1302_W_PROTECT, 0x00);    // write unprotect
    DS1302_WriteReg(DS1302_W_TK_CHARGER, 0x01); // stop charger
    DS1302_WriteReg(0XC0, 0x00);
    DS1302_WriteReg(0XC2, 0x01);
    DS1302_WriteReg(0XC4, 0x02);
    DS1302_WriteReg(0XC6, 0x03);
    DS1302_WriteReg(DS1302_W_PROTECT, 0x80); // write protect
}


