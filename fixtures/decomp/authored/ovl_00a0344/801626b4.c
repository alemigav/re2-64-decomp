typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_801626b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 7) * 0x10000 + 0x5000700;
    *(undefined2 *)(param_1 + 0x2c2) = 0;
    *(undefined2 *)(param_1 + 700) = *(undefined2 *)(param_1 + 0x2c0);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  FUN_8016375c(param_1,0);
  return;
}
