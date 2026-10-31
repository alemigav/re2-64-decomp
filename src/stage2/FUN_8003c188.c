/* FUN_8003c188
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c188  body 0x8003c188..0x8003c1d7  size 83 B
 * sha256  e35d20e247512825494ee0ecf049a026eb3ae701cd6280e2b4fe8c90866a364d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c188(void)

{
  *DAT_800ebb94 = 0x54;
  DAT_800ebb94[1] = 0;
  FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x14000000,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
  return;
}
