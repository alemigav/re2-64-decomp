/* FUN_8000be30
 * image   boot (boot), base 0x80000480
 * address 0x8000be30  body 0x8000be30..0x8000be4f  size 35 B
 * sha256  5878c317626318deda1de2c0f75ea1ed031ac3d1b16079fc43c1085887ce3fd2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000be30(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (_DAT_800128f0 != 0) {
    uVar1 = _DAT_800128f8;
  }
  return uVar1;
}
