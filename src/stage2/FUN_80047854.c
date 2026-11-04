/* FUN_80047854
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047854  body 0x80047854..0x8004786b  size 24 B
 * body sha256 01c1f04255bec7b2095bc5494a1d41abea9ff65bbe50debdf3dd2e74cc850184
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80047854_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p, u8 a, u8 b, u16 c, u16 d)
{
    p[8] = a;
    p[9] = b;
    *(u16 *)(p + 16) = c;
    *(u16 *)(p + 18) = d;
}
