/* FUN_80059a84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059a84  body 0x80059a84..0x80059ab3  size 48 B
 * body sha256 402ebb64c9f6e6c951066b4ccbfa91f856d5659206a2ee40c99f491144474382
 * provider record sha256 e6880179ed6f319c438c635661ad6c6ba75724b998138a33c139ce06e1ddc5e2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059898::caseD_5(void)

{
  int iVar1;
  int unaff_s0;
  
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined1 *)(unaff_s0 + 6) = 6;
    *(undefined4 *)(unaff_s0 + 0x1e8) = 0x6000300;
  }
  return;
}
