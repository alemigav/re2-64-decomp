/* FUN_800a8470
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8470  body 0x800a8470..0x800a84e7  size 123 B
 * body sha256 f72676d5389f0fb0ec29a6b00c89b358fa4a7e9e2e07d78c01f06261d2e216ec
 * provider record sha256 1d28ea9b51606837013232fd7b12a5aa020ce24cce62d45a932fd9e7e97e7313
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a8470(void)

{
  if (_DAT_80147fa0 != 0) {
    if (_DAT_80147fa4 == 0) {
      trap(0x1c00);
    }
    if ((_DAT_80147fa4 == -1) && (_DAT_80147fa0 * 32000 == -0x80000000)) {
      trap(0x1800);
    }
    _DAT_80147848 = (_DAT_80147fa0 * 32000) / _DAT_80147fa4 << 3;
    FUN_800a6c04();
  }
  return;
}
