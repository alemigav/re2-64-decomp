/* FUN_8007aaa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007aaa8  body 0x8007aaa8..0x8007ab23  size 127 B
 * sha256  005b3c7f6f7117c78c4fb9ce0f7d98b3739046005f58541959888695c8e4b8cb
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
