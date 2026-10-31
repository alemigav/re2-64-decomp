/* FUN_8000e0a0
 * image   boot (boot), base 0x80000480
 * address 0x8000e0a0  body 0x8000e0a0..0x8000e0ff  size 99 B
 * sha256  5a6c75fe4c0a29c5043aca46a4165cfdb1b48e918c10110f3cc9d54dff9e7d0f
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
