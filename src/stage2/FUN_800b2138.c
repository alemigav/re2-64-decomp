/* FUN_800b2138
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2138  body 0x800b2138..0x800b2143  size 12 B
 * body sha256 7535eb5c4fe9f6d558752aa2b49ecb742e1a7e6dbc159bac01a919d46b81a054
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800B2138_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 D_80147FA9;
void FUN_x(u8 a)
{
    D_80147FA9 = a;
}
