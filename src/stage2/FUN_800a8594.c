/* FUN_800a8594
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8594  body 0x800a8594..0x800a860b  size 123 B
 * sha256  c4e9aed5464a6d30f5fdf1ff1246325f57c1c2b551d786ff3c3922ecb9c81bdc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined2 FUN_800a8594(void)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar1 = FUN_800af0d4();
  if (uVar1 == 0xffffffff) {
    uVar3 = 0;
  }
  else {
    iVar2 = (uVar1 & 0xff) * 0x1a0;
    uVar3 = 0;
    if ((*(uint *)(&DAT_801444a8 + iVar2) == uVar1) &&
       (uVar3 = 0, (*(uint *)(&DAT_8014446c + iVar2) & 2) == 0)) {
      uVar3 = *(undefined2 *)(iVar2 + -0x7febbaf6);
    }
  }
  return uVar3;
}
