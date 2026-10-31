/* FUN_8003b1b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b1b8  body 0x8003b1b8..0x8003b237  size 131 B
 * sha256  7590db83815015269f27d5b16ab39a2b4fbc8c65b4e0ccdb811a7d9a1e1ecd4c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
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
