typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_801651c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x160f0300;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar1 != 0) {
    FUN_80165a5c(param_1,1);
    *(undefined1 *)(param_1 + 0x2bf) = 0;
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
