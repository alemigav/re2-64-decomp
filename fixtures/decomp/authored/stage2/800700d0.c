typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern short DAT_800e8c78;












undefined4 FUN_800700d0(int param_1)

{
  int cVar1;
  int cVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  cVar1 = *(char *)(iVar3 + 1);
  cVar2 = *(char *)(iVar3 + 2);
  *(int *)(param_1 + 0x1c) = iVar3 + 3;
  uVar4 = FUN_800701d8(*(undefined4 *)(param_1 + 0x154),(int)cVar2);
  (&DAT_800e8c78)[cVar1] = uVar4;
  return 1;
}
