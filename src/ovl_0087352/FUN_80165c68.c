/* FUN_80165c68
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165c68  body 0x80165c68..0x80165c73  size 12 B
 * body sha256 1ff8f5e5704ae7916b6090d7d228236189617c2070c245c3bb8c502cf71a3f9c
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80165C68_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void FUN_x(u8 *p, u8 a)
{
    p[5] = a;
    *(u16 *)(p + 6) = 0;
}
