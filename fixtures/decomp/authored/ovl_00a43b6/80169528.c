typedef unsigned int undefined4;












void FUN_80169528(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x180,param_2);
  func_0x800424ec(param_2,iVar1 + 0x2f8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x5e8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x760,param_2);
  func_0x800424ec(param_2,iVar1 + 0x8d8,param_2);
  return;
}
