/* FUN_8005963c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005963c  body 0x8005963c..0x80059683  size 75 B
 * body sha256 41846b0e92de424e5325ab051661096aa2e239b3e9645a9250dc656ad887afc8
 * provider record sha256 5225533c31bd2fc48509e9963e4e7d28d0a0f3f7d458315a729ecec632107cb4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_3(void)

{
  char cVar1;
  ushort uVar2;
  int unaff_s1;
  
  FUN_80032b5c();
  cVar1 = FUN_80089d54();
  uVar2 = *(short *)(unaff_s1 + 0x1e0) + 0xf;
  *(ushort *)(unaff_s1 + 0x1e0) = uVar2;
  *(char *)(unaff_s1 + 6) = *(char *)(unaff_s1 + 6) + cVar1;
  if (0 < (int)((uint)uVar2 << 0x10)) {
    *(undefined2 *)(unaff_s1 + 0x1e0) = 0;
  }
  return;
}
