/* FUN_800b467c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b467c  body 0x800b467c..0x800b47b7  size 319 B
 * sha256  6dcadc80b08d3e3fb77d79c4be3f6d7e13ce16eede87f9986d6361646cff8b4e
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b467c(undefined4 param_1,undefined4 param_2,int param_3)

{
  FUN_800a5678();
  if (_DAT_80143fd4 == (code *)0x0) {
    osCreateMesgQueue(0x8015b010,0x8015b028,1);
    DAT_8015afc0 = 0;
    _DAT_80143fd4 = FUN_800b4540;
  }
  if (DAT_8015afc0 < 4) {
    *(undefined4 *)((uint)DAT_8015afc0 * 0xc + -0x7fea5030) = param_1;
    *(undefined4 *)((uint)DAT_8015afc0 * 0xc + -0x7fea502c) = param_2;
    *(uint *)((uint)DAT_8015afc0 * 0xc + -0x7fea5028) = param_3 + 0xfU & 0xfffffff0;
    DAT_8015afc0 = DAT_8015afc0 + 1;
    func_0x80007320(param_1,param_3);
    FUN_800a56c0();
    osRecvMesg(0x8015b010,0,1);
    func_0x80011390();
  }
  else {
    FUN_800a56c0();
  }
  return;
}
