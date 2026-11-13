typedef unsigned int undefined4;
typedef void code();












void FUN_8002fd00(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x14) = 0x2e;
  *(undefined4 *)(*param_1 + 0x18) = param_2;
  (**(code **)*param_1)();
  return;
}
