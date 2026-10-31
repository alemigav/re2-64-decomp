/* FUN_8017f7a0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f7a0  body 0x8017f7a0..0x8017f7db  size 63 B
 * sha256  b3c7edb4ae40deb6575415cd5abc61dbe2c4f2e85648541d8e83109a3bc85a5a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8017f7a0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_8017bec8(1);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_8017bec8(1);
    uVar2 = 1;
    if (iVar1 != 0) {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}
