/* FUN_80163cdc
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163cdc  body 0x80163cdc..0x80163d0f  size 52 B
 * body sha256 c171d62492ed643db31c22b921706aa8cb970b79955842334659dcc0c8c24f03
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/80163cdc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166718;












void FUN_80163cdc(int param_1)

{
  (*(code *)(&PTR_FUN_80166718)[*(byte *)(param_1 + 6)])();
  return;
}
