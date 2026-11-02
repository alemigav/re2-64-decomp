/* FUN_80059618
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059618  body 0x80059618..0x8005963b  size 36 B
 * body sha256 8c30c7be6701a2773a361ad15c0a777731c416f0b4a5b35786b356c2a464c86f
 * provider record sha256 aff0b69f8125a8ff081c1bffbc572d87bd15a1c4fadc0b362461c1357092d033
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_2(void)

{
  char cVar1;
  ushort uVar2;
  int unaff_s1;
  
  *(undefined4 *)(unaff_s1 + 0x1e8) = 0x3000300;
  *(undefined1 *)(unaff_s1 + 6) = 3;
  FUN_80077adc(0x22a0001,unaff_s1 + 0x28);
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
