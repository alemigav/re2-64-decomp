/* FUN_8000cb10
 * image   boot (boot), base 0x80000480
 * address 0x8000cb10  body 0x8000cb10..0x8000cb57  size 75 B
 * sha256  f63763525465add0e60f6b74acce43da697b7ea3257b1e41cb274a2ca0279cdf
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000cb10(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  _DAT_800128d0 = _DAT_800128d0 & (~param_1 | 0x401);
  FUN_80007300(uVar1);
  return;
}
