typedef unsigned int uint;
extern unsigned int DAT_80171d50;












void FUN_801714e0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = &DAT_80171d50;
  do {
    uVar2 = uVar2 + 1;
    if (param_1 == *piVar1) {
      FUN_80171484(piVar1[1]);
    }
    piVar1 = piVar1 + 2;
  } while (uVar2 < 3);
  return;
}
