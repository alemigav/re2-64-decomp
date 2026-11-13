typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80165858(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = func_0x80033604();
  *(undefined4 *)((uVar1 & 0xf) * 0x178 + *(int *)(param_1 + 0x234) + 0x60) = 0x3f2f;
  *(undefined1 *)(param_1 + 699) = 1;
  FUN_80166980(param_1,uVar1 & 0xf,9);
  *(undefined1 *)(param_1 + 5) = 1;
  FUN_80164d5c(param_1,param_2,param_3);
  return;
}
