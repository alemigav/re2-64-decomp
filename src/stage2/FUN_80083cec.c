/* FUN_80083cec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083cec  body 0x80083cec..0x80083d2b  size 67 B
 * sha256  def711b5d4b7be05b01c26a96c2f93676b68b40ac4ec7046d71b6d01c8994f86
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80083cec(uint param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(*(int *)(DAT_800df92c + 0x28) + 2);
  iVar2 = *(int *)(DAT_800df92c + 0x28);
  while (bVar1 != param_1) {
    bVar1 = *(byte *)(iVar2 + 0x16);
    iVar2 = iVar2 + 0x14;
  }
  return iVar2;
}
