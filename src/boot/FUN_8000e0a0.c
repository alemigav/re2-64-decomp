/* FUN_8000e0a0
 * image   boot (boot), base 0x80000480
 * address 0x8000e0a0  body 0x8000e0a0..0x8000e0ff  size 99 B
 * body sha256 ba587de4a07e8e3fb0436e2c33c5c6b4261955b13329731f5994b9232e40ba00
 * provider record sha256 37254c9bf0706d630f9d9ea97b07b857ca78a303e64de8ed03ed13234e0167fd
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000e0a0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  _DAT_80017830 = FUN_80007000();
  FUN_8000de30(param_2 + _DAT_80017830);
  FUN_80007300(uVar1);
  return;
}
