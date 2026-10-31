/* FUN_80071670
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071670  body 0x80071670..0x800716af  size 67 B
 * sha256  c57165414ce1952f41cdf7a694494e2145bbca164671773827c55babeb5a80a9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071670(int param_1)

{
  FUN_80038f40(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
