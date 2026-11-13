typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned char byte;












void FUN_801648a8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8016313c();
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    *(undefined1 *)(param_1 + 0x2c8) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  return;
}
