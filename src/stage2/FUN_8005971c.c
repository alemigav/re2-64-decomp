/* FUN_8005971c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005971c  body 0x8005971c..0x8005979b  size 131 B
 * body sha256 88e20cb697aae2c7cc59b947c50f3046bce93ae8a8b0cd80a90c87e4f86bf36a
 * provider record sha256 b9d8b906d9236b3032352e240269dab727b79677c471027456c304237ef580d0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_7(void)

{
  int iVar1;
  int unaff_s1;
  
  *(undefined4 *)(unaff_s1 + 0x1e8) = 0x4000300;
  *(undefined1 *)(unaff_s1 + 6) = 8;
  *(undefined2 *)(unaff_s1 + 500) = 0x1e;
  if (*(short *)(unaff_s1 + 0x1f2) < 0x96) {
    *(undefined2 *)(unaff_s1 + 500) = 0x3c;
  }
  if (*(short *)(unaff_s1 + 0x1f2) < 0x46) {
    *(short *)(unaff_s1 + 500) = *(short *)(unaff_s1 + 500) + 0x32;
  }
  if (*(short *)(unaff_s1 + 0x1f2) < 0x1e) {
    *(short *)(unaff_s1 + 500) = *(short *)(unaff_s1 + 500) + 0x32;
  }
  if (*(short *)(unaff_s1 + 0x1f2) == 0) {
    *(short *)(unaff_s1 + 500) = *(short *)(unaff_s1 + 500) + 100;
  }
  FUN_80089d54();
  iVar1 = FUN_800331b8();
  iVar1 = (uint)*(ushort *)(unaff_s1 + 500) - (iVar1 * 5 + 1);
  *(short *)(unaff_s1 + 500) = (short)iVar1;
  if (iVar1 * 0x10000 < 0) {
    *(undefined1 *)(unaff_s1 + 6) = 9;
  }
  return;
}
