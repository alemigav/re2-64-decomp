/* FUN_8007aa2c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007aa2c  body 0x8007aa2c..0x8007aaa7  size 127 B
 * sha256  6fe1b1dbec169d2ff8efe201ab4e86531e5feea76630eb5b1c2c64eb4d3058fd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007aa2c(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
  }
  return;
}
