/* FUN_8008b028
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b028  body 0x8008b028..0x8008b03f  size 24 B
 * body sha256 ccda9fe323cb50edc73664354a345889cc8cc470fc864d73e5f0a8027c8b6f08
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8008B028_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
extern u32 D_8012BD84;
extern u32 D_8010B6F4;
u32 FUN_x(void)
{
    return D_8012BD84 - D_8010B6F4;
}
