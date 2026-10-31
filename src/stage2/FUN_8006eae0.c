/* FUN_8006eae0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eae0  body 0x8006eae0..0x8006eb07  size 43 B
 * sha256  599f563cbc8d5ce8139a3efa44d6215aa2bb43737b1c22cd88bd90ea66e8d162
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006eae0(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  FUN_8006d284();
  return 1;
}
