/* FUN_8007aaa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007aaa8  body 0x8007aaa8..0x8007ab23  size 127 B
 * body sha256 a14a0338f026c0b8e213244c66f6506d4689487574818ffa715626dd7a6f8e9d
 * provider record sha256 3342e3802143954790af8eef6bfb25167f0329d8a0b8bc69d261fc47d06716da
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007aaa8(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
  }
  return;
}
