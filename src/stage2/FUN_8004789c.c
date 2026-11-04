/* FUN_8004789c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004789c  body 0x8004789c..0x800478ab  size 16 B
 * body sha256 4b7e64fcfdb5006f9d3e0f911a9d05e7ca152822099b8676ac7a5de9c85a0c71
 * recovered byte-exact (single: 4 of 4, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8004789C_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p, u8 a, u8 b, u8 c)
{
    p[4] = a;
    p[5] = b;
    p[6] = c;
}
