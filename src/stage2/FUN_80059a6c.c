/* FUN_80059a6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059a6c  body 0x80059a6c..0x80059a83  size 24 B
 * body sha256 561d86ade5f8f167e2b9d57a9edda2d944fa282d4fe3e331a2ee2b0a49bbaa19
 * provider record sha256 4798e174373cce837bfb67a23602f7d1954a3ee312446bbfb8600d843ff29c36
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059898::caseD_4(void)

{
  int iVar1;
  int unaff_s0;
  
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0x1000300;
  *(undefined1 *)(unaff_s0 + 6) = 5;
  *(undefined1 *)(unaff_s0 + 0x26f) = 0;
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined1 *)(unaff_s0 + 6) = 6;
    *(undefined4 *)(unaff_s0 + 0x1e8) = 0x6000300;
  }
  return;
}
