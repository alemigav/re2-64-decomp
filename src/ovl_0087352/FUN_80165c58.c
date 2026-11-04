/* FUN_80165c58
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165c58  body 0x80165c58..0x80165c67  size 16 B
 * body sha256 a7694a8fa0c247938625c95d137b026e2b3f0f853c86fd75269c8e917467c0ac
 * recovered byte-exact (single: 4 of 4, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80165C58_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
void FUN_x(u8 *p, u8 a, u8 b)
{
    p[4] = a;
    p[5] = b;
    *(u16 *)(p + 6) = 0;
}
