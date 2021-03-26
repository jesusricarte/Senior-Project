/*

 BG_TILE.C

 Tile Source File.

 Info:
  Form                 : All tiles as one unit.
  Format               : Gameboy 4 color.
  Compression          : None.
  Counter              : None.
  Tile size            : 8 x 8
  Tiles                : 0 to 0

  Palette colors       : None.
  SGB Palette          : None.
  CGB Palette          : None.

  Convert to metatiles : No.

 This file was generated by GBTD v2.2

*/

/* Start of tile array. */
/* const unsigned char BGTile[] =
{
  0xFF,0xFF,0xFB,0xFB,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0x7F,0x7F,0xF7,0xF7,0xFF,0xFF
}; */
const unsigned char BGTile[] =
{
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

unsigned char text[] =
{
  0x7C,0x7C,0x86,0x86,0x8A,0x8A,0x92,0x92,
  0xA2,0xA2,0xC2,0xC2,0x7C,0x7C,0x00,0x00,
  0x10,0x10,0xA5,0xA5,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x7C,0x7C,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x02,0x02,0x1C,0x1C,
  0x60,0x60,0x80,0x80,0xFE,0xFE,0x00,0x00,
  0xFE,0xFE,0x04,0x04,0x18,0x18,0x04,0x04,
  0x02,0x02,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0x0C,0x0C,0x14,0x14,0x24,0x24,0x44,0x44,
  0x84,0x84,0xFE,0xFE,0x04,0x04,0x00,0x00,
  0xFC,0xFC,0x80,0x80,0xFC,0xFC,0x02,0x02,
  0x02,0x02,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0x7C,0x7C,0x80,0x80,0x80,0x80,0xFC,0xFC,
  0x82,0x82,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0xFE,0xFE,0x82,0x82,0x04,0x04,0x08,0x08,
  0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x82,0x82,0x7C,0x7C,
  0x82,0x82,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x82,0x82,0x7E,0x7E,
  0x02,0x02,0x02,0x02,0x7C,0x7C,0x00,0x00,
  0x00,0x00,0xA5,0xA5,0xA5,0xA5,0x00,0x00,
  0xA5,0xA5,0xA5,0xA5,0x00,0x00,0x00,0x00,
  0x08,0x08,0x2E,0x2E,0xF8,0xF8,0x28,0x28,
  0x3E,0x3E,0xE8,0xE8,0x20,0x20,0x00,0x00,
  0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,
  0x20,0x20,0x10,0x10,0x08,0x08,0x00,0x00,
  0x00,0x00,0x00,0x00,0x7C,0x7C,0x00,0x00,
  0x7C,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,
  0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,
  0x08,0x08,0x10,0x10,0x20,0x20,0x00,0x00,
  0x3C,0x3C,0x42,0x42,0x02,0x02,0x0C,0x0C,
  0x10,0x10,0x00,0x00,0x10,0x10,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x9A,0x9A,0xAA,0xAA,
  0xBC,0xBC,0x80,0x80,0x7C,0x7C,0x00,0x00,
  0x38,0x38,0x44,0x44,0x82,0x82,0x82,0x82,
  0xFE,0xFE,0x82,0x82,0x82,0x82,0x00,0x00,
  0xFC,0xFC,0x82,0x82,0x82,0x82,0xFC,0xFC,
  0x82,0x82,0x82,0x82,0xFC,0xFC,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x80,0x80,0x80,0x80,
  0x80,0x80,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0xF8,0xF8,0x84,0x84,0x82,0x82,0x82,0x82,
  0x82,0x82,0x84,0x84,0xF8,0xF8,0x00,0x00,
  0xFE,0xFE,0x80,0x80,0x80,0x80,0xFC,0xFC,
  0x80,0x80,0x80,0x80,0xFE,0xFE,0x00,0x00,
  0xFE,0xFE,0x80,0x80,0x80,0x80,0xFC,0xFC,
  0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x80,0x80,0x80,0x80,
  0x8E,0x8E,0x82,0x82,0x7E,0x7E,0x00,0x00,
  0x82,0x82,0x82,0x82,0x82,0x82,0xFE,0xFE,
  0x82,0x82,0x82,0x82,0x82,0x82,0x00,0x00,
  0x7C,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x7C,0x7C,0x00,0x00,
  0x1E,0x1E,0x04,0x04,0x04,0x04,0x04,0x04,
  0x04,0x04,0x84,0x84,0x78,0x78,0x00,0x00,
  0x84,0x84,0x88,0x88,0x90,0x90,0xF0,0xF0,
  0x88,0x88,0x84,0x84,0x82,0x82,0x00,0x00,
  0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
  0x40,0x40,0x40,0x40,0x7E,0x7E,0x00,0x00,
  0x82,0x82,0xC6,0xC6,0xAA,0xAA,0x92,0x92,
  0x82,0x82,0x82,0x82,0x82,0x82,0x00,0x00,
  0x82,0x82,0xC2,0xC2,0xA2,0xA2,0x92,0x92,
  0x8A,0x8A,0x86,0x86,0x82,0x82,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x82,0x82,0x82,0x82,
  0x82,0x82,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0xFC,0xFC,0x82,0x82,0x82,0x82,0x82,0x82,
  0xFC,0xFC,0x80,0x80,0x80,0x80,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x82,0x82,0x92,0x92,
  0x8A,0x8A,0x84,0x84,0x7A,0x7A,0x00,0x00,
  0xFC,0xFC,0x82,0x82,0x82,0x82,0x84,0x84,
  0xF8,0xF8,0x84,0x84,0x82,0x82,0x00,0x00,
  0x7C,0x7C,0x80,0x80,0x80,0x80,0x7C,0x7C,
  0x02,0x02,0x02,0x02,0xFC,0xFC,0x00,0x00,
  0xFE,0xFE,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,
  0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,
  0x82,0x82,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,
  0x44,0x44,0x28,0x28,0x10,0x10,0x00,0x00,
  0x82,0x82,0x82,0x82,0x82,0x82,0x92,0x92,
  0xAA,0xAA,0xC6,0xC6,0x82,0x82,0x00,0x00,
  0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x10,
  0x28,0x28,0x44,0x44,0x82,0x82,0x00,0x00,
  0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,
  0xFE,0xFE,0x04,0x04,0x08,0x08,0x10,0x10,
  0x20,0x20,0x40,0x40,0xFE,0xFE,0x00,0x00,
  0x1C,0x1C,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x1C,0x1C,0x00,0x00,
  0x80,0x80,0x40,0x40,0x20,0x20,0x10,0x10,
  0x08,0x08,0x04,0x04,0x02,0x02,0x00,0x00,
  0x70,0x70,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x70,0x70,0x00,0x00,
  0x10,0x10,0x28,0x28,0x44,0x44,0x82,0x82,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0xFE,0xFE,0x00,0x00
};

unsigned char scoremap[] =
{
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

unsigned char windowmap[] = 
{
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30, //level:00
  0x30,0x30,0x23,0x13,0x1F,0x22,0x15,0x0A,0xFF,0xFF, //score
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};
/* End of BG_TILE.C */
