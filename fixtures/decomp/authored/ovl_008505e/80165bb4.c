typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;












void FUN_80165bb4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)(param_1 + 700) == '\0') {
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 500));
    FUN_8016655c(param_1,10,0);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,(int)*(short *)(param_1 + 0x1f6));
  if (iVar1 != 0) {
    if (*(unsigned char *)(param_1 + 7) == '\0') {
      *(undefined1 *)(param_1 + 7) = 1;
      *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x1ea) * 0x100 + 0x12000000;
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0x7000000;
    }
  }
  return;
}
