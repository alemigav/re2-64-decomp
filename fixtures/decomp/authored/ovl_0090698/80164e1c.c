typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80164e1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    FUN_80167688(param_1,0x2004,(uVar1 & 1) + 1);
  }
  FUN_80164aac(param_1,param_2,param_3);
  return;
}
