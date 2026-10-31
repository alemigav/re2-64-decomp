/* FUN_800478b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478b8  body 0x800478b8..0x800478c3  size 15 B
 * body sha256 467792955f882a109123db96dd0cab173ce70f85789383063b28490dee64df38
 * provider record sha256 9d0ae1458734d2f7f33000dc534aeeefb51b40d44ae1d18c13e64613e1c84919
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800478b8(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  return;
}
