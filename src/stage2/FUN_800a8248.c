/* FUN_800a8248
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8248  body 0x800a8248..0x800a82d7  size 147 B
 * sha256  0d1d96788984133a7da30eeba81421ee60996cb86516dc3aaf1618cf9006472f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a8248(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    uVar1 = FUN_800af0d4();
    while (uVar1 != 0xffffffff) {
      iVar2 = (uVar1 & 0xff) * 0x1a0;
      if (*(uint *)(&DAT_801444a8 + iVar2) == uVar1) {
        uVar3 = 0;
        *(uint *)(&DAT_8014446c + iVar2) = *(uint *)(&DAT_8014446c + iVar2) | 8;
      }
      uVar1 = *(uint *)(iVar2 + -0x7febbba8);
    }
  }
  return uVar3;
}
