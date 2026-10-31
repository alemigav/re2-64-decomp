/* FUN_800351e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800351e8  body 0x800351e8..0x800352c3  size 223 B
 * body sha256 4a1f1d24730ebec663392d7009eea362b878b6e5f68a3437c48c6d88b28fea8f
 * provider record sha256 965e80103f02931a6881ea0bc0046865483d71287c17e122038a245645ae7b7d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800351e8(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = param_1[0x8d];
  if ((*param_1 & 0x40000) == 0) {
    FUN_80040e58(param_1 + 0x19,param_1 + 5);
  }
  FUN_800424ec(param_1 + 5,uVar2 + 8,uVar2 + 0x38);
  uVar1 = *(ushort *)((int)param_1 + 0x66);
  *(ushort *)(uVar2 + 0x5c) = *(ushort *)(uVar2 + 0x5c) & 0xfff;
  FUN_800352c4(uVar2 + 0x1608,uVar2 + 0x38,400,100,0x30,4,0,0x32,0,0x30,6,0,
               (int)(((uint)uVar1 + (uint)*(ushort *)(uVar2 + 0x5a)) * 0x10000) >> 0x10);
  return;
}
