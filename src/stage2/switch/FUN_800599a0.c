/* FUN_800599a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800599a0  body 0x800599a0..0x80059a1f  size 128 B
 * body sha256 8cb149abfef5b89e78e133c9f5ad911649a12c1f1643802a972f8f3bf5c032cd
 * provider record sha256 02f29961b39b2733da91f02a1943de41bffab4cb1bd9feac8ad5d52f89e6944f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059898::caseD_2(void)

{
  int iVar1;
  int unaff_s0;
  
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0x4000300;
  *(undefined1 *)(unaff_s0 + 6) = 3;
  *(undefined2 *)(unaff_s0 + 500) = 0x1e;
  if (*(short *)(unaff_s0 + 0x1f2) < 0x96) {
    *(undefined2 *)(unaff_s0 + 500) = 0x3c;
  }
  if (*(short *)(unaff_s0 + 0x1f2) < 0x46) {
    *(short *)(unaff_s0 + 500) = *(short *)(unaff_s0 + 500) + 0x32;
  }
  if (*(short *)(unaff_s0 + 0x1f2) < 0x1e) {
    *(short *)(unaff_s0 + 500) = *(short *)(unaff_s0 + 500) + 0x32;
  }
  if (*(short *)(unaff_s0 + 0x1f2) == 0) {
    *(short *)(unaff_s0 + 500) = *(short *)(unaff_s0 + 500) + 100;
  }
  FUN_80089d54();
  iVar1 = FUN_800331b8();
  iVar1 = (uint)*(ushort *)(unaff_s0 + 500) - (iVar1 * 3 + 1);
  *(short *)(unaff_s0 + 500) = (short)iVar1;
  if (iVar1 * 0x10000 < 0) {
    *(undefined1 *)(unaff_s0 + 6) = 4;
  }
  return;
}
