typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_801682d8;












void FUN_80167ae4(int param_1)

{
  (**(code **)(&DAT_801682d8 + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
