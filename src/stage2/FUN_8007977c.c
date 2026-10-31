/* FUN_8007977c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007977c  body 0x8007977c..0x800797f3  size 123 B
 * body sha256 48b2fb7739154430f9ca8fcac7586c38b355a236fc159627e4d691dda64e2648
 * provider record sha256 ddafdb9ce65c80b5b695cf1ebcb8087f6b8e20bc1685f2db50121eea9d1054d5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007977c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8eb8,5);
  if (((iVar1 == 0) && (iVar1 = FUN_800837ac(&DAT_800e8eb8,0xf), iVar1 == 0)) &&
     ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0)) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
  }
  return;
}
