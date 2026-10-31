/* FUN_8007ab24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ab24  body 0x8007ab24..0x8007ac13  size 243 B
 * sha256  c9c217296d474edce923e89b8eff3fb2b7979a871678c5f028f28c608db3c1cc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ab24(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x178,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x2f0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x758,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xeb0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x1318,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
  }
  return;
}
