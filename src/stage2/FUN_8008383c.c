/* FUN_8008383c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008383c  body 0x8008383c..0x800838bf  size 135 B
 * sha256  897d622b79c2b9bdf4a6d434a3011c6fc05ccca6c184d5192972a9dbccfe349f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008383c(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_40 [2];
  undefined2 local_3e;
  undefined1 auStack_38 [32];
  
  FUN_80082200(auStack_40,0,8);
  local_3e = param_1;
  FUN_80040e58(auStack_40,auStack_38);
  FUN_80040cf4(param_2,auStack_38);
  FUN_8004276c(auStack_38,param_3,param_4);
  return;
}
