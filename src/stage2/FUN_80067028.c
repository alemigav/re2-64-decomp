/* FUN_80067028
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80067028  body 0x80067028..0x80067197  size 371 B
 * body sha256 474175791c00a1b8ca1965054528256e1c7124a3278ddfd894086dea58c8effa
 * provider record sha256 aae25b0042c3d04d2339eb411abb8cd38a4424c850e824df2a2d88a50d6b2609
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80067028(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_3 ^ *(int *)(param_1 + 0x120) - (int)*(short *)(param_1 + 0x1b4)) >> 0x1f |
          (param_4 ^ *(int *)(param_1 + 0x128) - (int)*(short *)(param_1 + 0x1b6)) >> 0x1e & 2;
  if (uVar3 != 2) {
    if (uVar3 < 3) {
      if (uVar3 == 1) {
        uVar3 = param_3;
        if ((int)param_3 < 0) {
          uVar3 = -param_3;
        }
        iVar1 = *(int *)(param_1 + 0x120) + param_3;
        if ((int)uVar3 < 0x191) goto LAB_800670a8;
        goto LAB_800670d4;
      }
    }
    else if (uVar3 == 3) goto LAB_800670d4;
    uVar3 = param_3;
    if ((int)param_3 < 0) {
      uVar3 = -param_3;
    }
    uVar2 = param_4;
    if ((int)param_4 < 0) {
      uVar2 = -param_4;
    }
    if ((int)uVar2 <= (int)uVar3) {
      *(uint *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + param_4;
      return 1;
    }
    iVar1 = *(int *)(param_1 + 0x120) + param_3;
LAB_800670a8:
    *(int *)(param_1 + 0x120) = iVar1;
    return 1;
  }
  uVar3 = param_4;
  if ((int)param_4 < 0) {
    uVar3 = -param_4;
  }
  if ((int)uVar3 < 0x191) {
    *(uint *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + param_4;
    return 1;
  }
LAB_800670d4:
  uVar3 = param_3;
  if ((int)param_3 < 0) {
    uVar3 = -param_3;
  }
  uVar2 = param_4;
  if ((int)param_4 < 0) {
    uVar2 = -param_4;
  }
  if ((int)uVar3 < (int)uVar2) {
    uVar3 = param_3;
    if ((int)param_3 < 0) {
      uVar3 = -param_3;
    }
    if ((int)uVar3 < 0x321) {
      iVar1 = *(int *)(param_1 + 0x120) + param_3;
      goto LAB_800670a8;
    }
  }
  else {
    uVar3 = param_4;
    if ((int)param_4 < 0) {
      uVar3 = -param_4;
    }
    if ((int)uVar3 < 0x321) {
      *(uint *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + param_4;
      return 1;
    }
  }
  *(int *)(param_1 + 0x120) = (int)*(short *)(param_1 + 0x1b4);
  *(int *)(param_1 + 0x128) = (int)*(short *)(param_1 + 0x1b6);
  return 1;
}
