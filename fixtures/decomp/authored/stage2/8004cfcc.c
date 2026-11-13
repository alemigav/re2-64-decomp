typedef unsigned int undefined4;
extern unsigned int DAT_8010b6c0;












undefined4 FUN_8004cfcc(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &DAT_8010b6c0;
  do {
    uVar1 = FUN_8008b048(4);
    uVar1 = FUN_8004cf30(uVar1);
    *puVar2 = uVar1;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 4);
  return param_1;
}
