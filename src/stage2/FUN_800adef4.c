/* FUN_800adef4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800adef4  body 0x800adef4..0x800adf53  size 99 B
 * sha256  881d033a0f9b7d185ec3b68afe89cea13202371b688c864196f31aef33b66ddb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800adef4(undefined2 param_1)

{
  undefined4 uVar1;
  
  _DAT_8014e12c = param_1;
  _DAT_8014e130 = (undefined4 *)FUN_800ab43c(0x8014e128,0x8014e1e0,_DAT_8014e1d0,8,&LAB_800ae164);
  if (_DAT_8014e130 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *_DAT_8014e130;
  }
  return uVar1;
}
