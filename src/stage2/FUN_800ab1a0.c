/* FUN_800ab1a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab1a0  body 0x800ab1a0..0x800ab24b  size 175 B
 * sha256  0c02d89e1613ebae3071f5b221b7939c31a7a83bb4055d57aed07ae4e5f1e11e
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
