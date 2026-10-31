/* FUN_8005d8f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d8f0  body 0x8005d8f0..0x8005d913  size 39 B
 * body sha256 c3d1075062bb665c77c52201a06c07a9394665a8c89a28fa90c6beef844f73bc
 * provider record sha256 2a9143b6056dac0a3dcb753e95187b86d3b2515765d9b8fcd13430be7b5b9ce9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d8f0(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
