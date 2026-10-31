/* func_800b2404
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2404  body 0x800b2404..0x800b245f  size 95 B
 * body sha256 b2dd6f61b0bdd453909da3ac52b33e2d6eb134b2c4230a5879b53fb27abc15b4
 * provider record sha256 59956d2ab17cb3a1919da653acc340c3f27b62c4dc17cd634fb5d0ae2d83e826
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b2404(undefined4 param_1,undefined1 param_2)

{
  int in_v0;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (in_v0 != 0) {
    FUN_800a5678();
    uVar1 = FUN_800a777c(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
