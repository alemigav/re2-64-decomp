/* FUN_80081754
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081754  body 0x80081754..0x800818c7  size 375 B
 * sha256  70df5e043041374b58e4744dea42932f84e12a8d6c5dd5ebcbb1e28d632248bb
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80081754(int param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      if (((*(ushort *)(param_1 + 0x1ac) & 0x10) != 0) &&
         (iVar2 = FUN_80069854(param_1,0x1c2,DAT_80112718), iVar2 != 0)) {
        return;
      }
      cVar3 = FUN_80081de8(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220)
                          );
      if (cVar3 == '\0') {
        return;
      }
      FUN_80083758(&DAT_800e8d00,*(undefined1 *)(param_1 + 0x267));
      *(undefined1 *)(param_1 + 5) = 6;
      *(undefined1 *)(param_1 + 6) = 0;
      if ((*(ushort *)(param_1 + 0x268) & 4) == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 5) = 0x12;
      *(undefined1 *)(param_1 + 6) = 2;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    if (*(byte *)(param_1 + 8) < 0x10) {
      iVar2 = *(byte *)(param_1 + 8) + 0x10;
    }
    else {
      iVar2 = *(byte *)(param_1 + 8) - 0x40;
    }
    *(ushort *)(param_1 + 0x1e0) = (ushort)(byte)(&DAT_8011b570)[iVar2 * 2];
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
  }
  cVar3 = FUN_80081d1c(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  if (cVar3 != '\0') {
    *(undefined1 *)(param_1 + 6) = 2;
  }
  return;
}
