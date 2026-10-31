/* FUN_8007acc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007acc0  body 0x8007acc0..0x8007ad13  size 87 B
 * sha256  dac9915ad94ea924f5ade2090c0786cdd8ce35bf56c548ad69f1f39ee20697b0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007acc0(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
  }
  return;
}
