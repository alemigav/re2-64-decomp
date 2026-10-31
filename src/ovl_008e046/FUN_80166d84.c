/* FUN_80166d84
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166d84  body 0x80166d84..0x80166db7  size 55 B
 * sha256  2dbd26c445ae1dca6a833785fca663d98c47a9a8c0799919769b2c5c107f1a0e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166d84(int param_1)

{
  (**(code **)(&DAT_8016752c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
