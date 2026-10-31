/* FUN_800878fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800878fc  body 0x800878fc..0x8008794b  size 83 B
 * body sha256 26e2c7ae887a09c7c3cc8822249c29051e1d12c72d183aa18e0d6f82f0b3ff49
 * provider record sha256 160616cbf0d96e907654374b6c734b12aafdda049caca3beebd8dca84988b5dd
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
