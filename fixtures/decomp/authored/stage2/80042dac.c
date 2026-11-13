typedef unsigned int undefined4;
extern unsigned int DAT_80139a64;












void FUN_80042dac(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)&DAT_80139a64;
  iVar2 = 2;
  puVar3 = (undefined4 *)(param_1 + 0x14);
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  } while (iVar2 != -1);
  return;
}
