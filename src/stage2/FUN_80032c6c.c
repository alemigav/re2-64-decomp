/* FUN_80032c6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032c6c  body 0x80032c6c..0x80032d13  size 171 B
 * sha256  98a6e4f8497530f97642099f479c9c8abee073601ea4bb76d2c14b65d06f04a5
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80032c6c(int param_1,short param_2,short param_3)

{
  short local_58;
  short local_56;
  short local_54;
  undefined1 auStack_50 [32];
  undefined1 auStack_30 [32];
  
  local_58 = 0;
  local_56 = *(short *)(param_1 + 0x66) + param_2;
  local_54 = *(short *)(param_1 + 0x68) + param_3;
  FUN_80040e58(&local_58,auStack_50);
  FUN_800424ec(*(undefined4 *)(param_1 + 0x70),auStack_50,auStack_30);
  FUN_8004276c(auStack_30,param_1 + 0x1e0,&local_58);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_58;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)local_56;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_54;
  return;
}
