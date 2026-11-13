typedef unsigned char undefined1;












void FUN_8002fc00(int param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = param_3 + -1;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined1 *)(param_1 + iVar2);
      iVar2 = iVar2 + -1;
      *puVar1 = param_2;
    } while (iVar2 != -1);
  }
  return;
}
