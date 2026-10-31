/* FUN_80029db4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80029db4  body 0x80029db4..0x80029f07  size 343 B
 * sha256  bb10a8a7320ecfc030a3492796e76154b5857af703b2444c704d25a7e235fc23
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80029db4(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  if ((*(int *)(param_1 + 0x10) < (int)param_3) &&
     (iVar1 = FUN_80029c20(param_1,param_3), iVar1 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(int *)(param_1 + 0x10) - param_3;
    *(uint *)(param_1 + 0x10) = uVar2;
    iVar1 = param_2 + param_3 * 4;
    uVar2 = *(int *)(param_1 + 0xc) >> (uVar2 & 0x1f) & (1 << (param_3 & 0x1f)) - 1U;
    if (*(int *)(iVar1 + 0x44) < (int)uVar2) {
      do {
        if ((*(int *)(param_1 + 0x10) < 1) && (iVar3 = FUN_80029c20(param_1,1), iVar3 == 0)) {
          return 0xffffffff;
        }
        uVar4 = *(int *)(param_1 + 0x10) - 1;
        *(uint *)(param_1 + 0x10) = uVar4;
        piVar5 = (int *)(iVar1 + 0x48);
        uVar2 = uVar2 << 1 | *(int *)(param_1 + 0xc) >> (uVar4 & 0x1f) & 1U;
        param_3 = param_3 + 1;
        iVar1 = iVar1 + 4;
      } while (*piVar5 < (int)uVar2);
    }
    if ((int)param_3 < 0x11) {
      piVar5 = (int *)(param_2 + param_3 * 4);
      uVar2 = (uint)*(byte *)(*(int *)(param_2 + 0xd0) + piVar5[0x23] + (uVar2 - *piVar5) + 0x11);
    }
    else {
      *(undefined4 *)(**(int **)(param_1 + 0x24) + 0x14) = 0x69;
      (**(code **)(**(int **)(param_1 + 0x24) + 4))(*(int **)(param_1 + 0x24),0xffffffff);
      uVar2 = 0;
    }
  }
  return uVar2;
}
