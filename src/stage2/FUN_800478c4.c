/* FUN_800478c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478c4  body 0x800478c4..0x800478db  size 24 B
 * body sha256 def2d9af370242a4cb550ce40b91c7b89d8038160b84177d42da97e62583e916
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800478C4_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u16 *p, u16 a, u16 b, u16 c, u16 d)
{
    p[2] = a;
    p[3] = b;
    p[4] = c;
    p[5] = d;
}
