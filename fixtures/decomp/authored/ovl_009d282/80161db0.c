typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_80161db0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 5);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    if (*(short *)(param_1 + 0x270) == 0) {
      return;
    }
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
  }
  cVar2 = func_0x80089d54(param_1,param_2,param_3,0x1000);
  *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + cVar2;
  return;
}
