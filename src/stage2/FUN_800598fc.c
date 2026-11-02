/* FUN_800598fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800598fc  body 0x800598fc..0x8005999f  size 164 B
 * body sha256 6cb0983b01b2c01cbb76ef0fcff51f13bf76c0024e59457f6a3f39aef7d7d1b6
 * provider record sha256 8e4905fa577b7c6db4f75f08aef244c03934b850607415ca48c6be2dbdfcb97e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80059930) */

void switchD_80059898::caseD_1(void)

{
  char cVar2;
  short sVar1;
  int unaff_s0;
  
  FUN_80032b5c();
  cVar2 = FUN_80089d54();
  *(char *)(unaff_s0 + 6) = *(char *)(unaff_s0 + 6) + cVar2;
  if (*(char *)(unaff_s0 + 0x1ea) == '\0') {
    sVar1 = *(short *)(unaff_s0 + 0x1e0) + -0x32;
  }
  else {
    sVar1 = *(short *)(unaff_s0 + 0x1e0) + -0x14;
  }
  *(short *)(unaff_s0 + 0x1e0) = sVar1;
  if (*(short *)(unaff_s0 + 0x1e0) < 0) {
    *(undefined2 *)(unaff_s0 + 0x1e0) = 0;
  }
  return;
}
