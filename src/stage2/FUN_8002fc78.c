/* FUN_8002fc78
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fc78  body 0x8002fc78..0x8002fc93  size 28 B
 * body sha256 878df31a9e13a4a1a6525e075d26ffdfcadc5bcd1d44c9ee694f338b70cb0334
 * recovered byte-exact (WRAPFWD_SOURCE: 7 of 7, all 2 copies of the identical body)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as WRAPFWD_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

extern void FUN_callee(u32 a);

void FUN_wrapfwd(u32 a0, u32 a1)
{
    FUN_callee(a1);
}
