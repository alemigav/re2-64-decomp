/* FUN_8003a128
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a128  body 0x8003a128..0x8003a153  size 47 B
 * body sha256 933a751536c9087aa73d59ddb97047869abd2e2e15bf34319796a47be3740057
 * provider record sha256 e193d44c575269ba87d5597a156d75732b1c088a58e01c14c5030cd14cd0b53f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a128(void)

{
  *(short *)(DAT_800ebb94 + 4) = *(short *)(DAT_800ebb94 + 4) + 0x100;
  FUN_8003b14c();
  return;
}
