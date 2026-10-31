/* FUN_8003d454
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d454  body 0x8003d454..0x8003d48b  size 59 B
 * sha256  b6fd58e1c3b0cebb43f865b2b25a87c846dd66ac341d71d1a1de5334eac4ff2b
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
