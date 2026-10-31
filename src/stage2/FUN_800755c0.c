/* FUN_800755c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800755c0  body 0x800755c0..0x80075607  size 75 B
 * sha256  c46e66a0979fd0c3c52b05d41971156511e2ebc5cf6af918c91d73c9385d4642
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800755c0(void)

{
  while (_DAT_8013a168 != 0) {
    _DAT_8013a168 = _DAT_8013a168 + -1;
    FUN_800a8a04();
  }
  return;
}
