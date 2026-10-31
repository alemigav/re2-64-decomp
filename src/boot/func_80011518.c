/* func_80011518
 * image   boot (boot), base 0x80000480
 * address 0x80011518  body 0x80011518..0x800115a3  size 143 B
 * body sha256 be4636c3852532349fc0823055e71adac6880a60d7f97e2cfe2c74d9a7a1e359
 * provider record sha256 bacabd57e34f17088dff52437316ea3d5e32c57731eafe31c38ea2c17db66143
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_80011518(int param_1,int param_2)

{
  int in_v0;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1;
  if (in_v0 != 0) {
    iVar3 = param_1 + -0x2000;
  }
  DAT_80013890 = (param_1 + param_2 & 0x1fffU) == 0;
  iVar1 = FUN_800115b0();
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    _DAT_a4500000 = FUN_8000e800(iVar3);
    uVar2 = 0;
    _DAT_a4500004 = param_2;
  }
  return uVar2;
}
