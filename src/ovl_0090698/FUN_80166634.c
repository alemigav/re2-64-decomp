/* FUN_80166634
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166634  body 0x80166634..0x801666bf  size 140 B
 * body sha256 77e54f2a8b83e9f7de54dac88b5813a11cd38dbc750d28cf80ba0338415e2d17
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80166634.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_80166634(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 0x2c0) == '\0') {
    FUN_801679c8(param_1,0x3f3f3f);
    *(undefined1 *)(param_1 + 0x2d7) = 0x1e;
    FUN_8016703c(param_1,0x13,10);
    FUN_8016703c(param_1,0,10);
  }
  *(undefined1 *)(param_1 + 5) = 2;
  FUN_8016577c(param_1,param_2,param_3);
  return;
}
