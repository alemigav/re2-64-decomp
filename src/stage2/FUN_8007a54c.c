/* FUN_8007a54c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a54c  body 0x8007a54c..0x8007a5eb  size 163 B
 * sha256  2385661a008b73ab857e86ca8fcc74d85012035db97839ad2ac54c34ab3761d2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a54c(int param_1)

{
  **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) | 0x4000;
  *(code **)(param_1 + 0x2a0) = FUN_80035e3c;
  *(undefined1 **)(param_1 + 0x2a4) = &LAB_800805f4;
  if ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) {
    DAT_800df934 = FUN_80035e34(param_1,DAT_800df934);
  }
  *(undefined2 *)(param_1 + 0x2b8) = 0;
  *(undefined2 *)(param_1 + 0x2c0) = 0;
  *(undefined2 *)(param_1 + 700) = 0;
  *(undefined1 *)(param_1 + 0x2bf) = 0;
  *(undefined1 *)(param_1 + 0x1ed) = 0;
  *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x80;
  return;
}
