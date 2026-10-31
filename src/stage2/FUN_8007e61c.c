/* FUN_8007e61c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e61c  body 0x8007e61c..0x8007e693  size 123 B
 * body sha256 28a67e392e7feaa488cbbab74f4611df382c1b4c398e5f57a07ffd0a56066eff
 * provider record sha256 c1779ce73a461844c011b8ebe53591574f33d289d065fbb9e75e75eef22f84d3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e5c0::caseD_1(void)

{
  ushort uVar1;
  ushort uVar2;
  int unaff_s0;
  
  FUN_80089d54();
  uVar1 = *(ushort *)(unaff_s0 + 0x66);
  if ((uVar1 & 0x200) == 0) {
    uVar2 = -(uVar1 >> 2 & 0xff);
  }
  else {
    uVar2 = uVar1 >> 2 & 0xff;
  }
  *(ushort *)(unaff_s0 + 0x66) = uVar1 + uVar2;
  if ((*(ushort *)(unaff_s0 + 0x66) & 0x3e0) == 0) {
    *(ushort *)(unaff_s0 + 0x66) = *(ushort *)(unaff_s0 + 0x66) & 0xff00;
    *(undefined1 *)(unaff_s0 + 7) = 2;
    if ((*(byte *)(unaff_s0 + 6) & 2) != 0) {
      *(undefined1 *)(unaff_s0 + 7) = 0;
      *(char *)(unaff_s0 + 5) = *(char *)(unaff_s0 + 5) + '\x01';
    }
  }
  return;
}
