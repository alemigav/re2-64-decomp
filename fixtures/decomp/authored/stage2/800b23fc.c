typedef unsigned char undefined1;
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












undefined4 func_800b23fc(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a777c(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
