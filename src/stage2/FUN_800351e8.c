/* FUN_800351e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800351e8  body 0x800351e8..0x800352c3  size 223 B
 * sha256  248877441b1d104b956c4d7bd78a362c76b860516ef5a264bb8fc5f82640a1ca
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
