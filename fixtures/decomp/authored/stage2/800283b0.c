typedef unsigned int undefined4;
typedef void code();












void FUN_800283b0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    (**(code **)(*(int *)(param_1 + 4) + 0x28))();
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}
