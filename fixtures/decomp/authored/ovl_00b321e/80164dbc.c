typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned int PTR_FUN_801667a8;












void FUN_80164dbc(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,8,uVar1 & 3);
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,8,uVar1 & 3 | 4);
    FUN_80164684(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}
