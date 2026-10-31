/* FUN_8007e694
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e694  body 0x8007e694..0x8007e6a7  size 23 B
 * body sha256 6cb6b5bfbb1b1f3cd5b8ce78dd2dc77117f9857826aaee771b8dc28b68f6e7db
 * provider record sha256 b2618da3a097dd2d0757aedbdac3f000cc95368195d506344454cb9f6bc88220
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e5c0::caseD_2(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint *unaff_s0;
  
  *(undefined1 *)((int)unaff_s0 + 7) = 3;
  *(undefined1 *)(unaff_s0 + 0x7a) = 6;
  *(undefined1 *)((int)unaff_s0 + 0x1ea) = 3;
  if (*(char *)((int)unaff_s0 + 0x1e9) == '\x11') {
    *(byte *)((int)unaff_s0 + 0x26f) = *(byte *)((int)unaff_s0 + 0x26f) | 0x80;
  }
  bVar1 = *(byte *)(unaff_s0 + 2);
  if ((bVar1 == 0x45) || (bVar1 == 0x4f)) {
    cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
    cVar2 = 'w';
    if (cVar3 == 'c') {
      *(undefined1 *)((int)unaff_s0 + 0x1ea) = 0;
      if (*(byte *)(unaff_s0 + 2) < 0x10) {
        iVar4 = *(byte *)(unaff_s0 + 2) + 0x10;
      }
      else {
        iVar4 = *(byte *)(unaff_s0 + 2) - 0x40;
      }
      *(undefined2 *)(unaff_s0 + 0x78) = *(undefined2 *)(&DAT_8010ba78 + iVar4 * 2);
      FUN_80032b5c();
      unaff_s0[0xb] = unaff_s0[0xb] - 0x708;
      *(short *)((int)unaff_s0 + 0x25e) = *(short *)((int)unaff_s0 + 0x25e) + -0x708;
      *(undefined2 *)((int)unaff_s0 + 0x1b6) = *(undefined2 *)((int)unaff_s0 + 0x32);
      *(undefined2 *)(unaff_s0 + 0xe) = *(undefined2 *)((int)unaff_s0 + 0x32);
      *(char *)((int)unaff_s0 + 0x1a2) = *(char *)((int)unaff_s0 + 0x1a2) + '\x01';
      *(undefined2 *)(unaff_s0 + 0x6d) = *(undefined2 *)((int)unaff_s0 + 0x2a);
      *(undefined2 *)(unaff_s0 + 0xd) = *(undefined2 *)((int)unaff_s0 + 0x2a);
      *(undefined2 *)((int)unaff_s0 + 0x36) = *(undefined2 *)((int)unaff_s0 + 0x2e);
      cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
      cVar2 = 'w';
    }
  }
  else {
    cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
    cVar2 = '1';
    if (cVar3 == '\x1d') {
      if (bVar1 < 0x10) {
        iVar4 = *(byte *)(unaff_s0 + 2) + 0x10;
      }
      else {
        iVar4 = *(byte *)(unaff_s0 + 2) - 0x40;
      }
      *(undefined2 *)(unaff_s0 + 0x78) = *(undefined2 *)(&DAT_8010ba78 + iVar4 * 2);
      FUN_80032b5c();
      unaff_s0[0xb] = unaff_s0[0xb] - 0x708;
      *(short *)((int)unaff_s0 + 0x25e) = *(short *)((int)unaff_s0 + 0x25e) + -0x708;
      *(undefined2 *)((int)unaff_s0 + 0x1b6) = *(undefined2 *)((int)unaff_s0 + 0x32);
      *(undefined2 *)(unaff_s0 + 0xe) = *(undefined2 *)((int)unaff_s0 + 0x32);
      *(char *)((int)unaff_s0 + 0x1a2) = *(char *)((int)unaff_s0 + 0x1a2) + '\x01';
      *(undefined2 *)(unaff_s0 + 0x6d) = *(undefined2 *)((int)unaff_s0 + 0x2a);
      *(undefined2 *)(unaff_s0 + 0xd) = *(undefined2 *)((int)unaff_s0 + 0x2a);
      *(undefined2 *)((int)unaff_s0 + 0x36) = *(undefined2 *)((int)unaff_s0 + 0x2e);
      cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
      cVar2 = '1';
    }
  }
  if (cVar3 == cVar2) {
    *(byte *)((int)unaff_s0 + 0x26f) = *(byte *)((int)unaff_s0 + 0x26f) & 0x7f;
    *unaff_s0 = *unaff_s0 & 0xfffffffb;
  }
  cVar3 = FUN_80089d54();
  *(char *)((int)unaff_s0 + 7) = *(char *)((int)unaff_s0 + 7) + cVar3;
  default();
  return;
}
