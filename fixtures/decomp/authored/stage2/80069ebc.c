typedef unsigned int undefined4;
typedef unsigned short ushort;
typedef unsigned int uint;












int FUN_80069ebc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(*(ushort *)(param_4 + 6) >> 1);
  iVar1 = ((int)*(short *)(param_4 + 2) + uVar2) - *(int *)(param_1 + 8);
  iVar1 = FUN_80040bb4(uVar2 * uVar2 - iVar1 * iVar1);
  return (param_2 - uVar2) + iVar1;
}
