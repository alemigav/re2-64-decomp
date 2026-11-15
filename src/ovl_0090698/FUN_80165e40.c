/* FUN_80165e40
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165e40  body 0x80165e40..0x80165ec7  size 136 B
 * body sha256 cb83f8ceab689732d438c169d19b66e6d2182742c9eeebadcd0616260131d94a
 * recovered byte-exact (read from the words (M450): the image loads `addiu a3,zero,512` before the call, so the 4th argument is 0x200 and the draft called `func_0x80089d54()` with none. Same missing-argument pattern as ovl_0093192:0x801629d0 (M446); the three leading arguments are the function's own, passed straight through.)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80165e40.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












void FUN_80165e40(uint *param_1, uint param_2, uint param_3)

{
  uint uVar1;
  
  param_1[0x7a] = 0xd000700;
  func_0x80089d54(param_1,param_2,param_3,0x200);
  uVar1 = func_0x80033604();
  FUN_80167688(param_1,0x2002,(uVar1 & 3) + 1);
  FUN_8016703c(param_1,0,0);
  param_1[1] = 0x7000000;
  *param_1 = *param_1 | 0x42;
  if (*(char *)((int)param_1 + 0x2d6) < '\0') {
    param_1[0xb] = (int)*(short *)(param_1 + 0x6a) + 0x46;
  }
  return;
}
