/* FUN_8004789c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004789c  body 0x8004789c..0x800478ab  size 19 B
 * sha256  9b9a52b487e2e4ebdfcfa2477eb8fec422ddb148a567a16f564d0ce713e92971
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004789c(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  *(undefined1 *)(param_1 + 4) = param_2;
  *(undefined1 *)(param_1 + 5) = param_3;
  *(undefined1 *)(param_1 + 6) = param_4;
  return;
}
