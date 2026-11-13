/* FUN_801648a8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801648a8  body 0x801648a8..0x801648ef  size 72 B
 * body sha256 df0fc789663042e0cb1e6ba4259947359f3ef07fe5a8f0cc3be58f88ffb2cf15
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801648a8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned char byte;












void FUN_801648a8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8016313c();
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    *(undefined1 *)(param_1 + 0x2c8) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  return;
}
