/*DS1302驱动（头文件）*/
#ifndef __DS1302_H
#define __DS1302_H

#include "ecbm_core.h" //加载库函数的头文件。
#define DS1302_W_SECOND     0x80
#define DS1302_W_MINUTE     0x82
#define DS1302_W_HOUR       0x84
#define DS1302_W_DAY        0x86
#define DS1302_W_MONTH      0x88
#define DS1302_W_WEEK       0x8A
#define DS1302_W_YEAR       0x8C
#define DS1302_W_PROTECT    0x8E

#define DS1302_R_SECOND     0x81
#define DS1302_R_MINUTE     0x83
#define DS1302_R_HOUR       0x85
#define DS1302_R_DAY        0x87
#define DS1302_R_MONTH      0x89
#define DS1302_R_WEEK       0x8B
#define DS1302_R_YEAR       0x8D
#define DS1302_R_PROTECT    0x8F

#define DS1302_W_TK_CHARGER 0x90
#define DS1302_W_CLK_BURST  0xBE
#define DS1302_W_RAM_BURST  0xFE

#define DS1302_R_TK_CHARGER 0x91
#define DS1302_R_CLK_BURST  0xBF
#define DS1302_R_RAM_BURST  0xFF

#define DS1302_RAM_SIZE     0x31 // Ram Size in bytes
#define DS1302_RAM_START    0xC0 // First byte Address

#define HEX2BCD(v)          ((v) % 10 + (v) / 10 * 16)
#define BCD2HEX(v)          ((v) % 16 + (v) / 16 * 10)

sbit DS1302_SCK = P1 ^ 5;
sbit DS1302_IO  = P1 ^ 6;
sbit DS1302_RST = P1 ^ 7;

static const u8 READ_RTC_ADDR[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d};
static const u8 WRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};
static u8 BUF[8]                   = {0};

void DS1302_WriteByte(u8 writeByte);
u8 DS1302_ReadByte(void);
void DS1302_WriteReg(u8 addr, u8 value);
u8 DS1302_ReadReg(u8 addr);
void DS1302_ReadBurst(u8 cmd, u8 len, u8 *buf);
void DS1302_Init(void);

#endif