typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_801654e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(unsigned char *)(param_1 + 6) == '\0') && (*(unsigned char *)(param_1 + 0x2db) == '\0')) {
    *(undefined1 *)(param_1 + 0x2db) = 0x3c;
    FUN_80165310(param_1,2,6);
  }
  FUN_80164e88(param_1,param_2,param_3);
  return;
}
