/* FUN_80164b80
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164b80  body 0x80164b80..0x80164bbb  size 60 B
 * body sha256 b92aa7d1c6df7cb02d97f6e0f460576e5c5a4ad9b0ab8900e4915c8ee634bce8
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/80164b80.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80164b80(undefined4 param_1)

{
  uint uVar1;
  
  FUN_801625e0();
  uVar1 = func_0x80033604();
  FUN_801663a4(param_1,3,uVar1 & 7);
  return;
}
