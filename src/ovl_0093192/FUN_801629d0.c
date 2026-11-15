/* FUN_801629d0
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x801629d0  body 0x801629d0..0x80162a53  size 132 B
 * body sha256 46258a2aece9b3ed82a46332e553607b0dea4e0a678e507b7dc99aec536ca85e
 * recovered byte-exact (imported+adapted (M446): the draft's `func_0x80089d54()` omits its 4th argument; the image loads `addiu a3,zero,1024` immediately before the call, found by ALIGNING the two word lists (32 of 33 words present in order, positional identity 3 of 33 because one insertion shifts the rest). One statement added; the body is otherwise the decompiler's.)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0093192/801629d0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












void FUN_801629d0(uint *param_1, uint param_2, uint param_3)

{
  *param_1 = *param_1 | 2;
  param_1[0xb] = param_1[0xb] + 0x1e;
  *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x20;
  *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 0x40;
  func_0x80089d54(param_1,param_2,param_3,0x400);
  if (((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) ||
     ((int)param_1[0xb] < (int)*(short *)(param_1 + 0x6a))) {
    func_0x8003247c(param_1);
  }
  return;
}
