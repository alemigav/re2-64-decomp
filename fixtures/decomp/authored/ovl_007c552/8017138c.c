typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_8017138c(undefined4 *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined2 *)*param_1;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x140);
  *param_1 = puVar1;
  return;
}
