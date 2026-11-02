/* FUN_800596a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800596a8  body 0x800596a8..0x800596f7  size 80 B
 * body sha256 f7fac78924b262edb3171ac15ad2f26ecb031d3b8933b3e0b66bca67c880a114
 * provider record sha256 2110357cda7b55b4a91f30d4ecd485f9dcca4a76fec6a783c03a0f0992de213c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_5(void)

{
  char cVar1;
  int unaff_s1;
  
  *(undefined4 *)(unaff_s1 + 0x1e8) = 0x300;
  *(undefined1 *)(unaff_s1 + 6) = 6;
  FUN_80077adc(0x2290001,unaff_s1 + 0x28);
  FUN_80077adc(0x4020001,unaff_s1 + 0x28);
  FUN_80052bd0(1,0);
  FUN_80052c6c(5,0xfa,0);
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s1 + 6) = *(char *)(unaff_s1 + 6) + cVar1;
  return;
}
