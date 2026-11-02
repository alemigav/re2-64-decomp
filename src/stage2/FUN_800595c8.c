/* FUN_800595c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800595c8  body 0x800595c8..0x80059617  size 80 B
 * body sha256 ce6351bd7a6a8cae7b71c7b578232aea0d0d6692e3089cbb2083120762360ae8
 * provider record sha256 2c7acde95227951fc885d78309006028438a1506c89d0ef01c7d211f7baa045a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_1(void)

{
  int unaff_s1;
  
  if (*(char *)(unaff_s1 + 0x1ea) == '\0') {
    *(undefined1 *)(unaff_s1 + 6) = 2;
  }
  FUN_80032b5c();
  FUN_80089d54();
  *(short *)(unaff_s1 + 0x1e0) = *(short *)(unaff_s1 + 0x1e0) + 0x96;
  if ((*(uint *)(unaff_s1 + 0x1ac) & 1) != 0) {
    *(undefined1 *)(unaff_s1 + 6) = 5;
  }
  return;
}
