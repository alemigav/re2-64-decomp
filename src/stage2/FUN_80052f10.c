/* FUN_80052f10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052f10  body 0x80052f10..0x80052f3b  size 47 B
 * sha256  6b3cd4c88eff6ae1e8c943e32e8b8a6f185f5711c8eba35ae988c0f90668e918
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80052f10(char *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  do {
    if (*param_1 != '\0') {
      iVar2 = iVar2 + 1;
    }
    uVar1 = uVar1 + 1;
    param_1 = param_1 + 10;
  } while (uVar1 < 0x20);
  return iVar2;
}
