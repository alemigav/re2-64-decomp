/* FUN_801634ec
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x801634ec  body 0x801634ec..0x80163507  size 28 B
 * body sha256 75e0f97e57da496c409d7e15c7c26508ce048b562a441bf3964ed6e263e47be9
 * recovered byte-exact (WRAPVOID_SOURCE: 7 of 7, all 3 copies of the identical body)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as WRAPVOID_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
extern void FUN_callee(void);

void FUN_wrapvoid(void)
{
    FUN_callee();
}
