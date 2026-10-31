/* FUN_80161fe8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80161fe8  body 0x80161fe8..0x80162017  size 51 B
 * sha256  160ee5c51df6440102b6aaa8650c253d705a629901d01ef978b0278c689e8390
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161fe8(int param_1)

{
  if ((**(uint **)(param_1 + 0x234) & 1) != 0) {
    FUN_8016664c();
  }
  return;
}
