/* FUN_801661b8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801661b8  body 0x801661b8..0x80166247  size 144 B
 * body sha256 a5b381e8f4cb13bc04b292fcda34d778340a7abb83f888487b8a652e47dfb14f
 * recovered byte-exact (read from the words (M450): the sibling of ovl_0090698:0x80165e40, same defect — the image loads `addiu a3,zero,512` before the call and the draft passes no arguments.)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/801661b8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












void FUN_801661b8(uint *param_1, uint param_2, uint param_3)

{
  uint uVar1;
  
  param_1[0x7a] = 0xd000700;
  func_0x80089d54(param_1,param_2,param_3,0x200);
  uVar1 = func_0x80033604();
  FUN_80167688(param_1,0x2002,(uVar1 & 3) + 6);
  FUN_8016703c(param_1,0x13,1);
  FUN_80166248(param_1);
  param_1[1] = 0x7000000;
  *param_1 = *param_1 | 0x42;
  if (*(char *)((int)param_1 + 0x2d6) < '\0') {
    param_1[0xb] = (int)*(short *)(param_1 + 0x6a) + 0x46;
  }
  return;
}
