/* FUN_800ab24c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab24c  body 0x800ab24c..0x800ab2cb  size 131 B
 * sha256  5cb1063ef8e9c2dfa93ff1b4c54ec76592a68dd715a904ff7f35a0fff99646e7
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800ab290) */

void FUN_800ab24c(float *param_1)

{
  float fVar1;
  
  fVar1 = SQRT(*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]);
  *param_1 = *param_1 / fVar1;
  param_1[2] = param_1[2] / fVar1;
  param_1[1] = param_1[1] / fVar1;
  return;
}
