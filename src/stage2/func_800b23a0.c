/* func_800b23a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b23a0  body 0x800b23a0..0x800b23fb  size 95 B
 * body sha256 6db5d3cfac58ed774e751b1d2a88d84f6942df2cb9df73d22e5c55e587f9b04a
 * provider record sha256 95bb029767422de6dd31883d21c8ca3196ce9663e58cb34dfc993f49295db18f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b23a0(undefined4 param_1,undefined1 param_2)

{
  int in_v0;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (in_v0 != 0) {
    FUN_800a5678();
    uVar1 = FUN_800a76a4(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
