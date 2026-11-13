typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80166038(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_8016703c(param_1,0x13,1);
    FUN_80166248(param_1);
    uVar1 = func_0x80033604();
    FUN_80167688(param_1,0x2004,(uVar1 & 3) + 6);
  }
  FUN_801658fc(param_1,param_2,param_3);
  return;
}
