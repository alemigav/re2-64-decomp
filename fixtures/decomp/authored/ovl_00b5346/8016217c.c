typedef unsigned int u32;
typedef unsigned int undefined4;
extern unsigned char D_800e8d00[];












void FUN_8016217c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_0x800837ac((u32)D_800e8d00,0x1f);
  if (iVar1 == 0) {
    if (*(unsigned char *)(param_1 + 6) == '\0') {
      FUN_801621f8(param_1,param_2,param_3);
    }
    else {
      FUN_80162408(param_1,param_2,param_3);
    }
  }
  return;
}
