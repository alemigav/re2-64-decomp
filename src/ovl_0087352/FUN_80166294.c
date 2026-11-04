/* FUN_80166294
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80166294  body 0x80166294..0x801662a7  size 20 B
 * body sha256 e59bf7c45ed1e4b280a9f3b5ca66f975df715f138bc67a38cb57b5b0299b9500
 * recovered byte-exact (single: 5 of 5, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80166294_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void FUN_x(u16 *p, u16 v)
{
    p[155] = v;
    p[156] = v;
    p[150] = v;
    p[151] = v;
}
