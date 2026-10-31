/* FUN_8003a154
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a154  body 0x8003a154..0x8003a21b  size 203 B
 * body sha256 8994efbd437e3684679459189bdbdca7aea877d53b86fd63042a70d56e5a9f93
 * provider record sha256 702e10f57d60d4b8564c6777eeeb9bd7c3cde5c1baddf4e44c395b0e872c7cda
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a154(void)

{
  int iVar1;
  int iVar2;
  ushort uVar4;
  uint uVar3;
  
  iVar1 = DAT_800ebb94;
  *(undefined1 *)(DAT_800ebb94 + 0x21) = *(undefined1 *)(DAT_800ebb94 + 0x13);
  iVar2 = DAT_800ebb94;
  *(undefined2 *)(iVar1 + 0x18) = 0x8003;
  *(undefined1 *)(iVar2 + 0x20) =
       *(undefined1 *)(*(int *)(iVar2 + 0x70) + (uint)*(byte *)(iVar2 + 0x21) * 8 + 2);
  if (*(char *)(DAT_800ebb94 + 0x1e) != '\x06') {
    uVar4 = FUN_80033604();
    *(ushort *)(DAT_800ebb94 + 0x10) = (uVar4 & 3) * 5;
    uVar3 = FUN_80033604();
    *(short *)(DAT_800ebb94 + 0xe) =
         *(short *)(DAT_800ebb94 + 0xe) + (short)((uVar3 & 0xff) % 3) * -10;
  }
  return;
}
