/* FUN_800596f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800596f8  body 0x800596f8..0x8005971b  size 39 B
 * body sha256 d876a72fe04dc4f6e0757bf38efb1e441d02004a2f096da5399b85e9206c6b48
 * provider record sha256 40b685bfcd41ddbe77c243ecd1438fba8086344c39ece6de172f47fde2497f13
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_6(void)

{
  char cVar1;
  int unaff_s1;
  
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s1 + 6) = *(char *)(unaff_s1 + 6) + cVar1;
  return;
}
