/* FUN_800acfa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acfa8  body 0x800acfa8..0x800ad0bf  size 283 B
 * sha256  349d2ee285a8ab22f86cf3703c5056e21378bc7286cb90e1a8bb8692852b2771
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800acfa8(short param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_800a5678();
  iVar3 = _DAT_801529f0;
  iVar4 = 0;
  if (0 < _DAT_801529f0) {
    iVar1 = -0x7fead600;
    do {
      if (*(short *)(iVar1 + 4) == param_1) break;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar4 < _DAT_801529f0);
  }
  if (iVar4 != _DAT_801529f0) {
    sVar2 = *(short *)(iVar4 * 0xc + -0x7fead5f8) + -1;
    *(short *)(iVar4 * 0xc + -0x7fead5f8) = sVar2;
    iVar4 = iVar4 + 1;
    if (sVar2 == 0) {
      if (iVar4 < iVar3) {
        puVar5 = (undefined4 *)(iVar4 * 0xc + -0x7fead600);
        iVar3 = iVar4 * 0xc + -0xc;
        do {
          uVar6 = puVar5[1];
          uVar7 = puVar5[2];
          *(undefined4 *)(iVar3 + -0x7fead600) = *puVar5;
          *(undefined4 *)(&DAT_80152a04 + iVar3) = uVar6;
          *(undefined4 *)(iVar3 + -0x7fead5f8) = uVar7;
          puVar5 = puVar5 + 3;
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0xc;
        } while (iVar4 < _DAT_801529f0);
      }
      _DAT_801529f0 = _DAT_801529f0 + -1;
      FUN_800a56c0();
      return 1;
    }
  }
  FUN_800a56c0();
  return 0;
}
