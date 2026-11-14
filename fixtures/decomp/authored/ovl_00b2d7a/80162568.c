typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_80162b1c;












void FUN_80162568(int param_1)

{
  (**(code **)(&DAT_80162b1c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
