/* FUN_8003d454
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d454  body 0x8003d454..0x8003d48b  size 56 B
 * body sha256 5efbf667371aac3993d061d10640349eb53e1f3efaf5090d39739341ad18c5e7
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003d454.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
extern unsigned int DAT_800ebb94;












void FUN_8003d454(void)

{
  FUN_8003ad94();
  *(undefined1 *)(DAT_800ebb94 + 1) = 0x38;
  *(undefined2 *)(DAT_800ebb94 + 0x46) = *(undefined2 *)(DAT_800ebb94 + 0x12);
  return;
}
