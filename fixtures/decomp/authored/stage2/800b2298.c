typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












undefined4 FUN_800b2298(undefined2 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a83b4(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return uVar1;
}
