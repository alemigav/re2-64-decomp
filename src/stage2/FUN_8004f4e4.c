/* FUN_8004f4e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004f4e4  body 0x8004f4e4..0x8004f54b  size 107 B
 * body sha256 c70353feb78e38f7b6e427828203aab09f0eb8b9def361d3e330c145aad3b33c
 * provider record sha256 e5b96aa10b545360cfc01000d22e4e1be49df03b75912599846781ff808652d5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004f4e4(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x30);
  if (-1 < param_3) {
    param_4 = -param_4;
  }
  param_4 = (*(int *)(param_2 + 8) - (int)*(short *)(param_1 + 0x132)) + param_4;
  *(int *)(param_1 + 0x30) = param_4;
  *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + (param_4 - iVar2);
  uVar1 = FUN_8004f54c(param_1,param_1 + 0x120);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  return;
}
