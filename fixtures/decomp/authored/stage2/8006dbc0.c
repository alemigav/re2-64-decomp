typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_8006dbc0(int param_1)

{
  short uVar1;
  short uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar3 + 1);
  uVar2 = *(undefined1 *)(iVar3 + 3);
  *(int *)(param_1 + 0x1c) = iVar3 + 4;
  FUN_8006d628(uVar1,uVar2);
  return 1;
}
