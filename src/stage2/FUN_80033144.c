/* FUN_80033144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033144  body 0x80033144..0x8003315f  size 28 B
 * body sha256 40833e3aa1cca8d8d17a81503edbccfdb4f4b7d3d05eee25c3c3b700f2dac8f6
 * recovered byte-exact (single: 7 of 7, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80033144_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
u32 FUN_x(u8 *a, u8 *b)
{
    s32 d = *(s16 *)(b + 102) - *(s16 *)(a + 102);

    d = (d + 0x400) & 0xfff;
    return d < 0x800;
}
