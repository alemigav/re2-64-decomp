typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_801672c8;












void FUN_801664dc(int param_1)

{
  (**(code **)(&DAT_801672c8 + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
