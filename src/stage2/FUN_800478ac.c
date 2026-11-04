/* FUN_800478ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478ac  body 0x800478ac..0x800478b7  size 12 B
 * body sha256 2459fcac10f01a773f946a811bbb89f5d95d3c3c8821ed2ffc276ee74f11601d
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800478AC_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void FUN_x(u8 *p, u8 a, u8 b)
{
    p[8] = a;
    p[9] = b;
}
