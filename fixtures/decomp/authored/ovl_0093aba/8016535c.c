typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_8016554c;












void FUN_8016535c(int param_1)

{
  (**(code **)(&DAT_8016554c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
