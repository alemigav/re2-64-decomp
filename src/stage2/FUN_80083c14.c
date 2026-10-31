/* FUN_80083c14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083c14  body 0x80083c14..0x80083ceb  size 219 B
 * sha256  2da87fbc76ae28618ec38d8f899f2cfc27b5f7107dceb3adcc2ac358969e3659
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80083c14(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_80027148();
  DAT_800df944 = FUN_80083cec(param_1);
  if (DAT_800df92c != 0) {
    iVar2 = *(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20;
    FUN_800828ac(iVar2 + 4,iVar2 + 0x10);
    iVar2 = *(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20;
    FUN_80075878(iVar2 + 4,iVar2 + 0x10);
    FUN_800428e0(*(ushort *)(DAT_800e8cac * 0x20 + *(int *)(DAT_800df92c + 0x24) + 2) >> 7);
  }
  uVar1 = FUN_80083f88();
  FUN_80026980(uVar1);
  FUN_80062cfc(0);
  return;
}
