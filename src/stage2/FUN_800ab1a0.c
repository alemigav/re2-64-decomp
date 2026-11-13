/* FUN_800ab1a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab1a0  body 0x800ab1a0..0x800ab24b  size 172 B
 * body sha256 5e57d13265db9c9d61887a45bfa151a86f95436ea405195853abbf8472a3ef82
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800ab1a0.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_800ab1a0(float *param_1,float *param_2,float *param_3)

{
  *param_3 = *param_1 * *param_2 + param_1[1] * param_2[1] + param_1[2] * param_2[2] + param_1[9];
  param_3[1] = param_1[3] * *param_2 + param_1[4] * param_2[1] + param_1[5] * param_2[2] +
               param_1[10];
  param_3[2] = param_1[6] * *param_2 + param_1[7] * param_2[1] + param_1[8] * param_2[2] +
               param_1[0xb];
  return;
}
