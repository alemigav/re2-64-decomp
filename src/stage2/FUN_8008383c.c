/* FUN_8008383c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008383c  body 0x8008383c..0x800838bf  size 135 B
 * body sha256 42361ee656e537e1b0963595664882b56b2fd8921c913e2a8b5fad94c75c5c83
 * provider record sha256 b3e7f3b7885c9c2310f9438c0180f55008966da1f95df4e47e06daa0735c5fb9
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
