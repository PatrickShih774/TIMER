// ------------------  汉字字模的数据结构定义 ------------------------ //
typedef struct typFNT_GB16                 // 汉字字模数据结构
{
       signed char Index[2];               // 汉字内码索引
       char Msk[32];                       // 点阵码数据
};

/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 汉字库: 宋体16.dot 纵向取模下高位,数据排列:从左到右从上到下         //
/////////////////////////////////////////////////////////////////////////
struct typFNT_GB16 code GB_16[] =          // 数据表
{
"液", 0x10,0x22,0x64,0x0C,0x80,0x04,0xC4,0x34,
      0x05,0xC6,0xBC,0x24,0x24,0xE6,0x04,0x00,
      0x04,0x04,0xFE,0x01,0x02,0x01,0xFF,0x42,
      0x21,0x16,0x08,0x15,0x23,0x60,0x20,0x00,

"晶", 0x00,0x00,0x00,0x00,0xFF,0x49,0x49,0x49,
      0x49,0x49,0xFF,0x00,0x00,0x80,0x00,0x00,
      0x00,0xFF,0x49,0x49,0x49,0x49,0xFF,0x00,
      0xFF,0x49,0x49,0x49,0x49,0xFF,0x01,0x00,

"屏", 0x00,0x00,0xFE,0x12,0x92,0x92,0xB2,0xD2,
      0x92,0xD2,0xB2,0x92,0xDF,0x82,0x00,0x00,
      0x40,0x20,0x1F,0x04,0x84,0x44,0x3F,0x04,
      0x04,0x04,0xFF,0x04,0x04,0x06,0x04,0x00,

"测", 0x10,0x22,0x6C,0x00,0x80,0xFC,0x04,0xF4,
      0x04,0xFE,0x04,0xF8,0x00,0xFE,0x00,0x00,
      0x04,0x04,0xFE,0x01,0x40,0x27,0x10,0x0F,
      0x10,0x67,0x00,0x47,0x80,0x7F,0x00,0x00,

"试", 0x40,0x42,0xCC,0x00,0x10,0x90,0x90,0x90,
      0x90,0x90,0xFF,0x10,0x12,0x14,0x10,0x00,
      0x00,0x00,0x7F,0x20,0x10,0x20,0x60,0x3F,
      0x10,0x10,0x01,0x3E,0x40,0x80,0x70,0x00,

"社", 0x10,0x10,0x91,0xD6,0xB0,0x10,0x20,0x20,
      0x20,0xFF,0x20,0x20,0x30,0x20,0x00,0x00,
      0x02,0x01,0x00,0xFF,0x00,0x21,0x20,0x20,
      0x20,0x3F,0x20,0x20,0x20,0x30,0x20,0x00,

"会", 0x80,0x80,0x40,0x20,0x50,0x48,0x44,0x43,
      0x44,0x48,0x50,0x20,0x40,0xC0,0x40,0x00,
      0x00,0x00,0x02,0x42,0x62,0x52,0x4E,0x42,
      0x42,0x52,0x62,0xC3,0x02,0x00,0x00,0x00,

"易", 0x00,0x00,0x00,0x7F,0xC9,0x49,0x49,0x49,
      0x49,0x49,0x49,0x7F,0x00,0x80,0x00,0x00,
      0x08,0x04,0x22,0x11,0x09,0x87,0x41,0x21,
      0x19,0x07,0x41,0x81,0x41,0x3F,0x01,0x00,

"姐", 0x10,0x10,0xF0,0x1F,0x10,0xF8,0x10,0xFE,
      0x22,0x22,0x22,0x22,0xFF,0x02,0x00,0x00,
      0x40,0x22,0x15,0x08,0x14,0x63,0x40,0x7F,
      0x42,0x42,0x42,0x42,0x7F,0x40,0x40,0x00,

"控", 0x10,0x10,0x10,0xFF,0x90,0x50,0x0C,0x44,
      0x24,0x15,0x06,0x14,0x24,0x54,0x0C,0x00,
      0x02,0x42,0x81,0x7F,0x00,0x40,0x42,0x42,
      0x42,0x42,0x7E,0x42,0x43,0x62,0x40,0x00,

"制", 0x40,0x60,0x5E,0x48,0x48,0xFF,0x48,0x4C,
      0x68,0x40,0xF8,0x00,0x00,0xFF,0x00,0x00,
      0x00,0x00,0x3F,0x01,0x01,0xFF,0x11,0x21,
      0x1F,0x00,0x07,0x40,0x80,0x7F,0x00,0x00,

"器", 0x80,0x80,0x9F,0x91,0x91,0x91,0x9F,0xE0,
      0x9F,0x91,0xB1,0xD1,0x9F,0xC0,0x80,0x00,
      0x08,0x08,0xFC,0x8C,0x8A,0x8A,0xF9,0x00,
      0xF9,0x8A,0x8A,0x8C,0xFC,0x08,0x08,0x00,

"软", 0x08,0xC8,0xB8,0x8F,0xE8,0x8C,0x88,0x20,
      0x10,0x0F,0xC8,0x08,0x28,0x18,0x00,0x00,
      0x08,0x18,0x08,0x08,0xFF,0x04,0x84,0x40,
      0x30,0x0C,0x03,0x0C,0x30,0xC0,0x40,0x00,

"件", 0x40,0x20,0xF8,0x07,0x80,0x60,0x1C,0x10,
      0x10,0xFF,0x10,0x10,0x18,0x10,0x00,0x00,
      0x00,0x00,0xFF,0x02,0x02,0x02,0x02,0x02,
      0x02,0xFF,0x02,0x02,0x02,0x03,0x02,0x00,

"硬", 0x82,0x42,0xF2,0x4E,0x42,0xE3,0x42,0xF2,
      0x92,0x92,0xFE,0x92,0x92,0xFB,0x12,0x00,
      0x00,0x00,0x3F,0x10,0x10,0x3F,0x80,0x97,
      0x54,0x24,0x3F,0x44,0x44,0xC7,0x40,0x00,

"并", 0x00,0x00,0x08,0x09,0x0A,0xFE,0x08,0x08,
      0x08,0x0C,0xFA,0x0B,0x08,0x88,0x00,0x00,
      0x01,0x01,0x81,0x41,0x31,0x0F,0x01,0x01,
      0x01,0x01,0xFF,0x01,0x01,0x01,0x01,0x00,

"口", 0x00,0x00,0xFC,0x04,0x04,0x04,0x04,0x04,
      0x04,0x04,0x04,0x04,0xFE,0x04,0x00,0x00,
      0x00,0x00,0x3F,0x10,0x10,0x10,0x10,0x10,
      0x10,0x10,0x10,0x10,0x3F,0x00,0x00,0x00,

"接", 0x10,0x10,0x10,0xFF,0x90,0x54,0x44,0x54,
      0xE5,0x46,0x64,0x54,0x46,0x44,0x00,0x00,
      0x02,0x42,0x81,0x7F,0x02,0x02,0x82,0x8A,
      0x57,0x22,0x32,0x4E,0xC2,0x03,0x02,0x00,

"人", 0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x7F,
      0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,
      0x03,0x0C,0x10,0x20,0x40,0xC0,0x40,0x00,

"刷", 0x00,0x00,0xFE,0x92,0x92,0x92,0xF2,0x92,
      0x92,0xDF,0x82,0xF8,0x00,0xFF,0x00,0x00,
      0x20,0x1C,0x03,0x3F,0x00,0x00,0xFF,0x10,
      0x20,0x1F,0x00,0x4F,0x80,0x7F,0x00,0x00,

"很", 0x40,0x20,0x10,0x8C,0x63,0x00,0xFE,0x92,
      0x92,0x92,0x92,0x92,0xFF,0x02,0x00,0x00,
      0x04,0x02,0x01,0xFF,0x00,0x00,0xFF,0x40,
      0x23,0x04,0x08,0x14,0x62,0xC3,0x40,0x00,

"久", 0x00,0x00,0x40,0x20,0x18,0x07,0x04,0x04,
      0xE4,0x1E,0x04,0x00,0x00,0x00,0x00,0x00,
      0x40,0x40,0x20,0x20,0x10,0x08,0x04,0x03,
      0x00,0x03,0x0C,0x10,0x20,0x60,0x20,0x00,

"以", 0x00,0xFC,0x00,0x00,0x00,0x02,0x0C,0x18,
      0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,
      0x00,0x3F,0x20,0x10,0x08,0x84,0x82,0x41,
      0x40,0x20,0x18,0x17,0x20,0xC0,0x00,0x00,

"前", 0x08,0x08,0xE8,0x29,0x2A,0x2E,0xE8,0x08,
      0x08,0xCC,0x0A,0x0B,0xE8,0x0C,0x08,0x00,
      0x00,0x00,0xFF,0x09,0x49,0x89,0x7F,0x00,
      0x00,0x0F,0x40,0x80,0x7F,0x00,0x00,0x00,

"巨", 0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0x22,
      0x22,0x22,0x22,0xF3,0x22,0x00,0x00,0x00,
      0x00,0x00,0x7F,0x42,0x42,0x42,0x42,0x42,
      0x42,0x42,0x42,0x47,0x60,0x40,0x00,0x00,

"龙", 0x10,0x10,0x10,0x10,0x10,0x90,0x7F,0x10,
      0xF0,0x12,0x14,0x10,0xD0,0x18,0x10,0x00,
      0x00,0x80,0x40,0x30,0x0C,0x23,0x20,0x10,
      0x3F,0x44,0x42,0x41,0x40,0x40,0x78,0x00,

"突", 0x10,0x0C,0x04,0x24,0x14,0x0C,0x05,0xE6,
      0x04,0x4C,0x94,0x34,0x04,0x94,0x0C,0x00,
      0x81,0x81,0x41,0x41,0x21,0x11,0x0D,0x03,
      0x0D,0x11,0x21,0x21,0x41,0xC1,0x41,0x00,

"然", 0x80,0x40,0xB0,0x2F,0x48,0x88,0x78,0x20,
      0x20,0xA0,0x7F,0xA0,0x24,0x28,0x20,0x00,
      0x00,0x90,0x68,0x05,0x02,0x61,0x08,0x04,
      0x02,0x61,0x00,0x01,0x26,0x4C,0xC4,0x00,

"出", 0x00,0x00,0xFC,0x40,0x40,0x40,0x40,0xFF,
      0x40,0x40,0x40,0x40,0xFC,0x00,0x00,0x00,
      0x00,0xFE,0x40,0x40,0x40,0x40,0x40,0x7F,
      0x40,0x40,0x40,0x40,0x40,0xFE,0x00,0x00,

"现", 0x04,0x84,0x84,0xFC,0x86,0x84,0x00,0xFE,
      0x02,0x82,0x7A,0x02,0xFF,0x02,0x00,0x00,
      0x10,0x30,0x10,0x1F,0x88,0x88,0x40,0x23,
      0x18,0x07,0x78,0x80,0x83,0x80,0xE0,0x00,

"带", 0x80,0x64,0x24,0x24,0x3F,0x24,0x24,0xFF,
      0x24,0x24,0x3F,0x24,0x26,0xA4,0x60,0x00,
      0x00,0x00,0x00,0x7F,0x01,0x01,0x01,0xFF,
      0x01,0x21,0x41,0x3F,0x00,0x00,0x00,0x00,

"来", 0x00,0x08,0x28,0x48,0xC8,0x08,0x08,0xFF,
      0x08,0x88,0x48,0x68,0x0C,0x88,0x00,0x00,
      0x21,0x21,0x11,0x11,0x09,0x05,0x03,0xFF,
      0x03,0x05,0x09,0x19,0x11,0x31,0x11,0x00,

"灾", 0x10,0x0C,0x04,0xC4,0x04,0x04,0x05,0xF6,
      0x04,0x04,0x04,0xC4,0x84,0x14,0x0C,0x00,
      0x00,0x80,0x82,0x41,0x20,0x10,0x0C,0x03,
      0x0C,0x12,0x21,0x20,0x40,0xC0,0x40,0x00,

"难", 0x04,0x34,0xC4,0x04,0xC4,0x3E,0x44,0x20,
      0xF8,0x4F,0x49,0xFA,0x48,0x4C,0x08,0x00,
      0x20,0x10,0x0C,0x03,0x04,0x18,0x00,0x00,
      0xFF,0x22,0x22,0x3F,0x22,0x32,0x20,0x00,

"走", 0x40,0x40,0x48,0x48,0x48,0x48,0x48,0xFF,
      0x48,0x48,0x48,0x4C,0x48,0x60,0x40,0x00,
      0x00,0x80,0x40,0x20,0x1F,0x20,0x40,0x7F,
      0x44,0x44,0x44,0x46,0x44,0x60,0x20,0x00,

"了", 0x00,0x02,0x02,0x02,0x02,0x02,0x02,0xE2,
      0x22,0x12,0x0A,0x06,0x02,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

"公", 0x00,0x00,0x80,0x40,0x30,0x0C,0x00,0xC0,
      0x06,0x18,0x20,0x40,0x80,0x80,0x80,0x00,
      0x01,0x01,0x00,0x30,0x28,0x24,0x23,0x20,
      0x20,0x28,0x30,0x60,0x00,0x01,0x00,0x00,

"主", 0x00,0x08,0x08,0x08,0x08,0x08,0x09,0xFE,
      0x08,0x08,0x08,0x88,0x0C,0x08,0x00,0x00,
      0x40,0x40,0x41,0x41,0x41,0x41,0x41,0x7F,
      0x41,0x41,0x41,0x41,0x41,0x60,0x40,0x00,

"又", 0x00,0x02,0x02,0x1E,0x62,0x82,0x02,0x02,
      0x02,0xC2,0x32,0x0E,0x00,0x00,0x00,0x00,
      0x80,0x80,0x40,0x40,0x20,0x11,0x0A,0x04,
      0x0B,0x10,0x20,0x20,0x40,0xC0,0x40,0x00,

"消", 0x10,0x22,0x64,0x0C,0x80,0x00,0xF2,0x94,
      0x90,0x9F,0x90,0x94,0xFA,0x10,0x00,0x00,
      0x04,0x04,0xFE,0x01,0x00,0x00,0xFF,0x04,
      0x04,0x04,0x44,0x84,0x7F,0x00,0x00,0x00,

"失", 0x00,0x40,0x20,0x1E,0x10,0x10,0x10,0xFF,
      0x10,0x10,0x10,0x18,0x10,0x80,0x00,0x00,
      0x01,0x81,0x81,0x41,0x21,0x11,0x0D,0x03,
      0x0D,0x11,0x21,0x21,0x41,0xC1,0x41,0x00,

"不", 0x02,0x02,0x02,0x02,0x02,0x82,0x42,0xF2,
      0x0E,0x42,0x82,0x02,0x02,0x03,0x02,0x00,
      0x00,0x08,0x04,0x02,0x01,0x00,0x00,0xFF,
      0x00,0x00,0x00,0x01,0x03,0x06,0x00,0x00,

"见", 0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0xFA,
      0x02,0x02,0x02,0xFF,0x02,0x00,0x00,0x00,
      0x80,0x80,0x40,0x47,0x20,0x18,0x06,0x01,
      0x3C,0x40,0x40,0x47,0x40,0x40,0x70,0x00,

"王", 0x00,0x82,0x82,0x82,0x82,0x82,0x82,0xFE,
      0x82,0x82,0x82,0x82,0xC3,0x82,0x00,0x00,
      0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7F,
      0x40,0x40,0x40,0x40,0x40,0x60,0x40,0x00,

"国", 0x00,0xFE,0x02,0x0A,0x8A,0x8A,0x8A,0xFA,
      0x8A,0xCA,0x8E,0x0A,0x02,0xFF,0x02,0x00,
      0x00,0xFF,0x40,0x50,0x50,0x50,0x50,0x5F,
      0x50,0x52,0x54,0x50,0x40,0xFF,0x00,0x00,

"十", 0x40,0x40,0x40,0x40,0x40,0x40,0x40,0xFF,
      0x40,0x40,0x40,0x40,0x40,0x60,0x40,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

"分", 0x00,0x80,0x40,0x20,0x98,0x86,0x80,0x80,
      0x83,0x8C,0x90,0x20,0xC0,0x80,0x80,0x00,
      0x01,0x00,0x80,0x40,0x20,0x1F,0x00,0x40,
      0x80,0x40,0x3F,0x00,0x00,0x01,0x00,0x00,

"危", 0x00,0x10,0x08,0xF4,0x13,0x12,0x92,0x92,
      0x9A,0x96,0x92,0xD0,0x98,0x10,0x00,0x00,
      0x80,0x40,0x30,0x0F,0x00,0x00,0x3F,0x40,
      0x40,0x44,0x48,0x47,0x40,0x40,0x70,0x00,

"险", 0x00,0xFE,0x22,0x5A,0x86,0x20,0x90,0x28,
      0x24,0xA3,0x34,0x28,0x90,0x30,0x10,0x00,
      0x00,0xFF,0x04,0x08,0x47,0x40,0x41,0x5E,
      0x40,0x5F,0x60,0x58,0x47,0x60,0x40,0x00,

"世", 0x20,0x20,0x20,0xFE,0x20,0x20,0x20,0xFF,
      0x20,0x20,0x20,0xFF,0x20,0x30,0x20,0x00,
      0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x4F,
      0x44,0x44,0x44,0x4F,0x60,0x40,0x00,0x00,

"间", 0x00,0xF8,0x01,0x02,0xF6,0x10,0x12,0x12,
      0x12,0x12,0xFA,0x12,0x02,0xFF,0x02,0x00,
      0x00,0xFF,0x00,0x00,0x3F,0x11,0x11,0x11,
      0x11,0x11,0x3F,0x40,0x80,0x7F,0x00,0x00,

"谁", 0x40,0x40,0x42,0xCC,0x00,0x20,0x10,0xFC,
      0x4B,0x48,0x4A,0xFC,0x48,0x4C,0x08,0x00,
      0x00,0x00,0x00,0x7F,0x20,0x10,0x00,0xFF,
      0x22,0x22,0x22,0x3F,0x22,0x32,0x20,0x00,

"最", 0x40,0x40,0xC0,0x5F,0x55,0x55,0xD5,0x55,
      0x55,0x55,0x55,0x5F,0x40,0x60,0x40,0x00,
      0x20,0x20,0x3F,0x15,0x15,0x15,0xFF,0x81,
      0x47,0x29,0x11,0x29,0x65,0xC3,0x40,0x00,

"勇", 0x00,0x00,0xF9,0xA9,0xA9,0xA9,0xAB,0xFD,
      0xAD,0xAB,0xA9,0xA9,0xFC,0x08,0x00,0x00,
      0x00,0x84,0x87,0x44,0x44,0x24,0x1C,0x07,
      0x04,0x44,0x84,0x46,0x3D,0x00,0x00,0x00,

"敢", 0x10,0x12,0xF2,0x92,0x9A,0xF6,0x10,0x10,
      0xD8,0x17,0x10,0x10,0xF0,0x18,0x10,0x00,
      0x10,0x10,0x1F,0x12,0x12,0xFF,0x90,0x40,
      0x20,0x1B,0x04,0x1B,0x60,0xC0,0x40,0x00,

"汉", 0x10,0x22,0x64,0x0C,0x80,0x04,0x74,0x84,
      0x04,0x04,0x04,0xC4,0x3E,0x04,0x00,0x00,
      0x04,0x04,0x7E,0x01,0x80,0x40,0x20,0x11,
      0x0A,0x04,0x0B,0x10,0x60,0xC0,0x40,0x00,

"字", 0x00,0x10,0x0C,0x24,0x24,0x24,0x25,0x26,
      0xA4,0x64,0x24,0x04,0x14,0x0C,0x00,0x00,
      0x02,0x02,0x02,0x02,0x02,0x42,0x82,0x7F,
      0x02,0x02,0x02,0x02,0x02,0x03,0x02,0x00,

"垂", 0x00,0x20,0x24,0x24,0xE4,0x24,0x24,0xFC,
      0x24,0x22,0xE2,0x23,0x32,0xA0,0x00,0x00,
      0x01,0x09,0x49,0x49,0x4F,0x49,0x49,0x7F,
      0x49,0x49,0x4F,0x69,0x4D,0x09,0x01,0x00,

"直", 0x00,0x04,0x04,0xE4,0xA4,0xA4,0xA4,0xBF,
      0xA4,0xA4,0xA4,0xF4,0x26,0x04,0x00,0x00,
      0x40,0x40,0x40,0x7F,0x4A,0x4A,0x4A,0x4A,
      0x4A,0x4A,0x4A,0x7F,0x40,0x60,0x40,0x00,

"镜", 0x20,0x58,0xCF,0x48,0x48,0x24,0xA4,0xAC,
      0xB5,0xA6,0xB4,0xAC,0xE6,0xB4,0x20,0x00,
      0x02,0x02,0x7F,0x22,0x92,0x80,0x4F,0x3A,
      0x0A,0x0A,0x7A,0x8A,0x8F,0x80,0xE0,0x00,

"像", 0x80,0x40,0x20,0xF8,0x17,0x38,0x2C,0xAB,
      0x6A,0xBA,0x2E,0x2A,0x28,0xBC,0x08,0x00,
      0x00,0x00,0x00,0xFF,0x00,0x25,0x25,0x14,
      0x52,0x89,0x7F,0x06,0x09,0x10,0x10,0x00,

"水", 0x00,0x20,0x20,0x20,0x20,0xE0,0x00,0xFF,
      0xC0,0x40,0x20,0x10,0x18,0x00,0x00,0x00,
      0x20,0x10,0x08,0x04,0x03,0x40,0x80,0x7F,
      0x00,0x01,0x02,0x04,0x08,0x18,0x08,0x00,

"平", 0x00,0x02,0x02,0x1A,0x62,0x02,0x02,0xFE,
      0x02,0x02,0x62,0x1A,0x03,0x82,0x00,0x00,
      0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,
      0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,

"反", 0x00,0x00,0xFC,0x24,0x24,0xE4,0x24,0x24,
      0x24,0x22,0x22,0xA3,0x62,0x00,0x00,0x00,
      0x40,0x30,0x0F,0x80,0x80,0x40,0x23,0x14,
      0x08,0x14,0x22,0x21,0x40,0xC0,0x40,0x00,

"色", 0x00,0x80,0x40,0x20,0xF8,0x27,0x24,0x24,
      0xE4,0x34,0x2C,0x24,0xF0,0x20,0x00,0x00,
      0x00,0x00,0x00,0x00,0x3F,0x42,0x42,0x42,
      0x43,0x42,0x42,0x42,0x47,0x40,0x70,0x00,

"显", 0x00,0x00,0x00,0xFE,0x92,0x92,0x92,0x92,
      0x92,0x92,0x92,0xFF,0x02,0x00,0x00,0x00,
      0x40,0x42,0x44,0x4D,0x40,0x7F,0x40,0x40,
      0x40,0x7F,0x40,0x49,0x44,0x66,0x40,0x00,

"示", 0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xC2,
      0x42,0x42,0x42,0x43,0x42,0x60,0x40,0x00,
      0x00,0x10,0x08,0x04,0x06,0x40,0x80,0x7F,
      0x00,0x00,0x02,0x04,0x0C,0x18,0x00,0x00,

"幕", 0x00,0x02,0x02,0xFA,0xAA,0xAF,0xAA,0xAA,
      0xAA,0xAF,0xAA,0xFE,0x0B,0x02,0x00,0x00,
      0x12,0x12,0x0A,0x7E,0x0A,0x0B,0x0A,0xFE,
      0x0A,0x2A,0x4A,0x3E,0x0A,0x1B,0x0A,0x00,

"开", 0x80,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,
      0x82,0x82,0xFE,0x82,0x83,0xC2,0x80,0x00,
      0x00,0x80,0x40,0x30,0x0F,0x00,0x00,0x00,
      0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,

"关", 0x00,0x10,0x10,0x11,0x12,0x1C,0x10,0xF0,
      0x10,0x18,0x14,0x13,0x1A,0x90,0x00,0x00,
      0x81,0x81,0x41,0x41,0x21,0x11,0x0D,0x03,
      0x0D,0x11,0x21,0x21,0x41,0xC1,0x41,0x00,

"对", 0x08,0x48,0x88,0x08,0xC8,0x38,0x10,0x90,
      0x10,0x10,0x10,0xFF,0x10,0x18,0x10,0x00,
      0x20,0x10,0x0C,0x03,0x04,0x18,0x00,0x00,
      0x03,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,

"比", 0x00,0x00,0xFE,0x40,0x40,0x60,0x40,0x00,
      0xFF,0x80,0x40,0x20,0x30,0x00,0x00,0x00,
      0x00,0x40,0x7F,0x20,0x20,0x10,0x10,0x00,
      0x3F,0x40,0x40,0x40,0x40,0x40,0x78,0x00,

"度", 0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0xA5,
      0xA6,0xA4,0xFC,0x24,0x34,0x26,0x04,0x00,
      0x40,0x20,0x9F,0x80,0x42,0x42,0x26,0x2A,
      0x12,0x2A,0x26,0x42,0x40,0xC0,0x40,0x00,

"结", 0x00,0x30,0x28,0xA4,0x63,0x10,0x08,0x48,
      0x48,0x48,0x7F,0x48,0x48,0x4C,0x08,0x00,
      0x00,0x22,0x63,0x22,0x12,0x12,0x00,0xFE,
      0x42,0x42,0x42,0x42,0x42,0xFF,0x02,0x00,

"束", 0x04,0x04,0xE4,0x24,0x24,0x24,0x24,0xFF,
      0x24,0x24,0x24,0x24,0xF4,0x26,0x04,0x00,
      0x40,0x40,0x27,0x22,0x12,0x0A,0x06,0xFF,
      0x06,0x0A,0x12,0x12,0x27,0x60,0x20,0x00,

"图", 0x00,0xFE,0x02,0x22,0x12,0x1E,0xAA,0x4A,
      0xAA,0x1A,0x0A,0x02,0x02,0xFF,0x02,0x00,
      0x00,0xFF,0x44,0x44,0x42,0x49,0x49,0x52,
      0x64,0x41,0x42,0x46,0x42,0xFF,0x00,0x00,

"标", 0x10,0x10,0xD0,0xFF,0x90,0x50,0x44,0x44,
      0x44,0xC4,0x44,0x46,0x44,0x60,0x40,0x00,
      0x04,0x03,0x00,0xFF,0x00,0x11,0x08,0x46,
      0x80,0x7F,0x00,0x02,0x0C,0x18,0x00,0x00,

"时", 0x00,0xFC,0x84,0x84,0x84,0xFE,0x14,0x10,
      0x90,0x10,0x10,0x10,0xFF,0x10,0x10,0x00,
      0x00,0x3F,0x10,0x10,0x10,0x3F,0x00,0x00,
      0x00,0x23,0x40,0x80,0x7F,0x00,0x00,0x00,

"片", 0x00,0x00,0xFE,0x20,0x20,0x20,0x20,0x20,
      0x3F,0x20,0x20,0x20,0x20,0x30,0x20,0x00,
      0x80,0x40,0x3F,0x01,0x01,0x01,0x01,0x01,
      0x01,0xFF,0x00,0x00,0x00,0x00,0x00,0x00
};

// 汉字表：
// 液晶屏测试社会易姐控制器软件硬并口接人刷很久以前巨龙突然出现带来灾难走
// 了公主又消失不见王国十分危险世间谁最勇敢汉字垂直镜像水平反色显示幕开关
// 对比度结束图标时片