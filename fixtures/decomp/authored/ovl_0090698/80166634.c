typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_80166634(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 0x2c0) == '\0') {
    FUN_801679c8(param_1,0x3f3f3f);
    *(undefined1 *)(param_1 + 0x2d7) = 0x1e;
    FUN_8016703c(param_1,0x13,10);
    FUN_8016703c(param_1,0,10);
  }
  *(undefined1 *)(param_1 + 5) = 2;
  FUN_8016577c(param_1,param_2,param_3);
  return;
}
