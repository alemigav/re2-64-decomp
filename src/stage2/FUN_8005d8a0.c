/* FUN_8005d8a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d8a0  body 0x8005d8a0..0x8005d8c3  size 39 B
 * body sha256 2b0abd1ddab9474904933b57ebb269a068b8ed67a87b4076965e68df9cf07ae2
 * provider record sha256 957aed015823a6d1551ce19c007a2ba5065c8e0657bc29533ffd82321c1f41d3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d8a0(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
