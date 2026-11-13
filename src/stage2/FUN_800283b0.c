/* FUN_800283b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800283b0  body 0x800283b0..0x800283ef  size 64 B
 * body sha256 feeff2aedb68d9e61b8ec1de1f3d437f46cffd130371032d4ff33f2984b55f2e
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800283b0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef void code();












void FUN_800283b0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    (**(code **)(*(int *)(param_1 + 4) + 0x28))();
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}
