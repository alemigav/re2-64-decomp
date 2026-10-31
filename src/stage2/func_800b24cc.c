/* func_800b24cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b24cc  body 0x800b24cc..0x800b2527  size 95 B
 * body sha256 93fbe9d0bb085f420b47a46f4432e6e98663665347f873cd80f836d25cc68d0f
 * provider record sha256 1f1ec997672df8080a416213d547e70f40ca3f73456be308c3002cd8a07b67ab
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b24cc(undefined4 param_1,undefined2 param_2)

{
  int in_v0;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (in_v0 != 0) {
    FUN_800a5678();
    uVar1 = FUN_800a7854(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
