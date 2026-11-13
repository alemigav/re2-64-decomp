typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;












void FUN_801669a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  *(undefined2 *)(param_1 + 0x272) = 1;
  return;
}
