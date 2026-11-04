/* FUN_8016224c
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x8016224c  body 0x8016224c..0x8016227f  size 52 B
 * body sha256 497167aacb8d3013ad9e621631a0773cafba1788e9ed35bd1886907a6e6b938a
 * recovered byte-exact (dispatch family (table 0x80162b14): 13 of 13 words, one shape for all 2 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as DISPATCH80162B14_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*fn)(u32);

extern fn D_80162B14[];

void FUN_dispatch(u32 a0)
{
    fn *t = &D_80162B14[*(u8 *)(a0 + 5)];

    (*t)(a0);
}
