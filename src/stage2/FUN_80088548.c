/* FUN_80088548
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088548  body 0x80088548..0x8008857b  size 55 B
 * sha256  a30b0bda6a60aedd285c3c009873ad3d456d66fe891f0577f752390ce6691d4c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80088548(undefined2 *param_1,int param_2)

{
  DAT_8012bae0 = param_1;
  *param_1 = 1;
  param_1[1] = 0;
  *(int *)(param_1 + 2) = param_2 + -0x20;
  *(undefined2 *)((int)param_1 + param_2 + -0x10) = 8;
  *(undefined2 *)((int)param_1 + param_2 + -0xe) = 0;
  *(undefined4 *)((int)param_1 + param_2 + -0xc) = 0;
  return;
}
