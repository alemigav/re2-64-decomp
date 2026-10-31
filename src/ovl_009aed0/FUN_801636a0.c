/* FUN_801636a0
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801636a0  body 0x801636a0..0x801636cb  size 47 B
 * sha256  b02aadb08087c2f25de6813aee39eaaf1bc2c4128ddd3d39adb61d7c799f829f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801636a0(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x50a0000;
    func_0x80089d54();
  }
  return;
}
