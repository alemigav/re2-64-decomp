/* FUN_8017b98c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b98c  body 0x8017b98c..0x8017b9bb  size 51 B
 * sha256  61553e7bd6717cc221a22593d5ff6c423e199b140660b329396b3ad944f6d474
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017b98c(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_8017b8f4();
  uVar2 = FUN_8017b8f4();
  return iVar1 << 8 | uVar2;
}
