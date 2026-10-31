/* FUN_80073018
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073018  body 0x80073018..0x80073057  size 67 B
 * sha256  9b99420e02db0eff3c26f2554f1c09e573c8e86a9292d6113c959c704b06b5b4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073018(int param_1)

{
  FUN_8009f320(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
