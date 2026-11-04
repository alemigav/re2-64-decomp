/* FUN_80169bcc
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80169bcc  body 0x80169bcc..0x80169bff  size 52 B
 * body sha256 f1800e36b1c59962309bb93fdabeee15cc4a954bac496b23ab7069dc971fde94
 * recovered byte-exact (dispatch family (table 0x8016c504): 13 of 13 words, one shape for all 2 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as DISPATCH8016C504_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*fn)(u32);

extern fn D_8016C504[];

void FUN_dispatch(u32 a0)
{
    fn *t = &D_8016C504[*(u8 *)(a0 + 5)];

    (*t)(a0);
}
