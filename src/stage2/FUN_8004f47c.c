/* FUN_8004f47c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004f47c  body 0x8004f47c..0x8004f4e3  size 107 B
 * sha256  7dd46f9f2993b8cdef2de04787369992ee4b7abfbe7c0ce896566f210d2bb5a7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004f47c(int param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x120);
  iVar2 = *(int *)(param_1 + 0x28);
  if (-1 < param_3) {
    param_4 = -param_4;
  }
  param_4 = (*param_2 - (int)*(short *)(param_1 + 0x130)) + param_4;
  *(int *)(param_1 + 0x28) = param_4;
  *piVar3 = *piVar3 + (param_4 - iVar2);
  uVar1 = FUN_8004f54c(param_1,piVar3);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  return;
}
