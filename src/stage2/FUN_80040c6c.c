/* FUN_80040c6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040c6c  body 0x80040c6c..0x80040cf3  size 139 B
 * sha256  fc7a6dd80040666f0f266577a6b811e85684298f73f56db76b1591017709cae1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040c6c(int *param_1,int *param_2,int *param_3)

{
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - param_1[1] * *param_2;
  return;
}
