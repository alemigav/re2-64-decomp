/* FUN_800a9540
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9540  body 0x800a9540..0x800a9577  size 59 B
 * sha256  916c0fcf54160217469ce31527daabf5f18f1129a97bce8bfef830a69d0a122c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a9540(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = 0;
  if (DAT_80147a58 != 0) {
    puVar2 = &DAT_801481e0;
    do {
      *puVar2 = 0;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x18;
    } while (iVar1 < (int)(uint)DAT_80147a58);
  }
  return;
}
