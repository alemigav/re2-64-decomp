/* FUN_800b2638
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2638  body 0x800b2638..0x800b2693  size 95 B
 * body sha256 b9f3a60be35bf13ec5af99df58b0cff770d113c0a9af0b0e3c25f276b6591cb1
 * provider record sha256 0ee360a8455681d04f35dcefb6c93a1e2a1e1786d74e2416af267eef38528e22
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800b2638(uint param_1,short param_2)

{
  short sVar1;
  short *psVar2;
  
  FUN_800a5678();
  psVar2 = (short *)((param_1 & 0xf) * 2 + -0x7feb8050);
  sVar1 = *psVar2;
  *psVar2 = param_2;
  FUN_800a56c0();
  return (int)sVar1;
}
