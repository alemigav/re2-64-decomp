/* FUN_800ab2cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab2cc  body 0x800ab2cc..0x800ab32f  size 103 B
 * sha256  8027be81d582d445984cb1608bae0367f282a36a6fb49bea57b6b1bbb8d75531
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab2cc(float *param_1,float *param_2,float *param_3)

{
  *param_1 = param_2[1] * param_3[2] - param_2[2] * param_3[1];
  param_1[1] = param_2[2] * *param_3 - *param_2 * param_3[2];
  param_1[2] = *param_2 * param_3[1] - param_2[1] * *param_3;
  return;
}
