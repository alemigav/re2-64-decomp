/* FUN_801648f0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801648f0  body 0x801648f0..0x80164937  size 72 B
 * body sha256 6c4e92890065d15e458ce7da536b07a21a24ff62083197117373cd0200def3c7
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801648f0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166df0;












void FUN_801648f0(int param_1)

{
  (*(code *)(&PTR_FUN_80166df0)[*(byte *)(param_1 + 6)])();
  FUN_801664d8(param_1);
  return;
}
