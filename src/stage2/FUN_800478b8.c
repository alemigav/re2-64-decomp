/* FUN_800478b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478b8  body 0x800478b8..0x800478c3  size 12 B
 * body sha256 85b99e18d163ff3e5f69697c7d8f07244928259512a8217730b8de917beb23c5
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800478B8_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void FUN_x(u16 *p, u16 a, u16 b)
{
    p[2] = a;
    p[3] = b;
}
