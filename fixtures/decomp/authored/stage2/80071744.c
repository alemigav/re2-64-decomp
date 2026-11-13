typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_80071744(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  uVar1 = FUN_800717a0((int)*(char *)(iVar2 + 4),(int)*(char *)(iVar2 + 5));
  FUN_80039020(*(undefined1 *)(iVar2 + 1),*(undefined1 *)(iVar2 + 2),*(undefined1 *)(iVar2 + 3),
               uVar1);
  *(int *)(param_1 + 0x1c) = iVar2 + 6;
  return 1;
}
