/* FUN_8002fcc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fcc0  body 0x8002fcc0..0x8002fccf  size 16 B
 * body sha256 d589a66a5f12e3700cab9dfe68f536657aad828a8ab066ebb61d5bdfc728bb61
 * recovered byte-exact (single: 4 of 4, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002FCC0_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
u32 FUN_x(u8 *p, u32 b, u32 c, u32 d)
{
    return *(u32 *)(*(u32 *)(p + 4) + 44) - d;
}
