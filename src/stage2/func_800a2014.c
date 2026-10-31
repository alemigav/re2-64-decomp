/* func_800a2014
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2014  body 0x800a2014..0x800a206f  size 95 B
 * body sha256 878131b934b77389c889f86d694c9c32a03672350a090db6cfa98ca3e771ca0a
 * provider record sha256 da3a499ecff850e56b5a358891778a28376158970d04bae742c6e45f8fef0e95
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void func_800a2014(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_v0;
  
  if (in_v0 != 0) {
    FUN_800a5678();
    FUN_800a12f8(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return;
}
