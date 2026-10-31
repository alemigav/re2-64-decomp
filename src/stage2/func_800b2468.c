/* func_800b2468
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2468  body 0x800b2468..0x800b24c3  size 95 B
 * body sha256 c6832207f6d608521cf78f12070939c633200dc5580ccfaaf5acac2dc38e07c5
 * provider record sha256 02fb5cdae36b3928161b31bd2d7fbfb7287445928bb2e430a11faf0e24b78241
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b2468(undefined4 param_1,undefined2 param_2)

{
  int in_v0;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (in_v0 != 0) {
    FUN_800a5678();
    uVar1 = FUN_800a7970(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
