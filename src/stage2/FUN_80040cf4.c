/* FUN_80040cf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040cf4  body 0x80040cf4..0x80040d2b  size 59 B
 * sha256  7cca74fa6994b162adaa64f56c5c8589926a37d2a0466128f8cc159e3086c8a9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80040cf4(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_28 [32];
  
  FUN_8004226c(param_1,param_2,auStack_28);
  FUN_800424bc(auStack_28,param_2);
  return param_2;
}
