/* FUN_800ad62c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ad62c  body 0x800ad62c..0x800ad817  size 495 B
 * sha256  af9e0ac4cf97c5dc69443a73ade1e241cfb649eaa3b624d348f45f5d4a3f6fa7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ad62c(ushort param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  FUN_800a5678();
  uVar3 = (uint)(param_1 >> 6);
  iVar2 = uVar3 * 4;
  if (*(ushort *)(&DAT_80153610 + iVar2) == 0) {
    uVar7 = _DAT_80153600 & 0xffff;
    *(undefined2 *)(&DAT_80153612 + iVar2) = _DAT_80153602;
    uVar8 = uVar7;
  }
  else {
    uVar7 = (uint)*(ushort *)(&DAT_80153610 + iVar2);
    uVar8 = (uint)*(ushort *)(&DAT_80153612 + iVar2);
    iVar2 = 0;
    if (uVar7 != 0) {
      uVar1 = uVar8;
      do {
        if (param_1 <= *(ushort *)(uVar1 * 8 + -0x7feac1ec)) break;
        iVar2 = iVar2 + 1;
        uVar1 = uVar8 + iVar2;
      } while (iVar2 < (int)uVar7);
      uVar7 = uVar8 + iVar2;
      if (iVar2 < (int)(uint)*(ushort *)(&DAT_80153610 + uVar3 * 4)) {
        iVar2 = uVar7 * 8;
        if (*(ushort *)(iVar2 + -0x7feac1ec) == param_1) {
          *(short *)(iVar2 + -0x7feac1ea) = *(short *)(iVar2 + -0x7feac1ea) + 1;
          goto LAB_800ad7f8;
        }
        goto LAB_800ad714;
      }
    }
    uVar7 = uVar8 + iVar2;
  }
LAB_800ad714:
  iVar2 = 0;
  if ((int)_DAT_80153600 < 0x800) {
    puVar5 = &DAT_80153610;
    do {
      iVar2 = iVar2 + 1;
      if (uVar8 < *(ushort *)(puVar5 + 2)) {
        *(ushort *)(puVar5 + 2) = *(ushort *)(puVar5 + 2) + 1;
      }
      puVar5 = puVar5 + 4;
    } while (iVar2 < 0x200);
    iVar2 = _DAT_80153600 - 1;
    if ((int)uVar7 <= iVar2) {
      puVar6 = (undefined4 *)(iVar2 * 8 + -0x7feac1f0);
      iVar4 = iVar2 * 8 + 8;
      do {
        uVar9 = puVar6[1];
        *(undefined4 *)(iVar4 + -0x7feac1f0) = *puVar6;
        *(undefined4 *)(iVar4 + -0x7feac1ec) = uVar9;
        puVar6 = puVar6 + -2;
        iVar2 = iVar2 + -1;
        iVar4 = iVar4 + -8;
      } while ((int)uVar7 <= iVar2);
    }
    iVar2 = uVar7 * 8;
    *(undefined2 *)(iVar2 + -0x7feac1ea) = 1;
    *(ushort *)(iVar2 + -0x7feac1ec) = param_1;
    *(undefined4 *)(iVar2 + -0x7feac1f0) = param_2;
    _DAT_80153600 = _DAT_80153600 + 1;
    *(short *)(&DAT_80153610 + uVar3 * 4) = *(short *)(&DAT_80153610 + uVar3 * 4) + 1;
    FUN_800a56c0();
    return 1;
  }
LAB_800ad7f8:
  FUN_800a56c0();
  return 0;
}
