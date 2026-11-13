typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_80166280(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3003f00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  }
  func_0x80089d54(param_1,param_2,param_3,0x40);
  return;
}
