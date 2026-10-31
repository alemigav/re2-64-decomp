/* FUN_8003a128
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a128  body 0x8003a128..0x8003a153  size 47 B
 * sha256  27aceae8907c4b9c5312d2fe289ae2f6350000860a07e8b60330c49fb9f3ab13
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a128(void)

{
  *(short *)(DAT_800ebb94 + 4) = *(short *)(DAT_800ebb94 + 4) + 0x100;
  FUN_8003b14c();
  return;
}
