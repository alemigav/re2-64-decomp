/* FUN_801689a0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801689a0  body 0x801689a0..0x801689d3  size 52 B
 * body sha256 b17e32bf2a8094dfddea030fb149d4f0783d4ab3088f86f42510b510c61e53e1
 * recovered byte-exact (dispatch family (table 0x801698c8): 13 of 13 words, one shape for all 2 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as DISPATCH801698C8_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*fn)(u32);

extern fn D_801698C8[];

void FUN_dispatch(u32 a0)
{
    fn *t = &D_801698C8[*(u8 *)(a0 + 5)];

    (*t)(a0);
}
