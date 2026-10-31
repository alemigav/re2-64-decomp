/* FUN_80089c3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80089c3c  body 0x80089c3c..0x80089d53  size 283 B
 * body sha256 d14289280e0b96ae4ffbac8c6b362544012907cbc99af8c9680e54f0009150c8
 * provider record sha256 5cb2711d45186a1d6b30ba5f090e3d591cd94d9832255a4d73a0398c19b37738
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80089c3c(short *param_1,short *param_2,undefined2 *param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0x1000 - param_4;
  *param_3 = (short)((uint)(*param_1 * iVar1 + *param_2 * param_4) >> 0xc);
  param_3[1] = (short)((uint)(param_1[1] * iVar1 + param_2[1] * param_4) >> 0xc);
  param_3[2] = (short)((uint)(param_1[2] * iVar1 + param_2[2] * param_4) >> 0xc);
  param_3[3] = (short)((uint)(param_1[3] * iVar1 + param_2[3] * param_4) >> 0xc);
  param_3[4] = (short)((uint)(param_1[4] * iVar1 + param_2[4] * param_4) >> 0xc);
  param_3[5] = (short)((uint)(param_1[5] * iVar1 + param_2[5] * param_4) >> 0xc);
  FUN_80041d50(param_3,param_3);
  return;
}
