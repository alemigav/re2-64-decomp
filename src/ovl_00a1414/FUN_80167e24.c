/* FUN_80167e24
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80167e24  body 0x80167e24..0x80167e57  size 52 B
 * body sha256 23c56b4564e95c8431bc2312dfa7b9834ee9cfac3d6fb58677c4d04f411cb819
 * recovered byte-exact (dispatch family (table 0x80169060): 13 of 13 words, one shape for all 2 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as DISPATCH80169060_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*fn)(u32);

extern fn D_80169060[];

void FUN_dispatch(u32 a0)
{
    fn *t = &D_80169060[*(u8 *)(a0 + 5)];

    (*t)(a0);
}
