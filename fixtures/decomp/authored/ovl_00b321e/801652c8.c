typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_801652c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000f00;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x7000000;
  }
  return;
}
