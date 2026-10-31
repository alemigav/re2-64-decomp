/* FUN_800ade04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ade04  body 0x800ade04..0x800adef3  size 243 B
 * sha256  9219a5a7dd6b37f286506ccd0b945633b1724f8c5e5439a57263ac877b1f41f7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ade04(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = 0;
  if (0 < _DAT_8014e16c) {
    piVar2 = (int *)&DAT_8014e170;
    do {
      if (*piVar2 == param_1) break;
      iVar6 = iVar6 + 1;
      piVar2 = piVar2 + 3;
    } while (iVar6 < _DAT_8014e16c);
  }
  uVar1 = 0;
  if (iVar6 != _DAT_8014e16c) {
    FUN_800a5678();
    iVar6 = iVar6 + 1;
    if (iVar6 < _DAT_8014e16c) {
      puVar4 = (undefined4 *)(&DAT_8014e170 + iVar6 * 0xc);
      iVar3 = iVar6 * 0xc + -0xc;
      do {
        uVar1 = puVar4[1];
        uVar5 = puVar4[2];
        *(undefined4 *)(&DAT_8014e170 + iVar3) = *puVar4;
        *(undefined4 *)(iVar3 + -0x7feb1e8c) = uVar1;
        *(undefined4 *)(&DAT_8014e178 + iVar3) = uVar5;
        puVar4 = puVar4 + 3;
        iVar6 = iVar6 + 1;
        iVar3 = iVar3 + 0xc;
      } while (iVar6 < _DAT_8014e16c);
    }
    _DAT_8014e16c = _DAT_8014e16c + -1;
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
