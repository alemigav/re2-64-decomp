/* FUN_800b4478
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4478  body 0x800b4478..0x800b44f3  size 127 B
 * body sha256 541574e8c0165b1b5214e56d9712e12d7a8f2167c46d0f90f0219878cb0ffd68
 * provider record sha256 f40949814a96e9a1c7602da5d4c9f077ac49e5f0c830b444591f329f15f0043f
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
