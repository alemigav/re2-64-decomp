/* FUN_800b2638
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2638  body 0x800b2638..0x800b2693  size 95 B
 * sha256  8ffb99762ff5bdd8ba2f9b3de123c393fd637c6d3eec2251cb305e628f131e11
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
