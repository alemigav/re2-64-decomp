/* FUN_800ab1a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab1a0  body 0x800ab1a0..0x800ab24b  size 175 B
 * body sha256 76842c1c8fe6301ed0426830ff5b868cd0c399e3f7611879aa8ae2bb83c84d09
 * provider record sha256 16c7a957cf768736f4566b7fa31a54f8388852d74e51827b42cf0305fba7c36e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
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
