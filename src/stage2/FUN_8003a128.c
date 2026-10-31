/* FUN_8003a128
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a128  body 0x8003a128..0x8003a153  size 47 B
 * body sha256 933a751536c9087aa73d59ddb97047869abd2e2e15bf34319796a47be3740057
 * provider record sha256 a9698d3588fc3c6d74633ef513c71a98195c0f06e45396ca83a20e91053f33d8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a128(void)

{
  *(short *)(DAT_800ebb94 + 4) = *(short *)(DAT_800ebb94 + 4) + 0x100;
  FUN_8003b14c();
  return;
}
