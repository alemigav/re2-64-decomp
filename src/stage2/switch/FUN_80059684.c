/* FUN_80059684
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059684  body 0x80059684..0x800596a7  size 36 B
 * body sha256 878ecc27dfbc299ef34fdc29196d49c7bb95ca6324ec6c97fed16dca38a1821b
 * provider record sha256 62bc227a7c2d28edbbaa9379275dbd907caf4640c9cbba297534767418e734e8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_4(void)

{
  int unaff_s1;
  
  FUN_800551e0();
  *(undefined4 *)(unaff_s1 + 4) = 0x1000000;
  *(undefined1 *)(unaff_s1 + 0x26f) = 0;
  *(byte *)(unaff_s1 + 0x25c) = *(byte *)(unaff_s1 + 0x25c) & 0xed;
  return;
}
