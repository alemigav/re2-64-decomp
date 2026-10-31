/* FUN_800a9578
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9578  body 0x800a9578..0x800a95fb  size 135 B
 * sha256  dba095582ff2abbe0a2b9e6cc09a134b7e221146a32fe7c9eec35079b7c9e0ed
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a9578(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_80147a58 != 0) {
    pcVar1 = &DAT_801481e0;
    do {
      if (*pcVar1 == '\x01') {
        FUN_800a5c50(*(undefined4 *)(pcVar1 + 8),*(undefined4 *)(pcVar1 + 0xc));
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 0x18;
    } while (iVar2 < (int)(uint)DAT_80147a58);
  }
  return;
}
