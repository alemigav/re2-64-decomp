/* FUN_8008794c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008794c  body 0x8008794c..0x8008799b  size 83 B
 * sha256  4bf5b43fcfec9ea6f97f6caffc10207c854cae7bc949b80ee2bbb6186d2d7a7b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008794c(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0xd6)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0xb8) + param_3 * *(short *)(param_1 + 0xd4) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0xbc) + param_3 * *(short *)(param_1 + 0xd4) * 4;
  }
  return;
}
