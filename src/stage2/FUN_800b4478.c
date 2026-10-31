/* FUN_800b4478
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4478  body 0x800b4478..0x800b44f3  size 127 B
 * sha256  a72d35b3f7dbba5abcb18609dffeca9a3cd0f5a3a2deaf89d8490380a528ac63
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b4478(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  if (DAT_80136d80 != '\0') {
    param_5 = param_5 * 0x1228;
    FUN_800b4d30(param_5 + -0x7fea74e0,param_2 + param_4);
    *(int *)(param_5 + -0x7fea62c4) = *(int *)(param_5 + -0x7fea62c4) + param_2 + param_4;
  }
  return 0;
}
