/* FUN_800878fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800878fc  body 0x800878fc..0x8008794b  size 83 B
 * body sha256 26e2c7ae887a09c7c3cc8822249c29051e1d12c72d183aa18e0d6f82f0b3ff49
 * provider record sha256 60a98d0dd72db2c4f80c6f559cd276faf65ca310ae29839fb6b2a37b78e01be9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800878fc(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0x5e)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0x40) + param_3 * *(short *)(param_1 + 0x5c) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0x44) + param_3 * *(short *)(param_1 + 0x5c) * 4;
  }
  return;
}
