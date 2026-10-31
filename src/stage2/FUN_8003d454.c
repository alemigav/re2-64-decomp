/* FUN_8003d454
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d454  body 0x8003d454..0x8003d48b  size 59 B
 * body sha256 5e8196025576050e00aed81068aadb8e0a0dcf0e4d7263e2ef87164d929d7268
 * provider record sha256 f27f086d052d08a5ddfb254165fdb412cd192067ab7b14ed9a635c61d3223d75
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d454(void)

{
  FUN_8003ad94();
  *(undefined1 *)(DAT_800ebb94 + 1) = 0x38;
  *(undefined2 *)(DAT_800ebb94 + 0x46) = *(undefined2 *)(DAT_800ebb94 + 0x12);
  return;
}
