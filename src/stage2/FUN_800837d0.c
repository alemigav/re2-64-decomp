/* FUN_800837d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800837d0  body 0x800837d0..0x8008383b  size 111 B
 * sha256  13a2774e86d571af8609a643f75aa3788ed0be604b7ad420dd8d8130fde0d732
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800837d0(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_38 [2];
  undefined2 local_36;
  undefined1 auStack_30 [32];
  
  FUN_80082200(auStack_38,0,8);
  local_36 = param_1;
  FUN_80040e58(auStack_38,auStack_30);
  FUN_8004276c(auStack_30,param_2,param_3);
  return;
}
