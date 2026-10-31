/* FUN_800598a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800598a0  body 0x800598a0..0x800598fb  size 95 B
 * body sha256 6c27bd0c84e63ea2dc622ebebb9945f17a7881483b039780c87ed33dd9e17f59
 * provider record sha256 a4dc041eba885a526f4cae74ec0f2d5e255c4bdad4595cbaba835781e893837f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80059930) */

void switchD_80059898::caseD_0(void)

{
  char cVar2;
  short sVar1;
  uint *unaff_s0;
  
  unaff_s0[0x7a] = 0x5000300;
  *(undefined1 *)((int)unaff_s0 + 6) = 1;
  *(undefined2 *)(unaff_s0 + 0x78) = 400;
  *(undefined2 *)((int)unaff_s0 + 0x1e2) = 0;
  *(undefined2 *)(unaff_s0 + 0x79) = 0;
  *(byte *)((int)unaff_s0 + 0x26f) = *(byte *)((int)unaff_s0 + 0x26f) | 0x80;
  *(byte *)(unaff_s0 + 0x97) = *(byte *)(unaff_s0 + 0x97) | 0x12;
  FUN_80077adc(0x4020001,unaff_s0 + 10);
  *unaff_s0 = *unaff_s0 & 0xfffffffb;
  FUN_80032b5c();
  cVar2 = FUN_80089d54();
  *(char *)((int)unaff_s0 + 6) = *(char *)((int)unaff_s0 + 6) + cVar2;
  if (*(char *)((int)unaff_s0 + 0x1ea) == '\0') {
    sVar1 = *(short *)(unaff_s0 + 0x78) + -0x32;
  }
  else {
    sVar1 = *(short *)(unaff_s0 + 0x78) + -0x14;
  }
  *(short *)(unaff_s0 + 0x78) = sVar1;
  if (*(short *)(unaff_s0 + 0x78) < 0) {
    *(undefined2 *)(unaff_s0 + 0x78) = 0;
  }
  return;
}
