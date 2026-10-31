/* FUN_800acbc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acbc0  body 0x800acbc0..0x800acd1b  size 351 B
 * sha256  bdd826e6b60c8e074290929561244f605a745810ed0dd7d69e942a2b14b6d54b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800acbc0(ushort param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  FUN_800a5678();
  iVar4 = 0;
  if (0 < _DAT_801521e0) {
    iVar1 = -0x7feade10;
    do {
      if (param_1 <= *(ushort *)(iVar1 + 4)) break;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 8;
    } while (iVar4 < _DAT_801521e0);
    iVar1 = iVar4 * 8;
    if (iVar4 < _DAT_801521e0) {
      if (*(ushort *)(&DAT_801521f4 + iVar1) == param_1) {
        *(short *)(iVar1 + -0x7feade0a) = *(short *)(iVar1 + -0x7feade0a) + 1;
        goto LAB_800acccc;
      }
      iVar1 = _DAT_801521e0 + -1;
      if (0x7ff < _DAT_801521e0) goto LAB_800acccc;
      if (iVar4 <= iVar1) {
        puVar3 = (undefined4 *)(iVar1 * 8 + -0x7feade10);
        iVar2 = iVar1 * 8 + 8;
        do {
          uVar5 = puVar3[1];
          *(undefined4 *)(iVar2 + -0x7feade10) = *puVar3;
          *(undefined4 *)(&DAT_801521f4 + iVar2) = uVar5;
          puVar3 = puVar3 + -2;
          iVar1 = iVar1 + -1;
          iVar2 = iVar2 + -8;
        } while (iVar4 <= iVar1);
      }
      goto LAB_800acce0;
    }
  }
  if (0x7ff < _DAT_801521e0) {
LAB_800acccc:
    FUN_800a56c0();
    return 0;
  }
LAB_800acce0:
  _DAT_801521e0 = _DAT_801521e0 + 1;
  iVar4 = iVar4 * 8;
  *(ushort *)(&DAT_801521f4 + iVar4) = param_1;
  *(undefined4 *)(iVar4 + -0x7feade10) = param_2;
  *(undefined2 *)(iVar4 + -0x7feade0a) = 1;
  FUN_800a56c0();
  return 1;
}
