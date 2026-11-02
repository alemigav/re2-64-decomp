/* FUN_8007e6a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e6a8  body 0x8007e6a8..0x8007e86b  size 452 B
 * body sha256 a4966dbe48d0361cbc85df6db453c35f0a3a674c6a1fe1b2cc42b293df246777
 * provider record sha256 4b84f424464aed774d39480f927491d0050853e824f6f2b97fd0a9b0beff0933
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e5c0::caseD_3(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint *unaff_s0;
  
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
