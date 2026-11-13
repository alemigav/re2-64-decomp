/* FUN_80040524
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040524  body 0x80040524..0x80040583  size 96 B
 * body sha256 b4579a0eb21c8612bc3b7ea55b5ad2112da638265089e42b08f9326c6f8887b8
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80040524.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
extern unsigned int DAT_800e9028;
extern unsigned int DAT_800ebb94;












void FUN_80040524(void)

{
  if ((*(ushort *)(DAT_800ebb94 + 0x12) & 3) == 0) {
    FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x1c020000,(int)*(short *)(DAT_800ebb94 + 0x22),
                 &DAT_800e9028,DAT_800ebb94 + 0x2c);
  }
  *(short *)(DAT_800ebb94 + 0x12) = *(short *)(DAT_800ebb94 + 0x12) + 1;
  return;
}
