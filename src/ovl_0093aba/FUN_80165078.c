/* FUN_80165078
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80165078  body 0x80165078..0x801650ab  size 52 B
 * body sha256 26b185c70a1b966970740581125f17b8e3e90e432b599f22a7f99356a69ce08d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0093aba/80165078.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80165548;












void FUN_80165078(int param_1)

{
  (*(code *)(&PTR_FUN_80165548)[*(byte *)(param_1 + 5)])();
  return;
}
