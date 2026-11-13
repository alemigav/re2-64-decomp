typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_801679c8(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = 0;
  do {
    uVar2 = uVar2 + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar1 + 0x60) = param_2;
    iVar1 = iVar1 + 0x178;
  } while (uVar2 < 0x14);
  return;
}
