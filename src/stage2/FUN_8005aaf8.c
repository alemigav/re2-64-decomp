/* FUN_8005aaf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005aaf8  body 0x8005aaf8..0x8005ab0f  size 24 B
 * body sha256 a8d3d565d95431b9b2819490d11828d46c2665a82575724f7d80ac3567ce76cd
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8005AAF8_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
extern u8 D_80111163;
u32 FUN_x(u8 *p)
{
    u32 v = p[419] - D_80111163;

    p[419] = v;
    return v;
}
