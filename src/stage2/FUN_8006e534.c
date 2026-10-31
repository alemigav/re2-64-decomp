/* FUN_8006e534
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e534  body 0x8006e534..0x8006e573  size 67 B
 * sha256  1c2f991e954654540f56c005b7e9bf5f97436465c15a7a8d4c49e3b5ac20706a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006e534(int param_1)

{
  FUN_80065034();
  DAT_80114f3b = 1;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}
