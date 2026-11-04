/* FUN_80165308
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165308  body 0x80165308..0x8016533b  size 52 B
 * body sha256 2d25ff2e4e80fc2823e61344b7c3f6ca8c2f49758ed02c9b1074f96053f48f26
 * recovered byte-exact (dispatch family (table 0x8016702c): 13 of 13 words, one shape for all 2 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as DISPATCH8016702C_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*fn)(u32);

extern fn D_8016702C[];

void FUN_dispatch(u32 a0)
{
    fn *t = &D_8016702C[*(u8 *)(a0 + 5)];

    (*t)(a0);
}
