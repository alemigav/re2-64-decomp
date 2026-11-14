typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef int code();












undefined1 FUN_80030fd0(int *param_1)

{
  short uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[5];
  iVar2 = puVar3[1];
  if (iVar2 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x11;
      (**(code **)*param_1)(param_1);
    }
    iVar2 = puVar3[1];
  }
  puVar3[1] = iVar2 + -1;
  uVar1 = *(undefined1 *)*puVar3;
  *puVar3 = (undefined1 *)*puVar3 + 1;
  return uVar1;
}
