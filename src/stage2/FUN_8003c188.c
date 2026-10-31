/* FUN_8003c188
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c188  body 0x8003c188..0x8003c1d7  size 83 B
 * body sha256 bc6523b55a7388308fb67d4406b95da15bd276cf6d5f3cdef0a7349a47476234
 * provider record sha256 b67a066e227bb0f0ddca9d820e738639d126cfd20379a4b79a6a2f4bd041c5e8
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
