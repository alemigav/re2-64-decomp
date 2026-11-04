/* FUN_8016780c
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x8016780c  body 0x8016780c..0x8016783f  size 52 B
 * body sha256 6d1a379205dc66bbdb39e483b7d919a410fa0b7add8147065bc82ab3ac1e832a
 * recovered byte-exact (dispatch family (table 0x801682d0): 13 of 13 words, one shape for all 2 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as DISPATCH801682D0_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*fn)(u32);

extern fn D_801682D0[];

void FUN_dispatch(u32 a0)
{
    fn *t = &D_801682D0[*(u8 *)(a0 + 5)];

    (*t)(a0);
}
