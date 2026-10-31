/* FUN_800b4818
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4818  body 0x800b4818..0x800b4927  size 275 B
 * sha256  5519e514524c78caba4834081875c44e86d0a2e11ae86e9f880f0ff7c910fa62
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b4818(undefined4 param_1,undefined4 param_2,int param_3)

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
  }
  FUN_800a56c0();
  return;
}
