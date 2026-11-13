/* FUN_8003a128
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a128  body 0x8003a128..0x8003a153  size 44 B
 * body sha256 a62523825d6fe3fd840738496e80d40c6d6aa6c521647f603037135bb1bfbdd7
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003a128.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_800ebb94;












void FUN_8003a128(void)

{
  *(short *)(DAT_800ebb94 + 4) = *(short *)(DAT_800ebb94 + 4) + 0x100;
  FUN_8003b14c();
  return;
}
