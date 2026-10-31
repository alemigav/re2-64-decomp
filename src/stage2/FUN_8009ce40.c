/* FUN_8009ce40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ce40  body 0x8009ce40..0x8009ced7  size 155 B
 * sha256  e86c9c00e86ba7d86165b8e59cf2e18a8de56e45b937cf56db18e86513b2f719
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ce40(void)

{
  int iVar1;
  
  if ((DAT_80132728 & 1) == 0) {
    FUN_800274f8(DAT_8013272b | 0x200,0xffffff00,7,1);
    DAT_8013272a = 0;
    DAT_80132728 = DAT_80132728 | 1;
    FUN_800274e4(5,0);
  }
  else {
    iVar1 = FUN_8002767c(DAT_8013272b);
    if (iVar1 != 0) {
      DAT_8013272a = 1;
      DAT_80132728 = DAT_80132728 ^ 1;
    }
  }
  return;
}
