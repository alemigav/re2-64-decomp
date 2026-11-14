typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
int FUN_80082388(char *param_1)
{
  char cVar1;
  int iVar2;

  if (param_1 == (char *)0x0) {
    return 0;
  }
  iVar2 = 0;
  while (cVar1 = *param_1, param_1 = param_1 + 1, cVar1 != '\0') {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}
