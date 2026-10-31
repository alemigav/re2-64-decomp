/* FUN_8003b238
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b238  body 0x8003b238..0x8003b2a3  size 111 B
 * sha256  dfb144dae0b0ebc9e6ba9283d5a9d7755825e7ffd9b4a74f2e85b206eebbca4c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b238(void)

{
  FUN_80038a20(((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x96) / 100 | 0x30b0000,0,&DAT_800e9028,
               DAT_800ebb94 + 0x34);
  return;
}
