typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












undefined4 FUN_800b2344(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a8248(param_1);
    FUN_800a56c0();
  }
  return uVar1;
}
