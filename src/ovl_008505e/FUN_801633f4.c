/* FUN_801633f4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801633f4  body 0x801633f4..0x80163427  size 52 B
 * body sha256 060844058c118b0f13ba08f849822004fe10bfb26789c3843321eb86799a15db
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801633f4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166dc8;












void FUN_801633f4(int param_1)

{
  (*(code *)(&PTR_FUN_80166dc8)[*(byte *)(param_1 + 6)])();
  return;
}
