/* FUN_800a5bc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5bc0  body 0x800a5bc0..0x800a5c07  size 75 B
 * sha256  b9b62a75c92841cec1ce3c88866beff4db15bf72313a1df3aa049b717384423e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5bc0(void)

{
  if (_DAT_80143f68 != 0) {
    FUN_800a5750();
    (*_DAT_8014400c)(_DAT_80143f68);
    _DAT_80143f68 = 0;
  }
  return;
}
