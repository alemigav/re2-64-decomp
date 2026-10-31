/* FUN_8007898c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007898c  body 0x8007898c..0x80078ab7  size 303 B
 * sha256  b61ffc5767f33c57be6f0ec27870c230fe1c28b19cc8bf7a189c3664951e4e4e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007898c(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = DAT_800c52dc + 0x300fU & 0xfffffff0;
  bVar1 = *(byte *)(DAT_800dfb58 + 0xc);
  if (-1 < DAT_80119ea8) {
    FUN_80075608(0,1);
    DAT_80119ea8 = -1;
    DAT_80119ecc = uVar3;
  }
  iVar2 = (uint)bVar1 * 2;
  do {
    func_0x80004cfc(*(undefined2 *)(&DAT_80116000 + iVar2),uVar3,1,"DOOR EDH");
    DAT_80119ea8 = FUN_800752dc(*(undefined2 *)(&DAT_8011614c + iVar2),0,1);
    DAT_8011a294 = &UNK_80116070 + (uint)bVar1 * 4;
  } while (DAT_80119ea8 == -1);
  DAT_8011a378 = 1;
  return;
}
