typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_801667a8;












void FUN_80164e84(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_80164684();
    *(undefined1 *)(param_1 + 0x2cf) = 0x14;
  }
  else {
    (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}
