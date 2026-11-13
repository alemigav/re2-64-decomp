typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_80030f18(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  puVar3 = (undefined4 *)(param_1 + param_2 * 4);
  puVar5 = (undefined4 *)(param_3 + param_4 * 4);
  for (; 0 < param_5; param_5 = param_5 + -1) {
    puVar6 = (undefined1 *)*puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = (undefined1 *)*puVar5;
    puVar5 = puVar5 + 1;
    for (iVar2 = param_6; iVar2 != 0; iVar2 = iVar2 + -1) {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}
