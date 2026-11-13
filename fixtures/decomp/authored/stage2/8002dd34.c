typedef unsigned int undefined4;
typedef void code();












void FUN_8002dd34(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x59];
  if ((*(int *)(iVar1 + 0x14) == 0) || (*(int *)(iVar1 + 0x14) == 2)) {
    if (param_1[0x11] != 0) {
      (**(code **)(param_1[0x62] + 8))();
    }
    *(undefined4 *)(iVar1 + 0x14) = 3;
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x28;
    (**(code **)*param_1)();
  }
  return;
}
