/* FUN_80095b90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80095b90  body 0x80095b90..0x80095c33  size 167 B
 * sha256  05a8f1367a825a9ba114b6811346602bbcfc53792d423fbefafcba0efe0126c6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80095b90(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar1 = DAT_800c52dc + 0x3c004U;
  }
  iVar2 = 0x50;
  do {
    iVar2 = iVar2 + -1;
    FUN_80047b04(uVar1,0);
    FUN_8004786c(uVar1,0x80,0x80,0x80);
    FUN_800479bc(uVar1,8,9);
    *(undefined **)(uVar1 + 0xc) = &DAT_8012f584;
    uVar1 = uVar1 + 0x14;
  } while (iVar2 != 0);
  return;
}
