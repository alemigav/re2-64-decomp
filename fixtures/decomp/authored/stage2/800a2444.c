typedef unsigned int undefined4;
typedef unsigned int uint;
extern unsigned int DAT_8013bc90;












void FUN_800a2444(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined4 *)&DAT_8013bc90;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 0x3fe;
    uVar3 = uVar3 + 1;
    FUN_800a0f1c(uVar1);
  } while (uVar3 < 8);
  return;
}
