/* FUN_80162d14
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162d14  body 0x80162d14..0x80162d47  size 52 B
 * body sha256 167a08950930b521a6641923dcd2a43a9581ec975b9a6dcb8750228fc7156be2
 * recovered byte-exact (dispatch family (table 0x80163120): 13 of 13 words, one shape for all 3 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as DISPATCH80163120_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*fn)(u32);

extern fn D_80163120[];

void FUN_dispatch(u32 a0)
{
    fn *t = &D_80163120[*(u8 *)(a0 + 5)];

    (*t)(a0);
}
