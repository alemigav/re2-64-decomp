/* FUN_8003b1b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b1b8  body 0x8003b1b8..0x8003b237  size 128 B
 * body sha256 52927b0f1dcce74f1aa5a693a2b8b45abf650780ec22d3d7978ca2e2cd7f29de
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003b1b8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned short ushort;
extern unsigned int DAT_800e9028;
extern unsigned int DAT_800ebb94;












void FUN_8003b1b8(void)

{
  if (*(byte *)(DAT_800ebb94 + 2) != 0) {
    if (((*(byte *)(DAT_800ebb94 + 2) & 1) == 0) &&
       ((int)*(short *)(DAT_800ebb94 + 0x34) + (int)*(short *)(DAT_800ebb94 + 0x36) +
        (int)*(short *)(DAT_800ebb94 + 0x38) != 0)) {
      FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) + 0xb00 | 0x3090000,0,&DAT_800e9028,
                   DAT_800ebb94 + 0x34);
    }
    *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + -1;
  }
  return;
}
