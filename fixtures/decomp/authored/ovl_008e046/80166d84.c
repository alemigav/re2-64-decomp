typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_8016752c;












void FUN_80166d84(int param_1)

{
  (**(code **)(&DAT_8016752c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
