/* FUN_80032b5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032b5c  body 0x80032b5c..0x80032bd7  size 127 B
 * sha256  3cc1df4780665c7326b23254957fee82ab07b3e71b445dbebaebcace4a7f9ef8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80032b5c(int param_1,short param_2)

{
  short local_38;
  short local_36;
  short local_34;
  undefined1 auStack_30 [32];
  
  local_38 = 0;
  local_34 = 0;
  local_36 = *(short *)(param_1 + 0x66) + param_2;
  FUN_80040e58(&local_38,auStack_30);
  FUN_8004276c(auStack_30,param_1 + 0x1e0,&local_38);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_38;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_34;
  return;
}
