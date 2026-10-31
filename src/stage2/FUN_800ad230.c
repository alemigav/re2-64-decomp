/* FUN_800ad230
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ad230  body 0x800ad230..0x800ad32f  size 259 B
 * sha256  91a6b7719f825e9eb6fa64a5efc53cb602d73f01ace56fffc3a85388ffaf73ea
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ad230(short param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  FUN_800a5678();
  iVar3 = _DAT_8014e1d0;
  iVar4 = 0;
  if (0 < _DAT_8014e1d0) {
    iVar2 = -0x7feb1e20;
    do {
      if (*(short *)(iVar2 + 4) == param_1) break;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 8;
    } while (iVar4 < _DAT_8014e1d0);
  }
  if (iVar4 != _DAT_8014e1d0) {
    sVar1 = *(short *)(iVar4 * 8 + -0x7feb1e1a) + -1;
    *(short *)(iVar4 * 8 + -0x7feb1e1a) = sVar1;
    iVar4 = iVar4 + 1;
    if (sVar1 == 0) {
      if (iVar4 < iVar3) {
        puVar5 = (undefined4 *)(iVar4 * 8 + -0x7feb1e20);
        iVar3 = iVar4 * 8 + -8;
        do {
          uVar6 = puVar5[1];
          *(undefined4 *)(iVar3 + -0x7feb1e20) = *puVar5;
          *(undefined4 *)(&DAT_8014e1e4 + iVar3) = uVar6;
          puVar5 = puVar5 + 2;
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 8;
        } while (iVar4 < _DAT_8014e1d0);
      }
      _DAT_8014e1d0 = _DAT_8014e1d0 + -1;
      FUN_800a56c0();
      return 1;
    }
  }
  FUN_800a56c0();
  return 0;
}
