/* FUN_80165bc4
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80165bc4  body 0x80165bc4..0x80165bf7  size 52 B
 * body sha256 2342ecf0e47164efa8fb1b98419c6de7fc6aa2d2c8860677c7e495f99bd6b7b1
 * recovered byte-exact (dispatch family (table 0x801672b4): 13 of 13 words, one shape for all 2 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as DISPATCH801672B4_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*fn)(u32);

extern fn D_801672B4[];

void FUN_dispatch(u32 a0)
{
    fn *t = &D_801672B4[*(u8 *)(a0 + 5)];

    (*t)(a0);
}
