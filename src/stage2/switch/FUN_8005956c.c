/* FUN_8005956c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005956c  body 0x8005956c..0x800595c7  size 92 B
 * body sha256 3dbb22f436f0fa3d5bb407026ba9cbfdfbff6db91577edf54cef07529754a79d
 * provider record sha256 a2a1a3174f61c418c4fba8755ac0a0c791bef184436a31a83e29fba2fa715bec
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_0(void)

{
  uint *unaff_s1;
  
  unaff_s1[0x7a] = 0x2000300;
  *(undefined1 *)((int)unaff_s1 + 6) = 1;
  *(undefined2 *)(unaff_s1 + 0x78) = 0xfce0;
  *(undefined2 *)((int)unaff_s1 + 0x1e2) = 0;
  *(undefined2 *)(unaff_s1 + 0x79) = 0;
  *(byte *)((int)unaff_s1 + 0x26f) = *(byte *)((int)unaff_s1 + 0x26f) | 0x80;
  *(byte *)(unaff_s1 + 0x97) = *(byte *)(unaff_s1 + 0x97) | 0x12;
  FUN_80077adc(0x4010001,unaff_s1 + 10);
  *unaff_s1 = *unaff_s1 & 0xfffffffb;
  if (*(char *)((int)unaff_s1 + 0x1ea) == '\0') {
    *(undefined1 *)((int)unaff_s1 + 6) = 2;
  }
  FUN_80032b5c();
  FUN_80089d54();
  *(short *)(unaff_s1 + 0x78) = *(short *)(unaff_s1 + 0x78) + 0x96;
  if ((unaff_s1[0x6b] & 1) != 0) {
    *(undefined1 *)((int)unaff_s1 + 6) = 5;
  }
  return;
}
