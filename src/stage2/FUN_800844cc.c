/* FUN_800844cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800844cc  body 0x800844cc..0x800844e3  size 24 B
 * body sha256 24595494da23a0f20c360344e3510731b74dfb3df72a1950b49dedb2c029ae94
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800844CC_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
u32 FUN_x(u32 a)
{
    return ((a & 0xff) << 8) | ((a << 16) >> 24);
}
