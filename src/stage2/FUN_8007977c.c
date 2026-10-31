/* FUN_8007977c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007977c  body 0x8007977c..0x800797f3  size 123 B
 * sha256  6035c614e9b39aa03c68d879f891b8b7baa7332dbd2ebf46cae56be01732ae7a
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
